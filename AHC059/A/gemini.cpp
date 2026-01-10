#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <map>

using namespace std;

using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;
using vs = vector<string>;

// 1次元配列を表示
template <typename T>
void privec(const vector<T>& vec) {
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << (i == vec.size() - 1 ? "" : " ");
    }
    cout << endl;
}

// 2次元配列を表示
template <typename T>
void primtx(const vector<vector<T>>& mtx) {
    for (const auto& row : mtx) {
        for (int j = 0; j < row.size(); j++) {
            cout << row[j] << (j == row.size() - 1 ? "" : " ");
        }
        cout << "\n";
    }
}

// グリッド上の最短の「カードがある場所」を探すBFS
// start: {row, col}
vl GridBFS(const vvl& grid, const vl& start, int N) {
    int H = N, W = N;
    vvl distances(H, vl(W, -1));
    queue<vl> q;

    distances[start[0]][start[1]] = 0;
    q.push(start);

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    while (!q.empty()) {
        vl curr = q.front(); q.pop();
        ll r = curr[0], c = curr[1];

        // カードが見つかったらその座標を返す（スタート地点以外）
        if (grid[r][c] != -1 && !(r == start[0] && c == start[1])) {
            return {r, c};
        }
        // スタート地点に既にカードがある場合も考慮するなら、条件を調整
        if (grid[r][c] != -1 && (r == start[0] && c == start[1])) {
             // 既にその場にカードがある場合、探索せずここを返しても良い
        }

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i], nc = c + dc[i];
            if (nr >= 0 && nr < H && nc >= 0 && nc < W && distances[nr][nc] == -1) {
                distances[nr][nc] = distances[r][c] + 1;
                q.push({(ll)nr, (ll)nc});
            }
        }
    }
    return {-1, -1};
}

struct MachineState {
    ll r = 0, c = 0;
    vl stack;

    void pickup(ll row, ll col, vvl& mat) {
        ll val = mat[row][col];
        if (!stack.empty() && stack.back() == val) {
            stack.pop_back();
        } else {
            stack.push_back(val);
        }
        mat[row][col] = -1;
    }
};

// 移動コマンドの生成
vs calc_way(ll r1, ll c1, ll r2, ll c2) {
    vs res;
    // 縦移動
    while (r1 < r2) { res.push_back("D"); r1++; }
    while (r1 > r2) { res.push_back("U"); r1--; }
    // 横移動
    while (c1 < c2) { res.push_back("R"); c1++; }
    while (c1 > c2) { res.push_back("L"); c1--; }
    return res;
}

int main() {
    int N;
    if (!(cin >> N)) return 0;

    vvl mat(N, vl(N));
    map<ll, vector<vl>> card_pos_dict;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> mat[i][j];
            if (mat[i][j] != -1) {
                card_pos_dict[mat[i][j]].push_back({(ll)i, (ll)j});
            }
        }
    }

    MachineState ms;
    vs history;

    while (true) {
        // 現在地にカードがなければ、一番近いカードを探して移動
        if (mat[ms.r][ms.c] == -1) {
            vl nxt = GridBFS(mat, {ms.r, ms.c}, N);
            if (nxt[0] == -1) break; // もうカードがない

            vs moves = calc_way(ms.r, ms.c, nxt[0], nxt[1]);
            history.insert(history.end(), moves.begin(), moves.end());
            ms.r = nxt[0]; ms.c = nxt[1];
        }

        // 1枚目拾う
        ll card_val = mat[ms.r][ms.c];
        ms.pickup(ms.r, ms.c, mat);
        history.push_back("Z");

        // ペアの相方を探す
        vl partner = {-1, -1};
        auto& v = card_pos_dict[card_val];
        for (auto& p : v) {
            if (mat[p[0]][p[1]] == card_val) {
                partner = p;
                break;
            }
        }

        if (partner[0] != -1) {
            // 相方の場所へ移動
            vs moves = calc_way(ms.r, ms.c, partner[0], partner[1]);
            history.insert(history.end(), moves.begin(), moves.end());
            ms.r = partner[0]; ms.c = partner[1];

            // 2枚目拾う（これでスタックから消える）
            ms.pickup(ms.r, ms.c, mat);
            history.push_back("Z");
        }
    }

    // 結果出力
    for (int i = 0; i < history.size(); i++) {
        cout << history[i] << (i == history.size() - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}
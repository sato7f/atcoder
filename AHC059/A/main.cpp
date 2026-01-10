// @prefix cpp_ICPC
// @description ICPC用のC++スニペット

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cfenv>
#include <cfloat>
#include <chrono>
#include <cinttypes>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdarg>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <fstream>
#include <functional>
#include <initializer_list>
#include <iomanip>
#include <ios>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <streambuf>
#include <string>
#include <tuple>
#include <type_traits>
#include <typeinfo>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

template <typename T>
using V = vector<T>;
template <typename T>
using VV = vector<vector<T>>;
using vi = vector<int>;
using vl = vector<long long>;
using vd = vector<double>;
using vc = vector<char>;
using vs = vector<string>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<long long>>;
using vvd = vector<vector<double>>;
using vvc = vector<vector<char>>;
using vvs = vector<vector<char>>;
using pi = pair<int, int>;
using pl = pair<long long, long long>;
using pc = pair<char, char>;
using ps = pair<string, string>;
using vp = vector<pair<long long, long long>>;
template <typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

template <typename T, typename U>
struct P : pair<T, U> {
    template <typename... Args>
    P(Args... args) : pair<T, U>(args...) {}

    using pair<T, U>::first;
    using pair<T, U>::second;

    P &operator+=(const P &r) {
        first += r.first;
        second += r.second;
        return *this;
    }
    P &operator-=(const P &r) {
        first -= r.first;
        second -= r.second;
        return *this;
    }
    P &operator*=(const P &r) {
        first *= r.first;
        second *= r.second;
        return *this;
    }
    template <typename S>
    P &operator*=(const S &r) {
        first *= r, second *= r;
        return *this;
    }
    P operator+(const P &r) const { return P(*this) += r; }
    P operator-(const P &r) const { return P(*this) -= r; }
    P operator*(const P &r) const { return P(*this) *= r; }
    template <typename S>
    P operator*(const S &r) const {
        return P(*this) *= r;
    }
    P operator-() const { return P{-first, -second}; }
};

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), v.rend()
#define each(i, v) for (auto i : v)
#define each2(x, y, v) for (auto [x, y] : v)
#define rep(i, N) for (long long i = 0; i < (long long)(N); i++)
#define repr(i, N) for (long long i = (long long)(N) - 1; i >= 0; i--)
#define rep1(i, N) for (long long i = 1; i <= (long long)(N); i++)
#define repr1(i, N) for (long long i = (N); (long long)(i) > 0; i--)
#define reg(i, a, b) for (long long i = (a); i < (b); i++)
#define regr(i, a, b) for (long long i = (b) - 1; i >= (a); i--)
#define mod(a, b) (a % b + b) % b // 出力が正整数になるmod計算
#define input(a) cin >> a

constexpr long long INF = 0x3f3f3f3f;
constexpr long long LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr double EPS = 1e-8;
constexpr long long MOD = 998244353;
// constexpr long long MOD = 1000000007;
long long dx4[8] = {0, 1, 0, -1};
long long dy4[8] = {-1, 0, 1, 0};
long long dx8[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
long long dy8[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

#define ll long long
// #define pb push_back
// #define fi first
// #define se second

// １次元配列を表示する
template <typename T>
void privec(T vec) {
    rep(i, vec.size()) { cout << vec[i] << " "; }
    cout << endl;
}

// ２次元配列を表示する
template <typename T>
void primtx(T mtx) {
    rep(i, mtx.size()) {
        rep(j, mtx[i].size()) { cout << mtx[i][j] << " "; }
        cout << "\n";
    }
}

// index が条件を満たすかどうか
template <typename T>
bool isOK(long long index, long long key, vector<T> vec) {
    if (vec[index] >= key) return true;
    else return false;
}

// 汎用的な二分探索のテンプレ
template <typename T>
long long binary_search(T key, vector<T> vec) {
    long long ng = -1; //「index = 0」が条件を満たすこともあるので、初期値は -1
    long long ok = vec.size(); // 「index = a.size()-1」が条件を満たさないこともあるので、初期値は a.size()

    /* ok と ng のどちらが大きいかわからないことを考慮 */
    while (abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;
        if (isOK(mid, key, vec)) ok = mid;
        else ng = mid;
    }
    return ok;
}

// 比較関数（sort()の第三引数に入れる）
bool my_compare(pair<ll, string> a, pair<ll, string> b){
    // 基本はfirstで比較
    if(a.first != b.first){
        // return a.first < b.first; // 昇順
        return a.first > b.first; // 降順
    }
    // それ以外はsecondで比較
    if(a.second != b.second){
        return a.second < b.second; // ABC順
    }else return true; // どちらも同じ
}


//比較演算子オーバーロード
//2つのメンバ変数をもとに比較する
struct Node{
    ll key1;  //比較時のキー（第1優先）
    string key2;  //比較時のキー（第2優先）
    ll value;  //順序に関係しない値

    /*bool operator<(const Node& other) const {
        //2つの構造体のkey1が異なる値を取るならkey1の比較結果を返す
        //key1の値が等しい場合はkey2の比較結果を返す
        if(key1 != other.key1) return key1 < other.key1;
        else return key2 < other.key2;
    }*/

    void pri(){
        cout << key1 << ", " << key2 << ", "<< value << endl;
    }
};

// struct Point
// {
// 	ll x, y;
// };

vl GridBFS(const vvl& grid, const vl& start)
{
    
	// グリッドの行数 (高さ)
	// const ll H = static_cast<ll>(grid.size());
    const ll H = 20;

	// グリッドの列数 (幅)
	// const ll W = static_cast<ll>(grid[0].size());
    const ll W = 20;

	// 各マスまでの最短距離（-1 は未訪問）
	vvl distances(H, vl(W, -1));

	// スタート地点の距離は 0 とする
	distances[start[0]][start[1]] = 0;

	// 幅優先探索のキュー
	std::queue<vl> q;

	// スタート地点をキューに追加する
	q.push(start);

	// 上下左右のマスへのオフセット
	vl Offsets[] = { { 0, -1 }, { 0, 1 }, { -1, 0 }, { 1, 0 } };

	while (!q.empty())
	{

        cout << "dfg\n";
        cout << q.size() << "@@@\n";
		// キューの先頭のマスの座標（現在地）
		const vl current = q.front(); q.pop();
        cout << current[0] << endl;
        cout << q.size() << "@\n";
        privec(current);
        cout << current.size() << endl;

        // pointの値が-1ならカードなし
        // 現在のpointの値が-1以外（何かカードがある）なら
        // 最短のマンハッタン距離のカードなのでその座標を返す
        if(grid[current[1]][current[0]] != -1){
            return {current[1], current[0]};
        }

        cout << "dfgw\n";
		// 上下左右の各マスを調べる
		for (const auto& offset : Offsets)
		{
            cout << "ggf\n";
			// 新たなマスの座標
			const int nx = (current[1] + offset[1]);
			const int ny = (current[0] + offset[0]);

            cout << nx << ", " << ny << endl;

            cout << "gge\n";

			// 範囲外の場合はスキップする
			if ((nx < 0) || (W <= nx) || (ny < 0) || (H <= ny))
			{
				continue;
			}
            cout << "gg\n";
			// 壁の場合はスキップする
			// if (grid[ny][nx] == '#')
			// {
			// 	continue;
			// }

			// すでに訪れている場合はスキップする
			if (distances[ny][nx] != -1)
			{
				continue;
			}
            cout << "og\n";
			// 新たなマスまでの距離を記録する
			distances[ny][nx] = (distances[current[0]][current[1]] + 1);

			// 新たなマスをキューに追加する
			// q.emplace(nx, ny);
            q.push({nx, ny});
            cout << nx << ", " << ny << endl;
            cout << "ggg\n";
		}
	}

    // なにもカードが見つからなかった場合
    return {-1, -1};

	// return distances;
}

class machineState {
    public:
        ll pos_row, pos_col;
        vl card_stack = {};

        // 状態の表示
        void pri(){
            cout << "↓ vvvvvv\n";

            cout << "(" << pos_row << ". "<< pos_col << ")\n";
            // cout << "card_stack size: " << card_stack.size() << endl;
            privec(card_stack);

            cout << "↑ ^^^^^\n";
        }
        
        // 取る
        void pickup_card(ll row, ll col, vvl mat){

            // 座標の更新（一応）
            pos_row = row;
            pos_col = col;

            // スタックにカードを追加
            // ただし，もし追加するカードと元々スタックの一番上にあったカードが同じなら
            // 両方のカードをスタックから消す
            if(card_stack.size() > 0 && card_stack.back() == mat[row][col]){
                card_stack.pop_back();
            }
            else{
                card_stack.push_back(mat[row][col]);
            }
        }

        // 置く
        ll discard_card(){
            // グリッドに置くカードを返す
            ll current_card = card_stack.back();

            // スタックからカードを削除
            card_stack.pop_back();

            return current_card;
        }

        // 動きに合わせてstateを更新
        // 範囲外処理はここではしない
        void move(string way){
            if(way == "U") {pos_row++;}
            else if(way == "D") {pos_row--;}
            else if(way == "R") {pos_col++;}
            else if(way == "L") {pos_col--;}
            // UDRL以外は受け付けない
            else {exit(0);}
        }

};

// 拾う
// 状態の更新と辞書の更新とグリッドの更新
void pickup(ll row, ll col, vvl& mat, machineState& state, map<ll, vvl>& card_pos){

    cout << "pp\n";
    
    // 状態の更新
    state.pickup_card(row, col, mat);

    cout << "pp2\n";

    // 辞書の更新
    card_pos[mat[row][col]].erase(std::remove(all(card_pos[mat[row][col]]), (vl){row, col}), card_pos[mat[row][col]].end());
    
    cout << "pp3\n";

    // グリッドの更新
    mat[row][col] = -1;
}

// 置く
// 状態の更新と辞書の更新とグリッドの更新
void discard(ll row, ll col, vvl& mat, machineState& state, map<ll, vvl>& card_pos){
    // 状態の更新
    ll poped_card = state.discard_card();
    
    // 辞書の更新
    card_pos[poped_card].push_back({row, col});

    // グリッドの更新
    mat[row][col] = poped_card;
}

// 現在のスタックの一番上のカードのペアのカードの位置
// vl pair_card_pos(ll card_num, map<ll, vvl> card_pos){
//     card_num
// }

// スタート座標からゴール座標までの道のり
vs calc_way(vl pos_start, vl pos_goal){
    vs way_vec;
    string move_way_row, move_way_col;

    /* 先に縦方向の移動 */

    ll d_row = pos_goal[0] - pos_start[0];
    
    // ゴールのrow座標がスタートのrow座標より大きい（＝差分が正）なら下に移動したいので"D"
    if(0 < d_row){
        move_way_row = "D";
    }
    else{
        move_way_row = "U";
    }

    rep(i, abs(d_row)){
        way_vec.push_back(move_way_row);
    }

    /* そのあと横方向の移動 */

    ll d_col = pos_goal[1] - pos_start[1];
    
    // ゴールのcol座標がスタートのcol座標より大きい（＝差分が正）なら右に移動したいので"R"
    if(0 < d_col){
        move_way_col = "R";
    }
    else{
        move_way_col = "L";
    }

    rep(i, abs(d_row)){
        way_vec.push_back(move_way_col);
    }

    return way_vec;
}


int main() {
    ll N;
    cin >> N;
    
    vvl mat(N, vl(N));
    rep(i, N){
        rep(j, N){
            cin >> mat[i][j];
        }
    }

    primtx(mat);
    cout << "--" << endl;

    // 辞書で各カードの配置を保持
    map<ll, vvl> card_pos_dict;

    rep(i, N){
        rep(j, N){
            card_pos_dict[mat[i][j]].push_back({i, j});
        }
    }

    // 辞書内容チェック
    // for (const auto& [key, value] : card_pos_dict){
    //     vl value_1 = value[0];
    //     vl value_2 = value[1];
    //     cout << key << " => (" << value_1[0] << ", " << value_1[1] << "), (" << value_2[0] << ", " << value_2[1] << ")\n";
    // }

    
    
    // 状態変数の初期化
    vs move_way_list = {};
    machineState mstate;
    mstate.pos_row = 0;
    mstate.pos_col = 0;

    // 現在の座標から最も近い
    vl next_pos = GridBFS(mat, {0, 0});

    mstate.pri();

    // 次の目標座標がなくなるまでループ
    while(next_pos != (vl){-1, -1}){

        cout << "--------------------------\n";

        /* 拾う */

        cout << "ペア１：拾い処理開始\n";

        // (0,0)のカードを拾うとこから開始
        // 状態の更新とグリッドの更新と辞書の更新
        pickup(mstate.pos_row, mstate.pos_col, mat, mstate, card_pos_dict);

        // deb
        primtx(mat);
        mstate.pri();
        
        // 動きリストに入れる
        move_way_list.push_back("Z");

        // 現在のスタックの一番上のカードのペアのカードの位置
        vl next_target_pos = card_pos_dict[mstate.card_stack.back()][0];
        
        // cout << "kore?\n";
        // privec(next_target_pos);
        
        cout << "ペア１：拾い処理終了\n";

        // /* 移動 */

        cout << "移動処理開始\n";
        
        // // マシン座標を更新
        mstate.pos_row = next_target_pos[0];
        mstate.pos_col = next_target_pos[1];

        mstate.pri();

        // 動きリストに入れる
        vs way_list = calc_way({mstate.pos_row, mstate.pos_col}, next_target_pos);
        std::copy(all(way_list),std::back_inserter(move_way_list));

        cout << "移動処理終了\n";

        /* 拾う */

        cout << "ペア２：拾い処理開始\n";

        // (0,0)のカードを拾うとこから開始
        // 状態の更新とグリッドの更新と辞書の更新
        pickup(mstate.pos_row, mstate.pos_col, mat, mstate, card_pos_dict);

        // deb

        primtx(mat);
        mstate.pri();
        
        // 動きリストに入れる
        move_way_list.push_back("Z");

        cout << "ペア２：拾い処理終了\n";

        /* 現在の座標から最も近い座標を取得 */
        next_pos = GridBFS(mat, {mstate.pos_row, mstate.pos_col});

        // break;
    }
    
    rep(i, move_way_list.size()){
        cout << move_way_list[i] << ", ";
    }



    return 0;
}

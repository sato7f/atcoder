using namespace std;

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

#define ll long long

template <typename T>
using V = vector<T>;
template <typename T>
using VV = vector<vector<T>>;
using vi = vector<int>;
using vl = vector<long long>;
using vd = V<double>;
using vs = V<string>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<long long>>;
using vvs = vector<vector<string>>;

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
template <typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;
using pl = P<long long, long long>;
using pi = P<int, int>;
using vp = V<pl>;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), v.rend()
#define each(x, v) for (auto x : v)
// #define each2(x, y, v) for (auto [x, y] : v)
#define rep(i, N) for (long long i = 0; i < (long long)(N); i++)
#define repr(i, N) for (long long i = (long long)(N)-1; i >= 0; i--)
#define rep1(i, N) for (long long i = 1; i <= (long long)(N); i++)
#define repr1(i, N) for (long long i = (N); (long long)(i) > 0; i--)
#define reg(i, a, b) for (long long i = (a); i < (b); i++)
#define regr(i, a, b) for (long long i = (b)-1; i >= (a); i--)
// #define fi first
// #define se second

#define in(a) cin >> a
#define out(a, b) cout << a << b
constexpr int INF = 0x3f3f3f3f;
constexpr long long LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr double EPS = 1e-8;
constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
#define pb push_back


struct UnionFind {
    // 親の要素とサイズを管理する変数
    vector<int> parent, size;

    // 変数の初期化
    UnionFind(int n) : parent(n, -1), size(n, 1) {}

    // x の根を求める
    int root(int x) {
        // x が根のとき
        if(parent[x] == -1) return x;

        // 経路圧縮
        return parent[x] = root(parent[x]);
    }

    // x と y の根が同じか
    bool isSame(int x, int y) {
        return root(x) == root(y);
    }

    // x と y のグループを併合する
    void unite(int x, int y) {
        // x と y の根を取得
        int rootX = root(x);
        int rootY = root(y);

        // x と y が同じグループのときは何もしない
        if (rootX == rootY) return;

        // union by size（ y のサイズが小さくなるように調整 ）
        if (size[rootX] < size[rootY]) swap(rootX, rootY);

        // y の親を x にする
        parent[rootY] = rootX;

        // x のサイズに y のサイズを足す
        size[rootX] += size[rootY]; 
    }
};

bool isAdj(int i1, int j1, int i2, int j2){
    if(max(pow(i1 - i2, 2), pow(j1 - j2, 2)) == 1)return true;
    else return false;
}

int main(){
    int H, W;
    in(H);in(W);
    vector<vector<char>> vvc(H, vector<char>(W));
    vp vp;
    rep(i, H){
        rep(j, W){
            in(vvc[i][j]);
            if (vvc[i][j] == '#'){
                vp.push_back({i, j});
            }
        }
    }
    int size = vp.size();
    UnionFind tree(size);
    rep(i, size){// 注目
        rep(j, size){ // 検証
            if(! tree.isSame(i, j)){
                if(isAdj(vp[i].first, vp[i].second, vp[j].first, vp[j].second)){
                    tree.unite(i, j);
                }
            }
        }
    }

    // vi vec = tree.parent;
    // sort(all(vec));
    // vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
    //each(i, vec)out(i, "\n");

    out(count(all(tree.parent), -1), "\n");

    return 0;
}

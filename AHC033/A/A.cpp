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
using vvc = vector<vector<char>>;

// 最後の引数を出力するためのテンプレート関数
template <typename T>
void print_impl_endl(T &&arg) {
    std::cout << arg << std::endl;
}
// 複数の引数を出力するためのテンプレート関数
template <typename T, typename... Args>
void print_impl_endl(T &&first, Args &&...args) {
    std::cout << first << " ";
    print_impl_endl(std::forward<Args>(args)...);
}
// メインのprint関数（改行あり）
template <typename... Args>
void print(Args &&...args) {
    print_impl_endl(std::forward<Args>(args)...);
}

// 最後の引数を出力するためのテンプレート関数
template <typename T>
void print_impl_end(T &&arg) {
    std::cout << arg;
}
// 複数の引数を出力するためのテンプレート関数
template <typename T, typename... Args>
void print_impl_end(T &&first, Args &&...args) {
    std::cout << first << " ";
    print_impl_end(std::forward<Args>(args)...);
}
// メインのprint関数（改行無し）
template <typename... Args>
void printf_cpp(Args &&...args) {
    print_impl_end(std::forward<Args>(args)...);
}

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
#define each(i, v) for (auto i : v)
#define each2(x, y, v) for (auto [x, y] : v)
#define rep(i, N) for (long long i = 0; i < (long long)(N); i++)
#define repr(i, N) for (long long i = (long long)(N) - 1; i >= 0; i--)
#define rep1(i, N) for (long long i = 1; i <= (long long)(N); i++)
#define repr1(i, N) for (long long i = (N); (long long)(i) > 0; i--)
#define reg(i, a, b) for (long long i = (a); i < (b); i++)
#define regr(i, a, b) for (long long i = (b) - 1; i >= (a); i--)
// #define fi first
// #define se second

#define input(a) cin >> a
constexpr int INF = 0x3f3f3f3f;
constexpr long long LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr double EPS = 1e-8;
constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
#define pb push_back
#define mod(a, b) (a % b + b) % b // 出力が正整数になるmod計算


// 入荷　containers arriving
// 出荷　containers shipping

// 局面の状態
struct factoryState{
    // 出荷前のコンテナの行列
    vector<vector<ll>> A;
    // 盤面のコンテナの行列
    vector<vector<ll>> B;
    // 出荷後のコンテナの行列
    vector<vector<ll>> D;
    // ターン数
    ll turn;
};

// 行列を表示する関数
void printMtx(vvl Mtx, string Mtx_name = "Mtx"){
    cout << Mtx_name << ":" << endl;
    rep(i, Mtx.size()){
        cout << "[" << i << "] ";
        rep(j, Mtx[i].size()){
            cout << setw(2) << Mtx[i][j] << " ";
        }
        cout << endl;
    }
}

// 全てのコンテナが出荷したか確認
bool isAllContainersShipping(vvl D){
    ll sum_container = 0;
    rep(i, D.size()){
        sum_container += D[i].size();
    }
    if (25 <= sum_container) return true;
    else return false;
}

// 出荷処理
vector<factoryState> arriveContainers(vector<factoryState> state){
    rep(i, D.size()){

    }

    return {A, B}
}


int main() {
    // 入力
    ll N;
    cin >> N;
    // 待機行列
    vvl A(N, vector<ll>(N));
    rep(i, N){
        rep(j, N){
            cin >> A[i][j];
        }
    }

    // 盤面行列
    vvl B(N, vector<ll>(N));
    // 出荷済み行列
    vvl D(N, vector<ll>(0));
    // ターンごとに回す
    ll turn = 0;

    factoryState state = {A, B, D, turn};

    // クレーンの位置の初期化完了
    vp crane_pos(N);
    rep(i, N) crane_pos[i] = {1, 0};


    while(true){
        // 1ターン経過
        state.turn++;

        // 入荷処理


        // クレーン操作

        // 出荷処理

        // 終了条件判定
        // 1. 全てのコンテナが出荷
        // 2. 10000ターンになった（10000ターンまでしか許されないから）
        if (isAllContainersShipping(state.D) || 10000 < state.turn) break;


        // デバッグ
        cout << state.turn << ", " << isAllContainersShipping(state.D) << endl;
        printMtx(state.A);
        if (state.turn == 4) break;
    }

    return 0;
}

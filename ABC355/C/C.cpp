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

vector<vector<ll>> Mtx2MtxT(vector<vector<ll>> Mtx){
    ll Mtx_size = Mtx.size();
    vvl MtxT(Mtx_size, vector<ll>(Mtx_size));

    rep(i, Mtx_size){
        rep(j, Mtx_size){
            MtxT[i][j] = Mtx[j][i];
        }
    }
    return MtxT;
}

bool isBing1Row(vl vec){
    ll hit = count(all(vec), 1);
    ll vec_size = vec.size();
    return (hit == vec_size);
}

bool isBingo(vvl Mtx){
    ll Mtx_size = Mtx.size();

    /*
    // 行
    rep(i, Mtx.size()){
        if(isBing1Row(Mtx[i])) return true;
    }
    */

    /*
    // 列
    vector<vector<ll>> MtxT = Mtx2MtxT(Mtx);
    rep(i, MtxT.size()){
        if(isBing1Row(MtxT[i])) return true;
    }
    */

    // ななめ
    // vl naname_sra_vec; // ／
    vl naname_bcsra_vec = {}; // ＼
    rep(i, Mtx_size){
        naname_bcsra_vec.push_back(Mtx[i][i]);
        // if(j == Mtx_size - i) naname_sra_vec.push_back(Mtx[i][j]);
    }
    // if (isBing1Row(naname_sra_vec)) return true;
    if (isBing1Row(naname_bcsra_vec)) return true;

    return false;
}


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

int main() {
    ll N, T;
    input(N);
    input(T);

    vvl A(N, vector<ll>(N, 0));
    vvl AT(N, vector<ll>(N, 0));
    vl A_hit(N);
    vl AT_hit(N);
    ll ok_pos, row, col;

    rep(i, T){
        input(ok_pos);
        ok_pos--;
        row = ok_pos / N;
        col = ok_pos % N;
        if (++A_hit[row] == N){
            cout << i + 1 << endl;
            return 0;
        }
        if (++AT_hit[row] == N){
            cout << i + 1 << endl;
            return 0;
        }
        
        A[row][col] = 1;
        AT[col][row] = 1;

        // printMtx(A);

        if(isBingo(A) || isBingo(AT)){
            cout << i + 1 << endl;
            return 0;
        }
    }

    cout << -1 << endl;
    return 0;
}

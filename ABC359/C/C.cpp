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
        cout << endl;
    }
}

int main() {
    ll sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;

    // 座標を横長四角の真ん中にする
    /* if (!(sx % 2 == 0 && sy % 2 == 0)){  // || (sx % 2 == 0 && sy % 2 == 1)) {
        sx--; // sx++;
        //cout << "sx-  "<< sx << ", " << sy << ", " << tx << ", " << ty << endl;
    }*/
    if((sx + sy) % 2 == 1) sx--;
    /*
    if((sx % 2 == 0 && sy % 2 == 1)){
        sx--;
        cout << "sx+  "<< sx << ", " << sy << ", " << tx << ", " << ty << endl;
    }*/

    /*if (!(tx % 2 == 0 && ty % 2 == 0)){  // || (sx % 2 == 0 && sy % 2 == 1)) {
        tx--; // tx++;
        //cout << "tx-  "<< sx << ", " << sy << ", " << tx << ", " << ty << endl;
    }*/
    if((tx + ty) % 2 == 1) tx--;
    /*
    if((sx % 2 == 0 && sy % 2 == 1)){
        sx--;
        cout << "sx+  "<< sx << ", " << sy << ", " << tx << ", " << ty << endl;
    }*/
    
    //cout << "@  " << sx << ", " << sy << ", " << tx << ", " << ty << endl;
    
    ll ans;
    ll dy = abs(ty - sy);
    ll dx = abs(tx - sx);

    // if(dy < dx) ans = dy + abs(dx - dy) / 2;
    // else ans = dy;
    ans = (dy + max(dx, dy)) / 2;

    cout << ans << endl;
    return 0;
}

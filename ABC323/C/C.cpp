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

typedef long long ll;
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
// #define each2(x, y, v) for (auto [x, y] : v)
#define rep(i, N) for (long long i = 0; i < (long long)(N); i++)
#define repr(i, N) for (long long i = (long long)(N)-1; i >= 0; i--)
#define rep1(i, N) for (long long i = 1; i <= (long long)(N); i++)
#define repr1(i, N) for (long long i = (N); (long long)(i) > 0; i--)
#define reg(i, a, b) for (long long i = (a); i < (b); i++)
#define regr(i, a, b) for (long long i = (b)-1; i >= (a); i--)
/// #define fi first
/// #define se second

#define in(a) cin >> a
#define out(a, b) cout << a << b
constexpr int INF = 0x3f3f3f3f;
constexpr long long LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr double EPS = 1e-8;
constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
#define pb push_back

int main(){
  int N, M;
  in(N);in(M);
  vi a_vec(M);
  vs s_vec(N);
  vi point(N);
  rep(i, M)in(a_vec[i]);
  // each(i, a_vec)out(i, " ");
  rep(i, N){
    in(s_vec[i]);
    
    // 得点計算
    point[i] = i + 1;
    rep(j, a_vec.size()){
      if (s_vec[i][j] == 'o'){
        point[i] += a_vec[j];
      }
    }
    // out(point[i], "\n");
  }
  int max_p = *max_element(all(point));
  
  // ポイントとインデックスのソート
  vp point_index(M);
  rep(index, M)point_index[index] = {a_vec[index], index};
  sort(rall(point_index)); // 大きい順
  // each(i, point_index)out(i.first, " ");out("", "\n");

  // どうポイントを追加すれば最大ポイントを超えられるか
  // 多くともM問分ポイントを足せば最大ポイントになれる
  // i人目の解答出力
  rep(i, N){
    int tmp_point = 0; // ポイントの増加分
    // j問目
    rep(j, M){
      
      // ポイントが大きい順にi問分のポイントを足して最大値と比較
      if (max_p <= point[i] + tmp_point){
        // cout << max_p << " " << point[i] + tmp_point << " " << i << " " << j << "\n";
        out(j, "\n");
        break;
      }
      while(true){
        if (s_vec[i][point_index[j].second] == 'x') {
          tmp_point += point_index[j].first;
          break;
        }
        else j++;
      }

    }
  }

  return 0;
}

/*入力例
N M
A1, A2, ..
S1
S2
..


3 4
1000 500 700 2000
xxxo
ooxx
oxox
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iomanip>
#include <utility>
#include <tuple>
#include <functional>
#include <bitset>
#include <cassert>
#include <complex>
#include <stdio.h>
#include <time.h>
#include <numeric>
#include <random>
#include <unordered_set>
#include <unordered_map>
#define all(a) (a).begin(), (a).end()
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define req(i, a, b) for (ll i = (a); i < (b); i++)
#define pb push_back
#define debug(x) cerr << __LINE__ << ' ' << #x << ':' << (x) << '\n'
#define debug2(x, y) cerr << __LINE__ << ' ' << #x << ':' << (x) << ',' << #y << ':' << (y) << '\n'
#define debug3(x, y, z) cerr << __LINE__ << ' ' << #x << ':' << (x) << ',' << #y << ':' << (y) << ',' << #z << ':' << (z) << '\n'
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long double ld;
template<class T> using P = pair<T, T>;
template<class T> using pri_s = priority_queue<T, vector<T>, greater<T>>;
template<class T> using pri_b = priority_queue<T>;
constexpr int inf = 1000000010;
constexpr int inf2 = 2000000010;
constexpr ll INF = 1000000000000000010;
constexpr ll INF4 = 4000000000000000010;
constexpr int mod1e9 = 1000000007;
constexpr int mod998 = 998244353;
constexpr ld eps = 1e-12;
constexpr ld pi = 3.141592653589793238;
constexpr ll ten(int n) { return n ? 10 * ten(n - 1) : 1; };
int dx[] = { 1,0,-1,0,1,1,-1,-1,0 }; int dy[] = { 0,1,0,-1,1,-1,1,-1,0 };
ll mul(ll a, ll b) { return (b != 0 && a > INF / b ? INF : a * b); }
void fail() { cout << "-1\n"; exit(0); } void no() { cout << "No\n"; exit(0); }
template<class T> void er(T a) { cout << a << '\n'; exit(0); }
template<class T, class U> inline bool chmax(T& a, const U& b) { if (a < b) { a = b; return true; } return false; }
template<class T, class U> inline bool chmin(T& a, const U& b) { if (a > b) { a = b; return true; } return false; }
template<class T> istream& operator >>(istream& s, vector<T>& v) { for (auto& e : v) s >> e; return s; }
template<class T> ostream& operator <<(ostream& s, const vector<T>& v) { for (auto& e : v) s << e << ' '; return s; }
template<class T> ostream& operator <<(ostream& s, const set<T>& v) { for (auto& e : v) s << e << ' '; return s; }
template<class T> ostream& operator <<(ostream& s, const multiset<T>& v) { for (auto& e : v) s << e << ' '; return s; }
template<class T, class U> ostream& operator << (ostream& s, const pair<T, U>& p) { s << p.first << ' ' << p.second; return s; }
 
struct fastio {
	fastio() {
		cin.tie(0); cout.tie(0);
		ios::sync_with_stdio(false);
		cout << fixed << setprecision(20);
		cerr << fixed << setprecision(20);
	}
}fastio_;


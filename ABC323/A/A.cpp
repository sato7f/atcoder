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
#define rep(i, n) for (int i = 0; i < (n); i++)
#define req(i, a, b) for (ll i = (a); i < (b); i++)
#define pb push_back
using namespace std;

int main(){
    rep(i, 16){
        char s;
        cin >> s;
        if ((i+1) % 2 == 0 && s == '1'){
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
    return 0;
}
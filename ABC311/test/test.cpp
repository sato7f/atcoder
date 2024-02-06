#include <iostream>
using namespace std;
template<typename T, typename U>
T Add(T a,U b){
    return a+b;
}

int main(){
    auto ans = Add(1.4, 2);
    cout << ans << endl;
    cout << Add(1.4, 2) << endl;


    return 0;
}
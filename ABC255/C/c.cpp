#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <cstdlib>
using namespace std;

int main()
{
  int X,A,D,N;
  int nearist_N,ans;

  cin >> X >> A >> D >> N;

  if(D == 0)
  {
    nearist_N = 1;
  }
  else
  {
    if(0 < D)
    {
      if(X < A)
      {
        cout << A - X << endl;
        return 0;
      }
      else if(A+(N-1)*D < X)
      {
        cout << X - A+(N-1)*D << endl;
      }
    }
    else if(D < 0)
    {
      if(X < A)
      {
        cout << abs(X - A+(N-1)*D) << endl;
        return 0;
      }
      else if(A+(N-1)*D < X)
      {
        cout << abs(A - X) << endl;
        return 0;
      }
    }
    nearist_N = (X-A)/D + 1;
  }
  

  ans = abs( X - (A + (nearist_N-1)*D) );
  cout << X << "," << (A + (nearist_N-1)*D) << ","  << nearist_N << "," << ans << endl;
  //cout << ans << endl;

  return 0;
}
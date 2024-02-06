#include <iostream>

using namespace std;

int main()
{
  string S,T;
  cin >> S >> T;
  //cout << S << "," << T << endl;

  S = "123" + S;
  T = "123" + T;
  //cout << S << endl;
  
  for(int i = 3;i<S.size();i++)
  {
    if(S[i-2] == S[i-1] && S[i-1] == S[i])
    {
      //cout << S[i-2] << "=" << S[i-1] << "||" << S[i-1] << "=" << S[i] << endl;
      S.erase(i-2,1);
      i--;
    }
  }

  for(int i = 3;i<T.size();i++)
  {
    if(T[i-2] == T[i-1] && T[i-1] == T[i])
    {
      //cout << S[i-2] << "=" << S[i-1] << "||" << S[i-1] << "=" << S[i] << endl;
      T.erase(i-2,1);
      i--;
    }
  }

  if(S == T)
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }



  //cout << S << "\n" << T << endl;
  return 0;
}
#include <iostream>
#include <vector>
#include <utility>
#include <string>
using namespace std;

vector<string> ary_carrytop(string S,int N)
{
  vector<string> ary = {S};
  for(int i = 0;i<N;i++)
  {
    S = S.back() + S;
    S.erase(N,1);
    ary.push_back(S);
    //cout << i << "," << ary[i] << endl;
  }
  return ary;
}

void print_string(string S)
{
  cout << S << endl;
}

string operation(string S,int N,int x,vector<string> aryAnswer)
{
  int x_mod = x % N;
  //cout << "x=" << x << ",N=" << N << ",x mod N =" << x_mod << endl;
  return aryAnswer[x_mod];
}

int main(void)
{
  int N,Q;
  string S;
  int x = 0;

  cin >> N >> Q >> S;
  //cout << N << Q << S << endl;

  vector<string> aryAnswer = ary_carrytop(S,N);

  int fir,sec;
  for(int i = 0;i<Q;i++)
  {
    //入力
    cin >> fir >> sec;

    //クエリ処理
    //「1 x」xをカウントしておく
    if(fir == 1)
    {
      x += sec;
      //print_string(S);
    }
    //「2 y」xmodN回処理してからy文字目表示
    else if(fir == 2)
    {
      S = operation(S,N,x,aryAnswer);
      cout << S[sec-1] << endl;
      //print_string(S);
    }
    else
    {
      cout << "error" << endl;
    }
  }


  return 0;
}
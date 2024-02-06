#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <cstdlib>
using namespace std;

void printVec(vector<int> ary)
{
  for(int i = 0;i<ary.size();i++)
  {
    cout << ary[i];
    if(i != ary.size()-1)
    {
      cout << ",";
    }
  }
  cout << endl;
}

int main()
{
  int N,K;
  int X;
  int flag = 1;
  vector<int> ary;

  cin >> N >> K;
  for(int i = 0;i<N;i++)
  {
    cin >> X;
    ary.push_back(X);
  }
  //printVec(ary);
  
  while(flag)
  {
    for(int i = 0;i<N-K;i++)
    {
      //cout << ary[i] << "," << ary[i+K] << endl;
      if(ary[i] > ary[i+K])
      {
        //cout << "swap!" << i << ":" << ary[i] << endl;
        swap(ary[i],ary[i+K]);
      }
      else flag = 0;
    }
  }

  printVec(ary);
  
  //cout << is_sorted(ary.begin(), ary.end()) << endl;

  return 0;
}
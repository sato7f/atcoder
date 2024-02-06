#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <cstdlib>
#include <algorithm>
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
  vector<int> ary = {2,3,1,7,5};
  vector<int> ary_sorted;
  copy(ary.begin(), ary.begin(), back_inserter(ary_sorted));
  
  printVec(ary);
  printVec(ary_sorted);

  if(ary == ary_sorted)
  {
    cout << "same!" << endl;
  }

  return 0;;
}
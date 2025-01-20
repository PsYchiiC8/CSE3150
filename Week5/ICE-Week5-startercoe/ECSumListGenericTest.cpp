#include <vector>
#include <set>
#include <iostream>
using namespace std;

#include "ECSumListGeneric.cpp"

int main()
{
  vector<double> vec;
  vec.push_back(2.5);
  vec.push_back(3);
  vec.push_back(3);
  vec.push_back(0);
  vec.push_back(1);
  double sum = ECSumList(vec);
  cout << "sum1: " << sum << endl;

  set<double> ss;
  ss.insert(2.5);
  ss.insert(3.0);
  ss.insert(3.0);
  ss.insert(0.0);
  ss.insert(1.0);
  double sum2 = ECSumList(ss);
  cout << "sum2: " << sum2 << endl;
}

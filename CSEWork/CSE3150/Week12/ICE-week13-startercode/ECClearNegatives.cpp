#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
// Set any negative numbers to zero in the passed-in vector
void ECClearNegatives(std::vector<int> &vec)
{
  // your code here
  // I want to you to write a single line of code
  // (yes, one line but it may be a little long...)
  // Try to practice std::transform
  std::transform(vec.begin(), vec.end(), vec.begin(), [](int x)->int { return x >= 0 ? x : 0;});
}

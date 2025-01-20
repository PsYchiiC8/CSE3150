#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

// compare function; for function pointer
bool cmp0(int x, int y)
{
  return x > y;
}

//functor
class cmp1{
public:
  cmp1() : nc(0) {}
  int GetNC() const { return nc; }
  bool operator()(int x, int y)
  {
    nc++;
    return x > y;
  }

private:
  int nc;
};

// lambda



// sorting
void mysort(vector<int> &v)
{
  // function pointer
  // std::sort(v.begin(), v.end(), cmp0);

  //using functor
  // cmp1 c;
  // std::sort(v.begin(), v.end(), std::ref(c));
  // cout << "nc: " << c.GetNC() << endl;

  //lambda
  std::sort(v.begin(), v.end(), [](int x, int y)->bool {return x < y;});
}


// testing
int main()
{
  vector<int> v;
  v.push_back(3);
  v.push_back(1);
  v.push_back(2);
  v.push_back(6);
  v.push_back(4);
  mysort(v);
  cout << "v: ";
  for(auto x: v)
  {
    cout << x << " ";
  }
  cout << endl;
}

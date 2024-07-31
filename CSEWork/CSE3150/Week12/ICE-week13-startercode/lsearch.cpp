// Modify the following code so that it uses lambda for compare
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

const double delta = 0.001;

bool compare(const double &x, const double &y)
{
  //return fabs(x-y) < delta;

  return [x, y] ()->bool { return fabs(x-y) < delta; }();
}

bool lsearch(const vector<double> &vec, const double &x)
{
  bool res = false;

  std::for_each(vec.begin(), vec.end(), [&res, x](double y) { if(fabs(x-y) < delta) { res = true; } });

#if 0
  for(unsigned int i=0; i<vec.size(); ++i)
  {
    if( compare(vec[i], x))
    {
      res = true;
      break;
    }
  }

#endif
  return res;


  // bool res = false;

  // return [vec, x](int i)->bool {if( vec[i] == x) {return true;} else return false;}(i);
}

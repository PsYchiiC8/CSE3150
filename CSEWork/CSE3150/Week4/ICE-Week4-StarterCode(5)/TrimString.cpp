#include <string>

using namespace std;

// ensure x is trimmed to contain its prefix of length of
// no more than five after the function call
void TrimString(string &x) {
    x = x.substr(0, 5);
#if 0
    string res;
    for(unsigned int i=0; i<5 && i<x.size(); ++i)
    {
      res += x[i];
    }
    x = res;
#endif
}

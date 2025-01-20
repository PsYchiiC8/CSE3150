#include <iostream>

using namespace std;

#include "ECTime.h"

int main(){
    ECTime t1(1, 40, 40), t2(2, 30, 30);
    ECTime t3 = t1 + t2;

    int h, m ,s;
    t3.GetTime(h, m, s);
    cout << "H: " << h << " M: " << m << " S: " << s << endl;
}
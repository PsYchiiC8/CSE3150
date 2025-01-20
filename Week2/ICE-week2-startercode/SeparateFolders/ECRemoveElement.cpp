#include <iostream>
using namespace std;

int ECRemoveSpace(int nums[], int len, int val)
{
//
    int p = 0, q = len-1;
    while( p < q )
    {
        if( nums[p] != val )
        {
            ++p;
        }
        else if( nums[q] == val )
        {
            --q;
        }
        else
        {
// nums[p] == val and nums[q] != val
            nums[p] = nums[q];
            nums[q] = val;
        }
    }

    return p;
}

#include <iostream>

using namespace std;

extern void ECRemoveSpace(int nums[], int len, int val);

/*
void ECRemoveSpace(int nums[], int len, int val)
{
  // Note: don't allocate extra memory for the array
  // approach: first scan the array to change any element=val to '_';
  // then move all '_' to the back of the array
  int numVals = 0;
  for(int i=0; i < len; ++i)
  {
    if( nums[i] == val )
    {
      nums[i] = '_';
      ++numVals;
    }
  }
  int numNonVals = len-numVals;
  int posFirst = 0, posSecond = numVals;	// positions into the first ans second parts to move
  while(true)
  {
    // find the position to swap
    while( posFirst < numNonVals && nums[posFirst] != '_')
    {
      ++posFirst;
    }
    while( posSecond < len && nums[posSecond] == '_')
    {
      ++posSecond;
    }
    if( posFirst >= numNonVals || posSecond >= len )
    {
      break;
    }
    // swap and inc the position
    int temp = nums[posFirst];
    nums[posFirst] = nums[posSecond];
    nums[posSecond] = temp;
    ++posFirst;
    ++posSecond;
  }
}  */

int main() {
    int nums1[] = {3, 2, 2, 3};
    ECRemoveSpace(nums1, 4, 3);
    cout << "nums1: ";
    for (int i = 0; i < 4; ++i) {
        cout << nums1[i] << " ";
    }
    cout << endl;
    int nums2[] = {0, 1, 2, 2, 3, 0, 4, 2};
    ECRemoveSpace(nums2, 8, 2);
    cout << "nums2: ";
    for (int i = 0; i < 8; ++i) {
        cout << nums2[i] << " ";
    }
    cout << endl;
    return 0;
}


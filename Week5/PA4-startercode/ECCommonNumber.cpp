// Given two arrays of integers, return true (and also store the smallest integer that is in both arrays). Return false if no such integer exists 
// For example, suppose A1={1, 5, 3, 1} and A2={3, 7, 2}. Then ECCommonNumber(A1, 4, A2, 3, val) would return true (and val would be 3 after function call returns). Here, A1 is the first array, 4 is the size of the first array, A2 is the second array and 3 is the size of the second array. 
// Note: you must implement your algorithm as efficiently as possible
// Also, you need to define the function yourself: how are you going to take
// Tip: don't reinvent the wheel; try to use C++ standard library functions

#include <cstring>
#include <algorithm>
using namespace std;


bool ECCommonNumber(int arr1[], int size1, int arr2[], int size2, int &valCommon){
    // your code here...
    if(size1 == 0 || size2 == 0){
        return false;
    }

    int i = 0, j = 0;

    sort(arr1, arr1 + size1);
    sort(arr2, arr2 + size2);

    while (i < size1 && j < size2) {
        if (arr1[i] == arr2[j]) {
            valCommon = arr1[i];
            return true;
        } else if (arr1[i] < arr2[j]) {
            i++;
        } else if (arr1[i] > arr2[j]){
            j++;
        }
    }

    return false;
}


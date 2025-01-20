//
//  RemoveDupPointers.cpp
//  
//
//  Created by Yufeng Wu on 1/18/21.
//
//

#include <string>
#include <vector>
#include <algorithm>
using namespace std;


bool compareStringPointers(string* a, string* b) {
    return *a == *b;
}

void RemoveDupPointers(vector<string *> &arrayPtrs)
{
    // arrayPtrs: STL vector of pointers to strings
    // remove pointers that are pointed to identical strings in the array
    // Your code goes here...
    vector<string*> uniquePtrs;
    for (const auto ptr : arrayPtrs) {
        bool isDuplicate = false;
        for (const auto uniquePtr : uniquePtrs) {
            if (compareStringPointers(ptr, uniquePtr)) {
                isDuplicate = true;
                break;
            }
        }
        if (!isDuplicate) {
            uniquePtrs.push_back(ptr);
        }
    }
    arrayPtrs = move(uniquePtrs);
}

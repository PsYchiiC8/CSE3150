#include <vector>
#include <iostream>

using namespace std;

// return the sum of the numbers
int ECSumList(const vector<int> &listNums) {
    // your code goes here ...
    int res = 0;
//    for(int i = 0; i < (int)listNums.size(); i++){
    for(auto num: listNums){
        res += num;
    }

    return res;
}


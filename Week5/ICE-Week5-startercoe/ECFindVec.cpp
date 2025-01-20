#include <vector>

using namespace std;

bool ECFind(const vector<int> &listVecs, int x) {
    // your code here
    for(auto val : listVecs){
        if(val == x){
            return true;
        }
    }

    return false;
}


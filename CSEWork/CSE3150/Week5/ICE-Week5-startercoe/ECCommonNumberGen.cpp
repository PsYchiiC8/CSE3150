// Recall in PA3, you want to find a common number in two arrays
// That function only assumes integer type; what about others: char, string, long, etc?
// Now implement a more generic common number finding function that works for different types, and we change the input type to vector
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

template<class T>
bool ECCommonNumber(const vector <T> &listA, const vector <T> &listB, T &val) {
    // your code here
//    vector <T> listB1(listB.size());
//
//    std::copy(listB.begin(), listB.end(), listB1.begin());
//    std::sort(listB1.begin(), listB1.end());


//    vector<T> listB1;
//    std::copy(listB.begin(), listB.end(), std::back_inserter(listB1));
//
//    std::sort(listB1.begin(), listB1.end());
//
//    for (auto x: listA) {
//        if (std::binary_search(listB1.begin(), listB1.end(), x)) {
//            val = x;
//            return true;
//        }
//    }

    set<T> = ss;
    std::copy(listB.begin(), listB.end(), std::insertter(ss, ss.end()));
    for(auto x : listA){
        if(ss.find(x)){
            val = x;
            return true;
        }
    }

    return false;
}


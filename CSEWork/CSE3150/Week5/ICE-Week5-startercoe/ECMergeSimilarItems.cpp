// This is a Leetcode problem
// You are given two lists (vectors), items1 and items2, representing two sets of items. Each item is a pair: [valuei, weighti] where valuei represents the value and weighti represents the weight of the ith item. The value of each item in items is unique.
// Store the results in a third list ret, where ret[i] = [valuei, weighti], with weighti being the sum of weights of all items with value valuei.
// Note: ret should be returned in ascending order by value. 
// Input: items1 = [[1,1],[4,5],[3,8]], items2 = [[3,1],[1,5]].  Output: [[1,6],[3,9],[4,5]]
// Explanation: 
//The item with value = 1 occurs in items1 with weight = 1 and in items2 with weight = 5, total weight = 1 + 5 = 6.
//The item with value = 3 occurs in items1 with weight = 8 and in items2 with weight = 1, total weight = 8 + 1 = 9.
//The item with value = 4 occurs in items1 with weight = 5, total weight = 5.  
// Note: you should make your code as generic as possible: the item value may be an integer, but can also be say a char. Weight can be an integer, but can also be a floating point...
// Also, try to use STL algorithm as much as you. This will lead to a program that is shorter...
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
// feel free to change the signature of the following function to make it more generic...

template<class T1, class T2>
void ECMergeSimilarItems(const vector<pair<T1,T2>> &items1, const vector<std::pair<T1,T2>> &items2, vector<std::pair<T1,T2>> &ret)
{
    // Key of map = Value;   Value of map = Weight
    map<int, int> m;

    // Copy Items1 into m
    m.insert(items1.begin(), items1.end());

    // Process each number in items2
    for(auto x : items2) {
        m[x.first] += x.second;
    }

    // Copy m back into ret
    copy(m.begin(), m.end(), back_inserter(ret));
}

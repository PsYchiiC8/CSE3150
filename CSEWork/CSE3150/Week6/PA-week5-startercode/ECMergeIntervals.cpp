// Merge overlapping intervals and return an array of the non-overlapping intervals that cover all the intervals in the input
// Your code must run no slower than O(nlogn) where n is the number of intervals

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void ECMergeIntervals(const std::vector <std::pair<int, int>> &listIntervals,
                      std::vector <std::pair<int, int>> &listNonOverlapIntervals) {
    // your code here...

    if(listIntervals.empty()){
        return;
    }

    vector<std::pair<int, int>> sortedIntervals = listIntervals;
    sort(sortedIntervals.begin(), sortedIntervals.end());

    int start = sortedIntervals[0].first;
    int end = sortedIntervals[0].second;

    for(auto interval : sortedIntervals) {
        if(interval.first <= end){
            end = max(end, interval.second);
        } else{
            listNonOverlapIntervals.push_back(make_pair(start, end));

            start = interval.first;
            end = interval.second;
        }
    }

    listNonOverlapIntervals.push_back(make_pair(start, end));
}

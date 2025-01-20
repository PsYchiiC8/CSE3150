// Created by Y. Wu, Jan 28, 2023
// Enumerate all subsets of a vector of characters which may contain duplicates
// First, a function for counting the number of subsets
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

// (1): counting the number of subsets
int ECSubsetEnumCount(const std::vector<char> &vecChars) {
    // return the number of subsets (without duplicates) of the vector of chars
    // for example, for [a, b, b], return 6: (), (a), (b), (a,b), (b,b), (a,b,b)
    // your code here ...
    unordered_set<char> uniqueChars(vecChars.begin(), vecChars.end());
    int numUniqueChars = uniqueChars.size();

    return 1 << numUniqueChars;
}

// (2): enumerating the subsets, and store the found subsets in setSubsets
// Note: the found subsets can be of any order (but cannot contain duplicates)
// Also note: you should try to make your code as efficient as you can (avoid excessive data copying)

void backtrack(const vector<char>& vecChars, vector<vector<char> >& listSubsets, vector<char>& subset, int start) {
    listSubsets.push_back(subset);

    // Explore all possibilities
    for (int i = start; i < (int)vecChars.size(); ++i) {
        // Skip duplicates
        if (i > start && vecChars[i] == vecChars[i - 1])
            continue;

        // Include the current element
        subset.push_back(vecChars[i]);
        backtrack(vecChars, listSubsets, subset, i + 1);
        subset.pop_back();
    }
}

void ECSubsetEnum(const std::vector<char> &vecChars, std::vector <vector<char> > &listSubsets) {
    // your code here
    vector<char> sortedVecChars = vecChars;
    sort(sortedVecChars.begin(), sortedVecChars.end());

    vector<char> subset;
    backtrack(sortedVecChars, listSubsets, subset, 0);
}

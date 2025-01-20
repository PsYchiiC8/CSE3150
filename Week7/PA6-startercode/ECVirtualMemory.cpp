//
//  ECVirtualMemory.cpp
//
//
//  Created by Yufeng Wu on 8/30/23.
//  Implement popular page replacement algorithms

#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <string>
#include <list>
#include <deque>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include "ECVirtualMemory.h"
using namespace std;

//*****************************************************************************
// Virtual memory: consists of memory pages and a main memory with limited capacity
// Page: represented by an integer; main memory can hold up to K pages
// Page replacement: when the main memory reaches its limit (i.e., having K pages)
// and a new page (not currently in memory) is to be add,
// then need to swap out one current page to make room for this new page
// This class: use OPT or LRU algorithm

// Your code here

ECVirtualMemory::ECVirtualMemory(int capacity) : capacity(capacity), NumPageFaults(0) {}

void ECVirtualMemory::RunLRU(std::vector<int> in_pages, int size, int capacity){
    // Create virtual memory
    NumPageFaults = 0;

    // Now run LRU
    for (int i = 0; i < size; ++i){
        AccessPage(in_pages[i]);
    }
}

void ECVirtualMemory::AccessPage(int page){
    pages.push_back(page);
    auto it = find(Store_Pages.begin(), Store_Pages.end(), page);

    if (it != Store_Pages.end()){
        Store_Pages.erase(it);
    } else {
        NumPageFaults++;
        if (Store_Pages.size() == capacity){
            Store_Pages.pop_back();
        }
    }
    Store_Pages.insert(Store_Pages.begin(), page);
}

bool ECVirtualMemory::search(int target, vector<int> &in_pages){
    for (int i = 0; i < in_pages.size(); i++){
        if (in_pages[i] == target){
            return true;
        }
    }
    return false;
}

int ECVirtualMemory::predict(vector<int> &cache, int index){
    // Store the index of pages which are going
    // to be used recently in future
    int res = -1, farthest = index;
    for (int i = 0; i < cache.size(); i++){
        int j;
        for (j = index; j < pages.size(); j++){
            if (cache[i] == pages[j]){
                if (j > farthest){
                    farthest = j;
                    res = i;
                }
                break;
            }
        }

        // If a page is never referenced in future,
        // return it.
        if (j == pages.size()){
            return i;
        }
    }

    // If all of the frames were not in future,
    // return any of them, we return 0. Otherwise
    // we return res.
    if (res == -1){
        return 0;
    }

    return res;
}

int ECVirtualMemory::RunOpt(){
    vector<int> cache;

    int hits = 0;

    for (int i = 0; i < pages.size(); i++){

        if (search(pages[i], cache)){
            hits++;
            continue;
        }

        if (cache.size() < Store_Pages.size()){
            cache.push_back(pages[i]);
        }
        else {
            int j = predict(cache, (i + 1));
            if (j < cache.size()){
                cache[j] = pages[i];
            }
        }
    }

    return pages.size() - hits;
}

int ECVirtualMemory::GetNumPagesInMainMemory() const {
    return Store_Pages.size();
}

int ECVirtualMemory::GetNumPageFaults() const {
    return NumPageFaults;
}

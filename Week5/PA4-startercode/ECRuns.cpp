//
//  ECRuns.cpp
//  
//
//  Created by Yufeng Wu on 08/22/23.
//
//
#include <string>
#include <iostream>
using namespace std;

// Return the number of runs, and the list of starting positions of runs in the passed in array (which you can assume it is large enough)
int ECRuns(const string &str, int *pListPositions){
    if (str.empty()) {
        return 0; // If the string is empty, there are no runs
    }

    pListPositions[0] = 0;
    int pos = 1;

    for(int i = 1; i < (int)str.length(); i++){
        if(str[i - 1] != str[i]){
            pListPositions[pos] = i;
            pos++;
        }
    }

    return pos;
}


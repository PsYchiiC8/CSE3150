#include <string>
#include <iostream>

// You are given a list of integers listNumbers and its size
// These numbers are the permutation of the first sz integers, starting from 1
// After the function returns, listNumbers would contain the next permutation
// For example, if the list is 1 3 4 2  ==> 1 4 2 3
// Note: you don't need to check whether the given input is indeed a permutation
// That is, listNumbers always contains a valid permutation
void ECNextPermutation(int *listNumbers, int sz) {
    // Your code here
    int i = sz - 2;
    while (i >= 0 && listNumbers[i] >= listNumbers[i + 1]) {
        i--;
    }

    if (i < 0) {
        // Reverse the entire sequence to get the first permutation
        for (int start = 0, end = sz - 1; start < end; start++, end--) {
            int temp = listNumbers[start];
            listNumbers[start] = listNumbers[end];
            listNumbers[end] = temp;
        }
    } else {
        int j = sz - 1;
        while (listNumbers[j] <= listNumbers[i]) {
            j--;
        }

        // Swap listNumbers[i] and listNumbers[j]
        int temp = listNumbers[i];
        listNumbers[i] = listNumbers[j];
        listNumbers[j] = temp;

        // Reverse the sequence to the right of i
        for (int start = i + 1, end = sz - 1; start < end; start++, end--) {
            int temp = listNumbers[start];
            listNumbers[start] = listNumbers[end];
            listNumbers[end] = temp;
        }
    }
}

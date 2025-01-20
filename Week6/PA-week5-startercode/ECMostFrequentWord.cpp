// Created by Y. Wu, Jan 28, 2023
// Given a string, find the most frequent word; if there is a tie, choose alphabetically smallest
// Word: consecutive alphanumerical symbols; that is, treat all non-alphanumerical symbols as separators
// for example, for "I have bad dreams that have bad feelings", return "bad"
#include <string>
#include <iostream>
#include <unordered_map>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

string ECMostFrequentWord(const string &strText) {
    // your code here
    istringstream iss(strText);
    string word;
    unordered_map<string, int> wordFreq;

    // Tokenize the string into words and count frequencies
    while (iss >> word) {
        string cleanWord;
        for (char c : word) {
            if (isalnum(c)) {
                cleanWord += c;
            } else {
                if (!cleanWord.empty()) {
                    wordFreq[cleanWord]++;
                    cleanWord.clear();
                }
            }
        }
        if (!cleanWord.empty()) {
            wordFreq[cleanWord]++;
        }
    }

    // Find the most frequent word(s)
    int maxFreq = 0;
    vector<string> mostFrequentWords;
    for (const auto &entry : wordFreq) {
        if (entry.second > maxFreq) {
            mostFrequentWords.clear(); // Clear previous most frequent words
            mostFrequentWords.push_back(entry.first);
            maxFreq = entry.second;
        } else if (entry.second == maxFreq) {
            mostFrequentWords.push_back(entry.first);
        }
    }

    // Sort the most frequent words alphabetically
    sort(mostFrequentWords.begin(), mostFrequentWords.end());

    // Return the alphabetically smallest word among the most frequent words
    return mostFrequentWords.front();
}


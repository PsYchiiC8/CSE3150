//
//  ParenthesesCheck.cpp
//  
//
//  Created by Yufeng Wu on 11/13/19.
//
//
#include <string>
#include <iostream>
#include <stack>

using namespace std;

// Check if the string has valid nested parentheses
// If so, return true; if not return false; if the string contains
// unexpected symbols, return false
bool ECParentheseCheck(const string &strInput) {
    // your code goes here

    stack<char> parenthesesStack;
    const string brackets = "()[]";

    for (char c: strInput) {
        if (brackets.find(c) != string::npos) {
            if (c == '(' || c == '[') {
                parenthesesStack.push(c);
            } else {
                if (parenthesesStack.empty()) {
                    return false;
                }

                char closingBracket = parenthesesStack.top();
                if ((closingBracket == '(' && c == ']') || (closingBracket == '[' && c == ')')) {
                    return false;
                }

                parenthesesStack.pop();
            }
        }

    }

    // If the stack is empty, all parentheses are matched
    return parenthesesStack.empty();
}
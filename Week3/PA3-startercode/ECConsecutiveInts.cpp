
//
//  ECConsecutiveInts.cpp
//  
//
//  Created by Yufeng Wu on 1/15/23.
//
//

#include <iostream>
#include <string>

using namespace std;

// Test whether strInput is a string composed of consecutive and increasing integers (in decimal formats)
// Return true if yes and false otherwise (return false if there are unexpected characters)
// For example, 1234578 would return false, while 1213141516 would return true (12 13 14 15 16)
// You may assume the integers is at most 999999 and there is no any separators between numbers
// You may also assume integers are all non-negatives

// Tip: try to use library functions instead of writing a lot of code yourself
// functions in C++ string you may find useful:
// substr: extract a substring from a string
// stoi:  convert string to integer (be careful about how to handle exception)
// and so on…

bool ECConsecutiveInts(const string &strInput) {
    // your code  here
    int size = strInput.size();

    int i = 1;

    while(i < size / 2) {
        if(isdigit(strInput[i]) == false){
            return false;
        }
        try {
            string new_str = strInput.substr(0, i);

            int num = stoi(new_str);

            while (new_str.size() < size) {
                num++;
                new_str += to_string(num);
            }

            if (new_str == strInput) {
                return true;
            }
        } catch (const invalid_argument &) {
            return false;
        } catch (const out_of_range &) {
            return false;
        } catch (const exception &) {
            return false;
        }
        i++;
    }

    return false;
}
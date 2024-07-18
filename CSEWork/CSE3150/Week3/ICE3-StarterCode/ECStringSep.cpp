// Starter code
#include <iostream>

using namespace std;

string ECStringSep(const string &str) {
    if(str.length() == 0){
        return string("");
    }

    string res;
    // your code goes here

    res = str[0];

    for(int i = 1; i < (int)str.length(); i++){
        res += ",";
        res += str[i];
    }

    return res;
}


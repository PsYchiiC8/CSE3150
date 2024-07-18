#include <string>

// define a function called ECInverseInt that takes a single parameter (a string) and return a string as its inversed integer
// Your code here
std::string ECInverseInt(const std::string &str) {
    std::string res;
    // find the first non-zero from the right
    bool fNonZero = false;
    for (int i = str.length() - 1; i >= 0; --i) {
        if (str[i] != '0' || fNonZero == true) {
            fNonZero = true;
            res += str[i];
        }
    }
    if (res.length() == 0) {
        res = "0";
    }

    return res;
}

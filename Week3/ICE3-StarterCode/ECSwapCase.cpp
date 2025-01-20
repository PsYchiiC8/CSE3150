#include <iostream>

std::string ECSwapCase(std::string str) {
    std::string res;
    for (unsigned int i = 0; i < str.length(); ++i) {
        if (std::islower(str[i])) {
            res += std::toupper(str[i]);
        } else {
            res += std::tolower(str[i]);
        }
    }
    return res;
}
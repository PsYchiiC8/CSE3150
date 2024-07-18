#include "ECPointerString.h"
#include <iostream>

using namespace std;


ECStringPtr::ECStringPtr() : ptr(NULL) {
    cout << "Default";
}

ECStringPtr::ECStringPtr(const std::string &strInit) : ptr(new string(strInit)) {
    cout << "Custom";
}

ECStringPtr::ECStringPtr(const ECStringPtr &rhs) {
    cout << "Copy";
    if (rhs.ptr != NULL) {
        ptr = new string(*rhs.ptr);
    } else {
        ptr = NULL;
    }

}

ECStringPtr::ECStringPtr(ECStringPtr &&rhs) {
    cout << "Move";
    ptr = rhs.ptr;
    rhs.ptr = NULL;
}


ECStringPtr::~ECStringPtr() {
    delete ptr;
}

ECStringPtr &ECStringPtr::operator=(const ECStringPtr &rhs) {
// YW: is assignment to self a problem?
//cout << "Assignment\n";
    if (&rhs != this) {
        if (rhs.ptr != NULL) {
            SetString(*rhs.GetPtr());
        } else {
            if (ptr != NULL) {
                delete ptr;
            }
            ptr = NULL;
        }
    }
    return *this;
}

void ECStringPtr::SetString(const std::string &strToSet) {
    if (ptr == NULL) {
        ptr = new string(strToSet);
    } else {
        *ptr = strToSet;
    }
}

const std::string *ECStringPtr::GetPtr() const {
    return ptr;
}

std::string ECStringPtr::GetString() const {
    string res;
    if (ptr != NULL) {
        res = *ptr;
    }
    return res;
}

// Skip for the first pass. Create a string by duplicating itself, e.g. if this string is "abc",
// the new string is "abcabc"
ECStringPtr ECStringPtr::Duplicate() const {
    string str = GetString();
    string str2 = str;
    str2 += str;
    ECStringPtr tmp(str2);
    return tmp;
}
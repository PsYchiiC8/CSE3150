
#include "ECLargeInteger.h"
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

ECLargeInteger::ECLargeInteger(int numDigits){
    listDigits.resize(numDigits);
    for(int i = 0; i < numDigits; i++){
        listDigits[i] = 0;
    }
}

ECLargeInteger::ECLargeInteger(const ECLargeInteger &rhs){
    listDigits = rhs.listDigits;
}

ECLargeInteger& ECLargeInteger::operator=(const ECLargeInteger &rhs){
    if(this != &rhs){
        listDigits = rhs.listDigits;
    }
    
    return *this;
}

// basic operations
// Get the digit at a position
// pos: position of the digit. pos=0: most siginficant digit

ECLargeInteger ECLargeInteger::operator+(const ECLargeInteger &rhs) const{
    int len1 = GetLength();
    int len2 = rhs.GetLength();
    int maxLen = std::max(len1, len2) + 1; // Add 1 for potential carry
    ECLargeInteger result(maxLen);

    int carry = 0;
    for (int i = 0; i < maxLen; i++) {
        int sum = carry;
        if (i < len1) {
            sum += listDigits[len1 - 1 - i]; // Access digits from right to left
        }
        if (i < len2) {
            sum += rhs.listDigits[len2 - 1 - i]; // Access digits from right to left
        }
        result.SetDigit(maxLen - 1 - i, sum % 10); // Set the current digit from right to left
        carry = sum / 10; // Update the carry for the next iteration
    }

    // Trim leading zeros
    std::reverse(result.listDigits.begin(), result.listDigits.end());
    while (maxLen > 1 && result.listDigits[maxLen - 1] == 0) {
        maxLen--;
    }
    result.listDigits.resize(maxLen);
    std::reverse(result.listDigits.begin(), result.listDigits.end());
    return result;
}

ECLargeInteger ECLargeInteger::operator-(const ECLargeInteger &rhs) const{
    int len1 = GetLength();
    int len2 = rhs.GetLength();
    int maxLen = std::max(len1, len2);
    ECLargeInteger result(maxLen);

    int borrow = 0;
    for (int i = 0; i < maxLen; i++) {
        int diff = borrow;
        if (i < len1) {
            diff += listDigits[len1 - 1 - i]; // Access digits from right to left
        }
        if (i < len2) {
            diff -= rhs.listDigits[len2 - 1 - i]; // Access digits from right to left
        }
        if (diff < 0) {
            diff += 10;
            borrow = -1;
        } else {
            borrow = 0;
        }
        result.SetDigit(maxLen - 1 - i, diff); // Set the current digit from right to left
    }

    std::reverse(result.listDigits.begin(), result.listDigits.end());
    // Trim leading zeros
    while (maxLen > 1 && result.listDigits[maxLen - 1] == 0) {
        maxLen--;
    }
    result.listDigits.resize(maxLen);
    std::reverse(result.listDigits.begin(), result.listDigits.end());

    return result;
}

ECLargeInteger ECLargeInteger::operator*(const ECLargeInteger &rhs) const{
    int len1 = GetLength();
    int len2 = rhs.GetLength();
    int maxLen = len1 + len2; // Maximum length of the result
    ECLargeInteger result(maxLen); // Initialize result with zeros

    for (int i = 0; i < len1; i++) {
        int carry = 0;
        for (int j = 0; j < len2; j++) {
            int product = listDigits[len1 - 1 - i] * rhs.listDigits[len2 - 1 - j];
            int sum = product + result.listDigits[maxLen - 1 - i - j] + carry;
            result.SetDigit(maxLen - 1 - i - j, sum % 10); // Set the current digit from right to left
            carry = sum / 10; // Update carry
        }
        // Add remaining carry
        result.SetDigit(maxLen - 1 - i - len2, carry);
    }

    std::reverse(result.listDigits.begin(), result.listDigits.end());
    // Trim leading zeros
    while (maxLen > 1 && result.listDigits[maxLen - 1] == 0) {
        maxLen--;
    }
    result.listDigits.resize(maxLen);
    std::reverse(result.listDigits.begin(), result.listDigits.end());

    return result;

}

bool ECLargeInteger::operator>=(const ECLargeInteger& rhs) const{
    // Get the lengths of the two large integers
    int len1 = (*this).GetLength();
    int len2 = rhs.GetLength();

    ECLargeInteger divisor(*this); // Initialize quotient with zeros

    ECLargeInteger dividend(rhs); // Copy of the dividend

    // If the lengths are different, return true if lhs is longer, false otherwise
    if (len1 > len2) {
        return true;
    } else if (len1 < len2) {
        return false;
    }

    // If the lengths are equal, compare the digits one by one
    for (int i = len1 - 1; i >= 0; i--) {
        if (dividend.listDigits[i] > divisor.listDigits[i]) {
            return true;
        } else if (dividend.listDigits[i] < divisor.listDigits[i]) {
            return false;
        }
    }

    // If all digits are equal, return true
    return true;
}


// division: return quotient and remainder (as passed-in parameter)
ECLargeInteger ECLargeInteger::DividedBy(const ECLargeInteger &divisor, ECLargeInteger &remainder) const{
    int len1 = GetLength();
    int len2 = divisor.GetLength();
    int maxLen = len1 - len2 + 1; // Maximum length of the quotient
    ECLargeInteger quotient(maxLen); // Initialize quotient with zeros

    ECLargeInteger temp(*this);
    
    // Perform long division
    int q;

    for (int i = 0; i < maxLen; i++) { // Iterate up to maxLen
        q = 0;
        while (temp >= divisor) {
            temp = temp - divisor;
            q++;
        }

        quotient.SetDigit(i, q);
    }

    remainder = temp; // Set remainder after the loop

    // std::reverse(quotient.listDigits.begin(), quotient.listDigits.end());

    // Trim leading zeros
    while (maxLen > 1 && quotient.listDigits[maxLen - 1] == 0) {
        maxLen--;
    }
    quotient.listDigits.resize(maxLen);

    return quotient;
}

// other operations
void ECLargeInteger::Dump() const{ // for debugging, dump out integer as what people usually do: like 16234 as a string of digits
    for (int i = GetLength() - 1; i >= 0; i--) {
        std::cout << listDigits[i];
    }
    std::cout << std::endl;
}  

// check primality using Fermat's test
// base: Fermat's test base: base^{n-1} mod n = remainder 
// If pRemainder is not NULL, set to the calculated remainder as above (this makes testing a little easier) 
bool ECLargeInteger::operator==(const ECLargeInteger& rhs) const{
    int len1 = GetLength();
    int len2 = rhs.GetLength();

    if (len1 != len2) {
        return false;
    }

    for (int i = 0; i < len1; i++) {
        if (listDigits[i] != rhs.listDigits[i]) {
            return false;
        }
    }

    return true;
}

bool ECLargeInteger::operator>(const ECLargeInteger& rhs) const {
    int len1 = GetLength();
    int len2 = rhs.GetLength();

    if (len1 > len2) {
        return true;
    } else if (len1 < len2) {
        return false;
    }

    for (int i = 0; i < len1; i++) {
        if (listDigits[i] > rhs.listDigits[i]) {
            return true;
        } else if (listDigits[i] < rhs.listDigits[i]) {
            return false;
        }
    }

    return false;
}

ECLargeInteger ECLargeInteger::operator/(const ECLargeInteger &rhs) const {
    ECLargeInteger remainder;
    return DividedBy(rhs, remainder);
}

ECLargeInteger ECLargeInteger::operator%(const ECLargeInteger &rhs) const {
    ECLargeInteger remainder(rhs.GetLength());
    DividedBy(rhs, remainder);
    
    return remainder;
}

ECLargeInteger ECLargeInteger::operator^(const ECLargeInteger &rhs) const {
    ECLargeInteger result(1);
    ECLargeInteger base(*this);
    ECLargeInteger exponent(rhs);

    while (exponent > 0) {
        if (exponent.listDigits[0] % 2 == 1) {
            result = result * base;
        }
        base = base * base;
        exponent = exponent / 2;
    }

    return result;
}

bool ECLargeInteger::FermatTest(const ECLargeInteger &base, ECLargeInteger *pRemainder) const {
    ECLargeInteger exponent(*this);
    exponent = exponent - 1;
    ECLargeInteger remainder(1);

    ECLargeInteger base_copy(base);
    // base_copy = base;

    while (exponent > 1) {
        base_copy = base_copy * base;
        remainder = base_copy % *this;

        base_copy = remainder;

        exponent = exponent - 1;
    }

    if (pRemainder != NULL) {
        *pRemainder = remainder;
    } else {
        pRemainder = &remainder;
    }

    return remainder == 1;
}
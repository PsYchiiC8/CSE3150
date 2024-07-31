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
        listDigits.resize(rhs.GetLength());
        listDigits = rhs.listDigits;
    }
    
    return *this;
}


ECLargeInteger ECLargeInteger::operator^(const ECLargeInteger &rhs) const {
    ECLargeInteger result(GetLength() * rhs.GetLength());

    // Get the size of the larger integer
    int size = std::max(GetLength(), rhs.GetLength());

    // Iterate over each bit
    for (int i = 0; i < size; i++) {
        // XOR the i-th bit of this and rhs and set the result's i-th bit to the result
        bool bit = listDigits[i] ^ rhs.listDigits[i];
        result.SetDigit(i, bit);
    }

    // Return the result
    return result;
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

bool ECLargeInteger::operator>=(const ECLargeInteger& rhs) const {
    // Compare the lengths of the two numbers
    int lhsLength = this->GetLength();
    int rhsLength = rhs.GetLength();

    // More digits means it's greater, fewer digits means it's smaller
    if (lhsLength > rhsLength) {
        return true;
    } else if (lhsLength < rhsLength) {
        return false;
    }

    // If they have the same number of digits, compare digit by digit from the most significant digit
    for (int i = 0; i < lhsLength; i++) {
        int lhsDigit = this->GetDigit(i); // Now directly corresponds to the digit's significance
        int rhsDigit = rhs.GetDigit(i);

        if (lhsDigit > rhsDigit) {
            return true; // LHS digit is greater, so LHS is greater
        } else if (lhsDigit < rhsDigit) {
            return false; // RHS digit is greater, so LHS is not greater or equal
        }
        // If the digits are equal, move to the next less significant digit
    }

    // If all digits are equal, then the numbers are equal
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
    int q = 0;
    while (temp >= divisor) {
        temp = temp - divisor;
        q++;
    }

    quotient.SetDigit(0, q);

    remainder = temp; // Set remainder after the loop

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

ECLargeInteger ECLargeInteger::operator/(const ECLargeInteger &rhs) const {
    ECLargeInteger remainder;
    return DividedBy(rhs, remainder);
}

ECLargeInteger ECLargeInteger::operator%(const ECLargeInteger &rhs) const {
    ECLargeInteger quotient, remainder;
    quotient = this->DividedBy(rhs, remainder);
    return remainder;
}

bool ECLargeInteger::operator<(const ECLargeInteger& rhs) const{
    return !(*this >= rhs);
}

bool ECLargeInteger::operator>(const ECLargeInteger& rhs) const{
    return rhs < *this;

}

bool ECLargeInteger::operator<=(const ECLargeInteger &rhs) const{
    ECLargeInteger divisor(*this); // Initialize quotient with zeros

    ECLargeInteger dividend(rhs); // Copy of the dividend

    // If the lengths are different, return true if lhs is longer, false otherwise
    if (this->GetLength() > rhs.GetLength()) {
        return false;
    } else if (this->GetLength() < rhs.GetLength()) {
        return true;
    }

    // If the lengths are equal, compare the digits one by one
    for (int i = this->GetLength() - 1; i >= 0; i--) {
        if (dividend.listDigits[i] > divisor.listDigits[i]) {
            return false;
        } else if (dividend.listDigits[i] < divisor.listDigits[i]) {
            return true;
        }
    }

    // If all digits are equal, return true
    return true;
}

bool ECLargeInteger::operator!=(const ECLargeInteger& rhs) const{
    if(this->GetLength() != rhs.GetLength()){
        return true;
    }
    else{
        for (int i = 0; i < this->GetLength(); ++i){
            if (this->GetDigit(i) != rhs.GetLength()){
                return true;
            }
        }
    }
    return false; 
}

bool ECLargeInteger::FermatTest(const ECLargeInteger &base, ECLargeInteger *pRemainder) const {
    ECLargeInteger base_copy(base.GetLength());
    base_copy = base;
    
    ECLargeInteger exponent(*this);
    exponent = exponent - 1;

    ECLargeInteger remainder(100);

    while (exponent > 1) {
        base_copy = base_copy * base;
        base_copy = base_copy % *this;

        exponent = exponent - 1;
    }

    if (pRemainder != NULL) {
        *pRemainder = remainder;
    } else {
        pRemainder = new ECLargeInteger(remainder);
    }

    return remainder == 1;
}

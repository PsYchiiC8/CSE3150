#ifndef EC_LARGE_INTEGER
#define EC_LARGE_INTEGER

#include <vector>
#include <cstddef>

// ****************************************************************************
// Large integer: can have hundrends of digits
// Caution: don't include leading zeros (unless it is 1 digit zero)

class ECLargeInteger
{
public:
    // Assume numDigits >= 1
    ECLargeInteger(int numDigits = 1);
    ECLargeInteger(const ECLargeInteger &rhs);
    ECLargeInteger& operator=(const ECLargeInteger &rhs);

    // basic operations
    // Get the digit at a position
    // pos: position of the digit. pos=0: most siginficant digit
    int GetLength() const { return listDigits.size(); }

    void SetDigit(int pos, int digit) { listDigits[pos] = digit; }

    // arithmetic operations: +/-/*.  
    // Your code here
    ECLargeInteger operator+(const ECLargeInteger &rhs) const;
    ECLargeInteger operator-(const ECLargeInteger &rhs) const;
    ECLargeInteger operator*(const ECLargeInteger &rhs) const;
    ECLargeInteger operator/(const ECLargeInteger &rhs) const;
    ECLargeInteger operator%(const ECLargeInteger &rhs) const;
    ECLargeInteger operator^(const ECLargeInteger &rhs) const;

    // division: return quotient and remainder (as passed-in parameter)
    bool operator>=(const ECLargeInteger &rhs) const;
    bool operator==(const ECLargeInteger &rhs) const;
    bool operator<=(const ECLargeInteger &rhs) const;
    bool operator>(const ECLargeInteger &rhs) const;
    bool operator!=(const ECLargeInteger& rhs) const;

    ECLargeInteger power(const ECLargeInteger &a, const ECLargeInteger &b, const ECLargeInteger &n) const;
    ECLargeInteger gcd(const ECLargeInteger &base, const ECLargeInteger &b) const;
    bool operator<(const ECLargeInteger &rhs) const;
    ECLargeInteger DividedBy(const ECLargeInteger &divisor, ECLargeInteger &remainder) const;

    // other operations
    void Dump() const;  // for debugging, dump out integer as what people usually do: like 16234 as a string of digits

    // check primality using Fermat's test
    // base: Fermat's test base: base^{n-1} mod n = remainder 
    // If pRemainder is not NULL, set to the calculated remainder as above (this makes testing a little easier) 
    bool FermatTest(const ECLargeInteger &base, ECLargeInteger *pRemainder = NULL) const;

    int GetDigit(int pos) const { return listDigits[pos]; }

private:
    // your code here
    std::vector<int> listDigits;
};

#endif

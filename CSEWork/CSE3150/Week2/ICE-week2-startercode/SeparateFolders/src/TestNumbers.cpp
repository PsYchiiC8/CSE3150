#include <iostream>
#include "ECNumbers.h"
#include "ECCalculator.h"


int main() {
    using namespace std;
    using namespace ECNumbers;  // Using ECCalculator namespace
    // read in an integer n
    int n = 0;
    cin >> n;

    // print out the square of it
    cout << "Square: " << ECNumbers::ECSquareN(n) << endl;

    // print out 2n
    cout << "2n: " << ECNumbers::ECDoubleN(n) << endl;

    // print out 4 times of n by invoking ECCalculator's function
    cout << "4n: " << ECNumbers::ECFourTimesN(n) << endl;

    return 0;
}

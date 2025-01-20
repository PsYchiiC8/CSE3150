#include <iostream>

using namespace std;

// complete the definition of the sorting function ...
void ECSortFP(int *listNumbers, int size, bool (*function)(int, int)) {
    // your code here
    bool stop = true;
    while (stop == true) {
        stop = false;
        for (int i = 0; i < size - 1; ++i) {
            if (function(listNumbers[i + 1], listNumbers[i])) {
                int temp = listNumbers[i];
                listNumbers[i] = listNumbers[i + 1];
                listNumbers[i + 1] = temp;
                stop = true;
            }

        }
    }
}

bool IsEarlier(int x, int y) {
    // prefer smaller item earlier (standard sorting)
    if (x < y) {
        return true;
    }
    return false;
}

bool IsEarlierReverse(int x, int y) {
    // prefer larger one earlier
    if (x > y) {
        return true;
    }
    return false;
}

bool IsEarlierParity(int x, int y) {
    // put even number earlier; if both are even or both are odd, sort by their values
    if ((x % 2 == 0 && y % 2 == 0) || (x % 2 != 0 && y % 2 != 0)) {
        if (x < y) {
            return true;
        } else {
            return false;
        }
    } else {
        if (x % 2 == 0) {
            return true;
        }
        return false;
    }
}

bool IsEarlierPrime(int x, int y) {
    // put prime numbers earlier, if both are prime or both are not prime, sort by their values
    int prime_x = 1;
    int prime_y = 1;
    for (int i = 2; i < x; ++i) {
        if (x % i == 0) {
            prime_x = 0;
            break;
        }
    }
    for (int i = 2; i < y; ++i) {
        if (y % i == 0) {
            prime_y = 0;
            break;
        }
    }
    if ((prime_x == 1 && prime_y == 1) || (prime_x != 1 && prime_y != 1)) {
        if (x < y) {
            return true;
        } else {
            return false;
        }
    } else {
        if (prime_x == 1) {
            return true;
        }
    }
    return false;
}

// int main()
// {
//   int arr[] = {1,3,2,4};
//   ECSortFP(arr, 4, IsEarlierReverse);

//   // print it out
//   for(int i=0; i<4; ++i)
//   {
//     cout << arr[i] << " ";
//   }
//   cout << endl;
// }

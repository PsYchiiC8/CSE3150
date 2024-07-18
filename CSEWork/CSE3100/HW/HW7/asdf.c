#include <iostream>
#include <vector>
#include <thread>

using namespace std;

// Function to find prime numbers using Sieve of Eratosthenes
void sieveOfEratosthenes(int n) {
    // Create a boolean array "prime[0..n]" and initialize all entries as true.
    vector<bool> prime(n + 1, true);

    for (int p = 2; p * p <= n; p++) {
        // If prime[p] is not changed, it is a prime
        if (prime[p]) {
            // Update all multiples of p
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }

    // Print the prime numbers
    for (int p = 2; p <= n; p++) {
        if (prime[p]) {
            cout << p << " ";
        }
    }
    cout << endl;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "Usage: " << argv[0] << " <number>" << endl;
        return 1;
    }

    int n = atoi(argv[1]);

    if (n <= 1) {
        cout << "Please enter a positive integer greater than 1." << endl;
        return 1;
    }

    // Create a separate thread to find and print prime numbers
    thread primeThread(sieveOfEratosthenes, n);

    // Wait for the thread to finish
    primeThread.join();

    return 0;
}
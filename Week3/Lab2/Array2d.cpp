#include <iostream>

int main() {
    // TODO: Allocate a 2D array (matrix) of size 10 by 10 in the heap.
    int m, n = 10;

    int *arr = new int[m * n];

    // TODO: Initialize the array where arr[i][j] = i+j

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            *(arr + i * 10 + j) = i + j;
        }
    }


    // TODO: Print the matrix elements
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << *(arr + i * 10 + j) << " ";
        }
        std::cout << std::endl;
    }

    // TODO: Make sure to deallocate the 2D-array correctly.

    delete[] arr;

    return 0;
}
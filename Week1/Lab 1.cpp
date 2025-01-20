#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10

// Function to initialize the array with random integers
void initializeArray(int arr[], int size) {
    for(int i = 0; i < size; i++){
        // TODO: Fill in the code to initialize the array with random integers between 1 and 100

        arr[i] = rand() % 100 + 1; // TODO: Generate a random integer between 1 and 100
    }

}

// Function to print the elements of the array
void printArray(int arr[], int size){
    printf("Array elements: ");
    // TODO: Fill in the code to print the elements of the array
    for(int i = 0; i < size; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

// Function to find and return the average of all elements in the array
double calculateAverage(int arr[], int size){
    int sum = 0;
    // TODO: Fill in the code to calculate the sum of all elements in the array

    for(int i = 0; i < size; i++){
        sum = sum + arr[i];
    }

    // TODO: Fill in the code to calculate the average of all elements in the array
    double average = ((double) sum) / ((double) size);

    return average;
}

int main() {
    int myArray[ARRAY_SIZE];

    // Initialize the random seed
    srand(time(NULL));

    // TODO: Call the function to initialize the array
    initializeArray(myArray, ARRAY_SIZE);

    // TODO: Call the function to print the original array
    printArray(myArray, ARRAY_SIZE);

    // TODO: Call the function to calculate and print the average of array elements
    printf("%.2f\n", calculateAverage(myArray, ARRAY_SIZE));

    return 0;
}

#include <iostream>

void InitializeString(char *str, int size) {
    for (int i = 0; i < size; ++i) {
        // TODO: Initialize every character by 'a' + i
        str[i] = 'a' + i;
    }

    // TODO: Print your string
    std::cout << str << std::endl;
}

int main() {
    int myArray[100] = {0};
    for (int i = 0; i < 100; ++i) {
        myArray[i] = i;
    }

    // TODO: Create a pointer to the 50th element in myArray

    int *point = &myArray[50];

    // TODO: Use your pointer to multiply the rest of myArray by 10 (i = 49 to 99)
    // use pointer arithmetic to iterate through myArray
    for (int i = 49; i < 100; i++){
        *point *= 10;
        ++point;
    }

    // TODO: Print all elements of myArray only using the pointer
    point = &myArray[0];
    for (int i = 0; i < 100; i++){
        std::cout << *point << " ";
        ++point;
    }
    std::cout << std::endl;

    // ------------------------------------------------------- //
    // TODO: Create a char pointer to a string of size 10
    // Initialize the string using InitializeString
    char* my_String = new char[10];
    InitializeString(my_String, 10);

    // TODO: Free the memory allocated by your string
    delete[] my_String;

    return 0;
}
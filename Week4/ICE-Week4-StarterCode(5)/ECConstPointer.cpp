#include <iostream>

using namespace std;

int ECSumArray(const int *listNums, int size) {
    // You need to loop through the array using pointer. How to define this pointer?
    const int *px = listNums;
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += *(px++);
    }
    return sum;

}

int main() {
    int array[] = {1, 2, 3, 5};
    int sum = ECSumArray(array, 4);
    cout << "sum: " << sum << "\n";
    return 0;
}

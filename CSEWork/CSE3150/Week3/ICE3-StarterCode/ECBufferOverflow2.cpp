// Can you change the code to use buffer overflow to 
// change the flow control of the code?
#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

int main();

void foo() {
    cout << "Enter foo\n";
    long arr[10];
    int i = 9;
    arr[i + 3] = long(main);
    // sleep for a while
    std::chrono::milliseconds timespan(100); // or whatever
    std::this_thread::sleep_for(timespan);
    cout << "Exit foo\n";

    cout<< "Stack: main address: " << (long)main << endl;
    for(int i = 0; i < 14; i++){
        cout << arr[i] << endl;
    }
}

int main() {
    foo();
    return 0;
}


#include <iostream>
#include <vector>
#include <stack>

// Practice with adapters
// std::stack is an adapter on top of std::vector
// Adapt the given vector into a stack to see how functionality changes
int main() {
    std::vector<int> myVector = {1, 2, 3, 4, 5};

    // Using std::stack as an adapter on top of std::vector
    std::stack<int, std::vector<int>> myStack(myVector);

    std::cout << "Original Vector: ";
    for (const auto &value: myVector) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    std::cout << "Stack (as an adapter on Vector): ";
    while (!myStack.empty()) {
        std::cout << myStack.top() << " ";
        myStack.pop();
    }

     std::cout << std::endl;

    return 0;
}

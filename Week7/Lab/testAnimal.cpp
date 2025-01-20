#include "animal.cpp"

int main() {
    Animal *animalPtr = new Dog("Rex", "Golden Retriever");

    // Call speak() through base pointer (polymorphism)
    std::cout << animalPtr->speak() << std::endl; // Output: Woof!

    // Delete using base pointer (issue occurs)
    delete animalPtr;

    return 0;
}
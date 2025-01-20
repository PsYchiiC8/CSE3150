#include <iostream>
#include <string>

class Animal {
protected:
    std::string name;

public:
    Animal(const std::string &name) : name(name) {}

    ~Animal() { // Non-virtual destructor
        std::cout << "Animal destructor called for: " << name << std::endl;
    }

    virtual std::string speak() const { return "Animal sound"; }
};

class Dog : public Animal {
private:
    std::string breed;

public:
    Dog(const std::string &name, const std::string &breed) : Animal(name), breed(breed) {}

    ~Dog() {
        std::cout << "Dog destructor called for: " << name << std::endl;
    }

    std::string speak() const override { return "Woof!"; }
};
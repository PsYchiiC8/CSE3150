// A simple source file. What is wrong with it?
#include <iostream>
#include "../inc/ECHeader1.h"

int foo(int x){
    return 2 * x;
}

int main()
{
    // do stuff
    std::cout << "foo: " <<  foo(2) << std::endl;

    //to use, need std:: and the function needs to be defined
}

//
//  ParenthesesCheckTest.cpp
//  Test code for parenthesising  
//
//  Created by Yufeng Wu on 08/22/23.
//
//
#include <string>
#include <iostream>
#include <chrono>

using namespace std;

template<class T>
void ASSERT_EQ(T x, T y) {
    if (x == y) {
        cout << "Test passed: equal: " << x << "  " << y << endl;
    } else {
        cout << "Test FAILED: equal: " << x << "  " << y << endl;
    }
}

// to build: c++ ParenthesesCheck.cpp ParenthesesCheckTest.cpp -o test
extern bool ECParentheseCheck(const string &strInput);

static void Test1() {
    string s1 = "()";
    bool f1 = ECParentheseCheck(s1);
    ASSERT_EQ(f1, true);

    string s2 = "()[]";
    bool f2 = ECParentheseCheck(s2);
    ASSERT_EQ(f2, true);

    string s3 = "([)]";
    bool f3 = ECParentheseCheck(s3);
    ASSERT_EQ(f3, false);

    string s4 = "([])";
    bool f4 = ECParentheseCheck(s4);
    ASSERT_EQ(f4, true);
}

static void Test2() {
    string s1 = "(a,a)";
    bool f1 = ECParentheseCheck(s1);
    ASSERT_EQ(f1, true);

    string s3 = "(Madam,I[am)Adam]";
    bool f3 = ECParentheseCheck(s3);
    ASSERT_EQ(f3, false);
}

// A larger data
static void Test3() {
    auto solnStart = std::chrono::high_resolution_clock::now();
    string s1;
    int sz = 2000;
    for (int i = 0; i < sz; ++i) {
        s1 += '(';
        s1 += "STUFF";
        s1 += '[';
    }
    for (int i = 0; i < sz; ++i) {
        s1 += ']';
        s1 += ')';
    }
    bool f1 = ECParentheseCheck(s1);
    ASSERT_EQ(f1, true);

    s1 += ')';
    bool f2 = ECParentheseCheck(s1);
    ASSERT_EQ(f2, false);

    auto solnFinish = std::chrono::high_resolution_clock::now();
    cout << "Run time: "
         << std::chrono::duration_cast<std::chrono::nanoseconds>(solnFinish - solnStart).count() / 1000000000.0
         << " seconds" << endl;

}

int main() {
    Test1();
    Test2();
    Test3();

    return 0;
}

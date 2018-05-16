_Pragma("once")

#include <iostream>
using namespace std;

class Object
{
public:
    virtual void fun() = 0;
};

class Base : public Object {
public:
    void fun() final; // ÉùÃ÷Îªfinal
};

//class Derived : public Base {
//public:
//    void fun();
//};

template <typename T> void TempFunc(T a) {
    cout << a << endl;
}

void DefParam(int m = 3);
template <typename T = int> class DefClass {};
template <typename T = int> void DefTempParam() {};

template <typename T> class X {};
template <typename T> void TempFunc1(T t) {};









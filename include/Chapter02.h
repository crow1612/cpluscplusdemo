#ifndef CHAPTER02_H
#define CHAPTER02_H
#include <iostream>
#include <list>
#include <vector>
#include <deque>
using namespace std;

struct Chp02A {
    Chp02A(int i) { cout << "A(inti)" << endl; }
    Chp02A(double d, int i) { cout << "A(double d, int i)" << endl;}
    Chp02A(float f, int i, const char *c) { cout << "A(float f, int i, const char *c)" << endl; }

    void f(double i) { cout << "f(double i)" << endl;}
};

struct Chp02B2 : Chp02A {
    using Chp02A::Chp02A; //

    virtual void ExtraInterface() {}
    void f(int i) { cout << "f(int i)" << endl;}

    int d {0};
};


struct ConstructA {
    ConstructA() {}
    ConstructA(int);
    };

struct ConstructB {
    ConstructB() {}
    ConstructB(int);
    };

struct ConstructC : ConstructA, ConstructB {
    using ConstructA::ConstructA;
    using ConstructB::ConstructB;
    ConstructC(int);
};

class TDConstructed {
    template<class T> TDConstructed(T first, T last) : l(first, last) {}
    list<int> l;

public:
    TDConstructed(vector<short> & v):
        TDConstructed(v.begin(), v.end()) {}

    TDConstructed(deque<int> & d):
        TDConstructed(d.begin(), d.end()) {}
};

class DCExcept{
public:
    DCExcept(double d)
    try: DCExcept(1, d) {
        cout << "Run the body." << endl;
    }
    catch(...) {
        cout << "caught exception." << endl;
    }

private:
    DCExcept(int i, double d) {
        cout << "going to throw!" << endl;
        //throw 0;
    }
    int type;
    double data;
};










#endif // CHAPTER02_H

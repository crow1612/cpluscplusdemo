#ifndef CHAPTER01_H
#define CHAPTER01_H

#include <iostream>
#include <string>
#include <stdio.h>
#include <climits>
#include <cstdio>
#include <cassert>


//#define UNIT_TEST

using namespace std;

const char * hello();
const char * world();

struct TestStruct {
    TestStruct() : name(__func__) {}
    const char *name;
};

#define LOG(...) {\
    fprintf(stderr, "%s:Line %d:\t", __FILE__, __LINE__); \
    fprintf(stderr, __VA_ARGS__);\
    fprintf(stderr, "\n");\
}

#if __cplusplus < 201103L
    #error "should use C++11 implementation"
#endif // __cplusplus



char *ArrayAlloc(int n);

struct A {
    ~A()  { throw 1; }
};

struct B {
    ~B() noexcept(false) { throw 2;}
};

struct C {
    B b;
};

void funA();
void funB();
void funC();


#endif // CHAPTER01_H

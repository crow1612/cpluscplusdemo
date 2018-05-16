#include "Chapter01.h"

const char * hello() { return __func__; }
const char * world() { return __func__; }

char *ArrayAlloc(int n) {
    assert(n > 0);
    return new char [n];
}

void funA() { A a;}
void funB() { B b;}
void funC() { C c;}

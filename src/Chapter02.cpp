#include "Chapter02.h"


struct A2 {
    A2(int i) {}
    A2(double d, int i) {}
    A2(float f, int i, const char* c) {}
    // ...
};

struct B2 : A2 {
    using A2::A2; // ¼Ì³Ð¹¹Ôìº¯Êý
    // ...
    virtual void ExtraInterface() {}
};

ConstructA::ConstructA(int){
    cout << "ConstructA" << endl;
}

ConstructB::ConstructB(int){
    cout << "ConstructB" << endl;
}

ConstructC::ConstructC(int) {
    cout << "ConstructC" << endl;
}

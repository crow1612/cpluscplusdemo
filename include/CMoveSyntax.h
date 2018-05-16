#ifndef CMOVESYNTAX_H
#define CMOVESYNTAX_H
#include <iostream>
using namespace std;


class HasPtrMem{
public:
    HasPtrMem();
    HasPtrMem(const HasPtrMem & h);
    HasPtrMem(HasPtrMem && h);

    ~HasPtrMem();


    int *d;
    static int n_cstr;
    static int n_dstr;
    static int n_cptr;
    static int n_mvtr;
};

HasPtrMem GetPtrMemTemp();


class Echo {
public:
    Echo() { std::cout << "new Echo()" << std::endl; }
    Echo(const Echo &) { std::cout << "new Echo(const Echo &)" << std::endl; }
    Echo& operator=(const Echo &) { std::cout << "=" << std::endl; }

    Echo(Echo &&) {std::cout << "move Echo(Echo &&)" << std::endl; }
    Echo& operator=(Echo &&) { std::cout << "move Echo& operator=(Echo&&)" << std::endl; }

    ~Echo() { cout << "Destructor! " << hex << this << endl; }
};

void testmove();



struct Copyable{
    Copyable() { cout << "Construct" <<endl;}
    Copyable(const Copyable &o) {
        cout << "Copied" << endl;
    }

    ~Copyable() { cout << "Destructor" << endl; }

    //Copyable(Copyable &&) { cout << "construct rvalue" << endl; }

    void output() const ;
};


Copyable ReturnRvalue();
void AcceptVal(Copyable a);
void AcceptRef(const Copyable& a);
void AcceptRvalueRef(Copyable && s);


class Moveable {
public:
    Moveable() : i(new int(3)) {}
    ~Moveable() { delete i;}
    Moveable(const Moveable & m) : i(new int(*m.i)) {}
    Moveable(Moveable && m) : i(m.i) {
        m.i = nullptr;
    }
    int* i;
};


class HugeMem {
public:
    HugeMem(int size) : sz(size > 0 ? size : 1) {
        c = new int[sz];
    }

    HugeMem() { cout << "HugeMem Construct" << endl; }

    ~HugeMem() { delete [] c; }

    HugeMem(HugeMem && hm) : sz(hm.sz), c(hm.c) {
        hm.c = nullptr;
    }

    int *c;
    int sz;
};

class Moveable2{
public:
    Moveable2();
    ~Moveable2();
    Moveable2(const Moveable2 &m);
    Moveable2(Moveable2 && m);

public:
    int *i;
    HugeMem h;
};


Moveable2 GetTemp2();


struct Maythrow {
    Maythrow() {}
    Maythrow(const Maythrow &) {
        cout << "Maythrow copy constructor." << endl;
    }
    Maythrow(Maythrow &&) {
        cout << "Maythrow move constructor." << endl;
    }
};

struct Nothrow{
    Nothrow() {}
    Nothrow(Nothrow &&) noexcept {
        cout << "Nothrow move constructor." << endl;
    }
    Nothrow(const Nothrow&) {
        cout << "Nothrow move constructor." << endl;
    }
};


void RunCode(int && m);
void RunCode(int & m);
void RunCode(const int && m);
void RunCode(const int & m);

template<typename T>
void PerfectForward(T&& t ) {
    RunCode(forward<T>(t));
}

template<typename T, typename U>
void PerfectForward(T&& t, U& Func) {
    cout << t << "\tforward..." << endl;
    Func(forward<T>(t));
}

void RunCodes(double &&m);
void RunHome(double &&h);
void RunComp(double &&c);

template <typename T>
class Ptr {
public:
    Ptr(T *p) : _p(p) {}
    operator bool() const {
        if (_p != 0)
            return true;
        else
            return false;
    }

private:
    T *_p;
};



class ConvertTo {};
class Convertable {
public:
    explicit operator ConvertTo() const { return ConvertTo();}
};

void FuncConvert(ConvertTo ct);
void Testconvert();




#endif // CMOVESYNTAX_H


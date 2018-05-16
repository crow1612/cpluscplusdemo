#include "CMoveSyntax.h"
#include <vector>
using namespace std;

HasPtrMem::HasPtrMem() : d(new int(0)) {
    cout << "Construct: " << ++n_cstr << endl;
}

HasPtrMem::HasPtrMem(const HasPtrMem & h) : d(new int(*h.d)) {
    cout << "Copy construct: " << ++n_cptr << endl;
}

HasPtrMem::HasPtrMem(HasPtrMem && h) : d(h.d) {
    h.d = nullptr;
    cout << "Move construct: " << ++n_mvtr << endl;
}

HasPtrMem::~HasPtrMem() {
    cout << "Destruct: " << ++n_dstr << endl;
}

HasPtrMem GetPtrMemTemp() {
    HasPtrMem h;
    cout << "Resource from " << __func__ << ": " << hex << h.d << endl;
    return h;
}


int HasPtrMem::n_cstr = 0;
int HasPtrMem::n_dstr = 0;
int HasPtrMem::n_cptr = 0;
int HasPtrMem::n_mvtr = 0;


void testmove() {
    vector<Echo> v1, v2;

    v1.resize(5);

    cout << v1.size() << " " << v2.size() << std::endl;
//    swap(v1, v2);
    v2 = v1;
//    v2 = std::move(v1); // 相对于v2 = v1，使用std::move(v1),减少了vector的拷贝次数，从而提高代码效率
    cout << v1.size() << " " << v2.size() << std::endl;
}

Copyable ReturnRvalue() {
    return Copyable();
}


void AcceptVal(Copyable a) {
    //Copyable news = a;
}
void AcceptRef(const Copyable& a)  {
    //Copyable news = a;
}

void AcceptRvalueRef(Copyable && s) {
    Copyable news = std::move(s); // 强制将左值转化为右值
}
void Copyable::output() const  {
    cout << "output" << endl;
}


Moveable2 GetTemp2() {
    Moveable2 tmp = Moveable2();
    cout << hex << "Huge Mem from " << __func__
         << " @" << tmp.h.c << endl;

    return tmp;
}


Moveable2::Moveable2() : i(new int(3)), h(1024) {
    cout << "Moveable2 Construct" << endl;
}

Moveable2::~Moveable2() {
    delete i;
}

Moveable2::Moveable2(Moveable2 && m) : i(m.i), h(move(m.h)) { // 强制转为右值，以调用移动构造函数
    cout << "Moveable2(Moveable2 && m)" << endl;
    m.i = nullptr;
}

Moveable2::Moveable2(const Moveable2 &m)  {
    cout << "Moveable2 Copy Construct" << endl;
}

void RunCode(int && m) {
    cout << "rvalue ref" << endl;
}

void RunCode(int & m) {
    cout << "lvalue ref" << endl;
}

void RunCode(const int && m) {
    cout << "const rvalue ref" << endl;
}

void RunCode(const int & m) {
    cout << "const lvalue ref" << endl;
}

void RunCodes(double &&m) {}
void RunHome(double &&h) {}
void RunComp(double &&c) {}

void FuncConvert(ConvertTo ct) {}
void Testconvert() {
    Convertable c;
    ConvertTo ct(c);
//    ConvertTo ct2 = c;
    ConvertTo ct3 = static_cast<ConvertTo>(c);
    FuncConvert(c);
}



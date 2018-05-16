#include "Friend.h"
#include "Final.h"
#include "Chapter01.h"
#include "Chapter02.h"
#include "Chapter02.h"
#include "CMoveSyntax.h"
#include <iostream>
#include <vector>
using namespace std;

#define UNIT_TEST
#ifdef UNIT_TEST



int main()
{
    // TODO:
    // 深入理解C++11——第三章
//    Chp02B2 chp(1);
//    DCExcept da(1.2);

//    HasPtrMem ptrMem(GetPtrMemTemp());
//    cout << "Resource from " << __func__ << ": " << hex << ptrMem.d << endl;
//    cout << "C++ __cplusplus value is: " << __cplusplus << endl;


//  demo 002
    std::string str = "Hello";
    std::vector<std::string> v;
    //调用常规的拷贝构造函数，新建字符数组，拷贝数据
    v.push_back(str);
    std::cout << "After copy, str is \"" << str << "\"\n";
    //调用移动构造函数，掏空str，掏空后，最好不要使用str
    v.push_back(std::move(str));
    std::cout << "After move, str is \"" << str << "\"\n";
    std::cout << "The contents of the vector are \"" << v[0]
                                         << "\", \"" << v[1] << "\"\n";




    cout << "Pass by value: " << endl;
    AcceptVal(ReturnRvalue()); // 临时值被拷贝传入
    cout << "Pass by reference: " << endl;
    AcceptRef(ReturnRvalue()); // 临时值被作为引用传递
    cout << "Pass by rvalue ref: " << endl;
    AcceptRvalueRef(ReturnRvalue());

    if (is_rvalue_reference<string &>::value) {
        cout << "is rvalue_reference" << endl;
    } else {
        cout << "is not rvalue reference" << endl;
    }

    cout << "moveable" << endl;
    Moveable moveableA;

    Moveable moveableC(move(moveableA));
    // crash
    //cout << *moveableA.i << endl;

    cout << "For moveable2" << endl;
    Moveable2 a(move(GetTemp2()));
    cout << hex << "Huge Mem from " << __func__ << " @" << a.h.c << endl;


    cout << "\nFor move_if_noexcept" << endl;
    Maythrow m;
    Nothrow n;

    Maythrow mt = move_if_noexcept(m);
    Nothrow nt = move_if_noexcept(n);

    cout << "\nFor forward" << endl;

    int pfa;
    int pfb;
    const int pfc = 1;
    const int pfd = 0;

    PerfectForward(pfa);
    PerfectForward(move(pfb));
    PerfectForward(pfc);
    PerfectForward(move(pfd));

    cout << "\npf" << endl;
    PerfectForward(1.5, RunComp);
    PerfectForward(8, RunComp);
    PerfectForward(1.5, RunComp);

    cout << "\n Explicit Construct" << endl;
    int exa;
    Ptr<int> exp(&exa);

    if (exp)
        cout << "valid pointer" << endl;
    else
        cout << "invalid pointer" << endl;

    Ptr<double> expd(0);
    cout << exp << " - " << expd << endl;

//     demo001
//    int a = 1;
//    int &rb = a + 1;
//
//    testmove();
//    Echo echoa, echob;
//    std::swap(echoa, echob);
    return 0;


//    // 深入理解C++11——第二章:保证C++的稳定性以及兼容性
//    int a = 1;
//    auto b = a;
//    cout << b << endl;
//    cout << "Standard Clib: " << __STDC_HOSTED__ << endl;
//    cout << "Standard C: " << __STDC__ << endl;
//    cout << hello() << ", " << world() << endl;
//
//    cout << "C++ __cplusplus value is: " << __cplusplus << endl;
//
//    TestStruct ts;
//    cout << ts.name << endl;
//
//    int x = 3;
//    LOG("x=%d", x);
//
//
//    long long ll_min = LLONG_MIN;
//    long long ll_max = LLONG_MAX;
//    unsigned long long ull_max = ULLONG_MAX;
//
//    printf("min of long long: %lld \n", ll_min);
//    printf("max of long long: %lld \n", ll_max);
//    printf("max of unsigned long long: %llu \n", ull_max);
//
//    cout << sizeof(long long) << endl;
//
//
//    ArrayAlloc(1);
//
//    //// noexcept
//    try {
//        funB();
//    }
//    catch(...) {
//        cout << "caught funB." << endl; // caught funB
//    }
//
//    try {
//        funC();
//    }
//    catch(...) {
//        cout << "caught funC." << endl; // caught funC
//    }
//
////    try {
////        funA();
////    }
////    catch (...) {
////        cout << "caught funA." << endl;
////    }
//
//
//    People<Poly> PeopleP; // 类型P在这里是People类型的友元
//    People<int> Peoplei; // 对于int类型模板参数，友元声明被忽略
//
//
//    TempFunc(1); // 实例化为TempFunc<const int>(1)
//    TempFunc("1"); // 实例化为TempFunc<const char *>(1)
//
//    DefenderTest def;
//    AttackerTest att;
//    att.Move(15, 30);
//    def.Defence(15, 30);
//    att.SpeedUp(1.5f);
//    def.Defence(15, 30);
//
//    Validator v;
//    v.Validate(7, 0, def);
//    v.Validate(1, -10, att);

    return 0;
}

#endif // UINT_TEST


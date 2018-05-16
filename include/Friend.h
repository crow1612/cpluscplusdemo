_Pragma("once");


class Poly;
typedef Poly P;

class LiLei {
    friend class Poly;
};

class Jim {
    friend Poly;
};

class HanMeiMei {
    friend P;
};

// 程序员可以为类模板声明友元啦。friend不再需要使用class，甚至直接用别名P


template<typename T> class People {
    friend T;
};



// 在模板实例化时可确定一个IE模板是否含有友元，使用该特征是很有好处的。

template <typename T> class DefenderT {
public:
    friend T;
    void Defence(int x, int y) {}
    void Attack(int x, int y) {}

private:
    int pox_x = 15;
    int pos_y = 0;
    int speed = 2;
    int stamina = 120;
};

template <typename T> class AttackerT {
public:
    friend T;
    void Move(int x, int y) {}
    void SpeedUp(float ratio) {}

private:
    int pos_x = 0;
    int pos_y = -30;
    int speed = 3;
    int stamina = 100;
};

using Defender = DefenderT<int>;
using Attacker = AttackerT<int>;

class Validator;
using DefenderTest = DefenderT<Validator>; // 测试专用的定义，Validator类成为友元
using AttackerTest = AttackerT<Validator>;

class Validator {
public:
    void Validate(int x, int y, DefenderTest &d) {}
    void Validate(int x, int y, AttackerTest &a) {}
};



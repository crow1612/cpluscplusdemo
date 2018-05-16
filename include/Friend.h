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

// ����Ա����Ϊ��ģ��������Ԫ����friend������Ҫʹ��class������ֱ���ñ���P


template<typename T> class People {
    friend T;
};



// ��ģ��ʵ����ʱ��ȷ��һ��IEģ���Ƿ�����Ԫ��ʹ�ø������Ǻ��кô��ġ�

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
using DefenderTest = DefenderT<Validator>; // ����ר�õĶ��壬Validator���Ϊ��Ԫ
using AttackerTest = AttackerT<Validator>;

class Validator {
public:
    void Validate(int x, int y, DefenderTest &d) {}
    void Validate(int x, int y, AttackerTest &a) {}
};



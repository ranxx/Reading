#include <iostream>

template<typename T>
class Singleton {

private:
    // 私有化构造
    Singleton(){};
    // 私有化对象构造
    Singleton(const Singleton&);
    // 私有化赋值构造
    Singleton& operator=(const Singleton&);

    // static T * m_Instance;
public:
    static T* GetInstance(){
        // if (m_Instance == NULL) {
        //     m_Instance = new T();
        // }
        static T m_Instance;
        return &m_Instance;
    }
    static void Echo() {
        // std::cout << m_Instance << std::endl;
    }
};

// Singleton *Singleton::m_Instance = new Singleton();

// class Test : public Singleton<Test> {
//     friend class Singleton<Test>;
// public:
//     Test(){};
//     Test(const Test&);
//     Test& operator=(const Test&);
//     Say(){};
// };

class test {
public:
    test(){};
    say(){};
};



int main(int argc, char **argv) {

    // Singleton *p1 = Singleton::GetInstance();
    // Singleton *p2 = Singleton::GetInstance();
    // Singleton *p3 = Singleton::GetInstance();
    // Singleton *p4 = Singleton::GetInstance();


    // p1->Echo();
    // p2->Echo();
    // p3->Echo();
    // p4->Echo();
    test *p = Singleton<test>::GetInstance();
    p->say();


    return 0;
}
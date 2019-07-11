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
public:
    static T* GetInstance(){
        static T m_Instance;
        return &m_Instance;
    }
};

class test1 {
public:
    void Echo() {
        std::cout << this << std::endl;
    }
};

class test2 {
public:
    void Echo() {
        std::cout << this << std::endl;
    }
};

int main(int argc, char **argv) {

    Singleton<test1>::GetInstance()->Echo();
    Singleton<test1>::GetInstance()->Echo();
    Singleton<test2>::GetInstance()->Echo();
    Singleton<test2>::GetInstance()->Echo();

    return 0;
}
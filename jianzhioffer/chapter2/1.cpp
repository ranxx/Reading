#include <iostream>
#include <string>

class CMyString{

public:
    CMyString(char*pDate=nullptr) {
        if (!pDate) {
            m_pData = NULL;
            return;
        } 
        m_pData = new char[strlen(pDate) + 1];
        strcpy(m_pData, pDate);
    }
    CMyString(const CMyString& str){
        if (!str.m_pData) {
            m_pData = NULL;
            return;
        }
        m_pData = new char[strlen(str.m_pData) + 1];
        strcpy(m_pData, str.m_pData);
    }
    CMyString(const std::string& str){
        if (!str.size()) {
            m_pData = NULL;
            return;
        }
        m_pData = new char[str.size() + 1];
        strcpy(m_pData, str.c_str());
    }
    ~CMyString(void){
        if (m_pData != NULL) {
            std::cout << "我析构了 "<< *this << std::endl;
            delete[] m_pData;
        }
    }
    CMyString& operator=(const CMyString& str) {
        if (this != &str) {
            // 异常安全性
            CMyString tmp(str);
            char *p = tmp.m_pData;
            tmp.m_pData = this->m_pData;
            this->m_pData = p;
        }
        return *this;
    }
    friend std::ostream& operator<<(std::ostream& out, const CMyString &str) {
        out << str.m_pData << " ";
        return out;
    }
private:
    char *m_pData;
};

int main(int argc, char **argv) {

    CMyString str1(std::string("hello world"));
    CMyString str2(str1);
    CMyString str3(str2);
    str1 = str2 = str1;

    return 0;
}
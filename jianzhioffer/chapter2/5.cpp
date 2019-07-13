#include <iostream>

/*
    请实现一个函数, 把字符串中的每一个空格替换成"%20".
    例如输入 "We are happy.", 则输出 "We%20are%20happy.".
*/

#ifndef PARAMS
#define PARAMS int argc, char ** argv
#endif


char* replaceSpace(std::string str) {
    
    int space = 0;
    for (int i = 0 ;i < str.length(); ++i) {
        if (str[i] == ' '){
            ++space;
        }
    }
    
    std::cout << "len(" << str <<"):" << str.length() << std::endl;

    char *p = new char[space + str.length()];
    char *tmp = p;
    for (int i = 0 ;i < str.length(); ++i) {
        if (str[i] == ' '){
            *tmp++ = '%';
            *tmp++ = '2';
            *tmp++ = '0';
        }else{
            *tmp++ = str[i];
        }
    }
    *tmp = '\0';
    return p;
}

int main(PARAMS) {

    std::cout << replaceSpace("We are happy.") << std::endl;
    std::cout << replaceSpace(" ") << std::endl;

    std::cout << std::string(replaceSpace("We are happy.")).length() << std::endl;
    std::cout << std::string(replaceSpace(" ")).length() << std::endl;

    return 0;
}
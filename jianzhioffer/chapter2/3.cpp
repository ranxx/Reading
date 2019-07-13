#include <iostream>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

// 0 ~ n-1
int duplicate(int str[], int len) {
    if (str == nullptr || len <= 0 ) {
        return -1;
    }
    for (int i = 0; i < len; ++i) {
        if (str[i] < 0 || str[i] > len-1) {
            return -1;
        }
    }
    for (int i = 0; i < len; ++i) {
        while (str[i] != i){
            if (str[str[i]] == str[i]) {
                return str[i];
            }
            swap(str[i], str[str[i]]);
        }
    }
    return -1;
}

int duplicateNumberUseMap(int str[], int len) {
    map<int, bool> items;
    for (int i = 0; i < len; ++i) {
        if (items[str[i]]) {
            return str[i];
        }
        items[str[i]] = true;
    }
    return -1;
}

int main() {

    int stra[] = {1, 2, 3, 4, 7, 9, 0, 0, 8, 10, 5};
    std::cout << "str长度: " << sizeof(stra)/sizeof(stra[0]) << "\t重复了: " << duplicateNumberUseMap(stra, sizeof(stra)/sizeof(stra[0])) << std::endl;
    std::cout << "str长度: " << sizeof(stra)/sizeof(stra[0]) << "\t重复了: " << duplicate(stra, sizeof(stra)/sizeof(stra[0])) << std::endl;

    return 0;
}
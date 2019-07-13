#include <iostream>

/*
    在一个二维数组中, 每-行都按照从左到右递增的顺序排序,
    每一行都按照从上到下递增的顺序排序. 请完成一个函数, 输入这样的-个
    二维数组和一个整数, 判断数组中是否含有该整数.

*/

class solution {
private:
    int **items;
    int row, col;
public:
    solution(int row, int col):row(row),col(col) {
        items = new int*[row];
        for (int i = 0; i < col; ++i) {
            items[i] = new int[row];
        }
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                items[i][j] = i * col + j + 2 * (i + + j + 1);
            }
        }
    }
    ~solution(){
        for (int i = 0; i < row; ++i) {
            delete[] items[i];
        }
    }
    void show() {
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                std::cout << items[i][j] << "\t"; 
            }
            std::cout << std::endl;
        }
    }

    bool contains(int num) {
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (items[i][j] == num) {
                    return true;
                }
            }
        }
        return false;
    }
    
    // 从右上角开始
    bool containsV2(int num) {
        for (int i = 0, j = col -1; i < row && j >= 0; ) {
            if (items[i][j] > num) {
                --j;
            }else if (items[i][j] < num) {
                ++i;
            }else{
                return true;
            }
        }
        return false;
    }

    // 从左下角开始
    bool containsV3(int num) {
        for (int i = row -1, j = 0; i >= 0 && j < col; ) {
            if (items[i][j] > num) {
                --i;
            }else if (items[i][j] < num) {
                ++j;
            }else{
                return true;
            }
        }
        return false;
    }
};

int main(int argc, char ** argv) {
    int row = 5, col = 6;
    solution sol(row, col);
    
    sol.show();

    int num = 20;
    std::cout << "contain " << num << ": " << (sol.contains(num) ? "true" : "false") << std::endl;
    num = 15;
    std::cout << "contain " << num << ": " << (sol.contains(num) ? "true" : "false") << std::endl;
    num = 8;
    std::cout << "contain " << num << ": " << (sol.containsV2(num) ? "true" : "false") << std::endl;

    num = 0;
    std::cout << "contain " << num << ": " << (sol.containsV2(num) ? "true" : "false") << std::endl;

    num = 11;
    std::cout << "contain " << num << ": " << (sol.containsV2(num) ? "true" : "false") << std::endl;

    num = 2;
    std::cout << "contain " << num << ": " << (sol.containsV3(num) ? "true" : "false") << std::endl;

    num = 49;
    std::cout << "contain " << num << ": " << (sol.containsV3(num) ? "true" : "false") << std::endl;

    return 0;
}
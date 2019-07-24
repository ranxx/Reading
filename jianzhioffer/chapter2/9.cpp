#include <iostream>
#include <stack>

/*
    用两个栈实现一个队列. 队列的声明如下, 请实现它的两个函数 appendTail 和 deleteHead, 分别完成在
    队列尾部插入节点和队头删除节点的功能
*/

#ifndef PARAMS
#define PARAMS int argc, char ** argv
#endif

#define SIZE(a) (sizeof(a) / sizeof(a[0]))

template <typename T>
class CQueue {

public:
    CQueue(void) {}
    ~CQueue(void) {}

    void appendTail(const T&node) {
        stack1.push(node);
    }

    T deleteHead() {
        if (stack2.empty()) {
            while (!stack1.empty()){
               stack2.push( stack1.top());
               stack1.pop();
            }
        }

        T tmp;
        if (!stack2.empty()) {
            tmp = stack2.top();
            stack2.pop();
        }
        return tmp;
    }

    int size() {
        return stack1.size() + stack2.size();
    }

private:
    std::stack<T> stack1;
    std::stack<T> stack2;
};

int main(PARAMS) {

    CQueue<int> queue;
    for (int i = 0; i < 5; ++i) {
        queue.appendTail(i);
    }

    while (queue.size()){
        std::cout << queue.deleteHead() << " ";
    }

    for (int i = 0; i < 5; ++i) {
        queue.appendTail(i);
    }

    while (queue.size()){
        std::cout << queue.deleteHead() << " ";
    }

    std::cout << std::endl;

    std::cout << queue.deleteHead() << std::endl;

    return 0;
}
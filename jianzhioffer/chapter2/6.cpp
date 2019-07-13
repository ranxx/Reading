#include <iostream>
#include <deque>

/*
    输入一个链表的头结点, 从尾到头反过来打印出每个节点的值
    结构如下:
    struct ListNode {
        int  m_nKey;
        ListNode * m_pNext;
    }
*/

#ifndef PARAMS
#define PARAMS int argc, char ** argv
#endif

struct ListNode {
    int  m_nKey;
    ListNode * m_pNext;
};

ListNode* generate(int arr[], int len) {
    ListNode *head = new ListNode;
    head->m_pNext = NULL;
    ListNode *tmp = head;
    for (int i = 0; i < len; ++i) {
        tmp->m_pNext = new ListNode;
        tmp = tmp->m_pNext;
        tmp->m_nKey = arr[i];
        tmp->m_pNext = NULL;
    }
    tmp = head->m_pNext;
    delete head;
    return tmp;
}

void display(ListNode*head) {
    while (head){
        std::cout << head->m_nKey << std::endl;
        head = head->m_pNext;
    }
}

void reversedisplay(ListNode*head) {
    if (!head) {
        return;
    }
    reversedisplay(head->m_pNext);
    std::cout << head->m_nKey << std::endl;
}

void reversedisplayV2(ListNode*head) {
    std::deque<ListNode*> q;
    while (head){
        q.push_back(head);
        head = head->m_pNext;
    }
    while (!q.empty()){
        head = q.back();
        q.pop_back();
        std::cout << head->m_nKey << std::endl;
    }
}

void destroy(ListNode * head) {
    ListNode * tmp = head;
    while (head){
        tmp = head->m_pNext;
        delete head;
        head = tmp;
    }
}

int main(PARAMS) {

    int arr[] = {1, 2, 3, 6};
    ListNode * head = generate(arr, sizeof(arr) / sizeof(arr[0]));
    std::cout << "display:" << std::endl;
    display(head);
    std::cout << "reversedisplay:" << std::endl;
    reversedisplay(head);
    std::cout << "reversedisplayV2:" << std::endl;
    reversedisplayV2(head);

    destroy(head);

    return 0;
}
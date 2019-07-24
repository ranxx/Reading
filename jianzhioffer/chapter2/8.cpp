#include <iostream>

/*
    给定一个二叉树和其中的一个节点, 如何找出中序遍历序列的下一个节点?
    树中的节点除了有两个分别指向左, 右子节点的指针, 还有一个指向父节点的指针
*/

#ifndef PARAMS
#define PARAMS int argc, char ** argv
#endif

#define SIZE(a) (sizeof(a) / sizeof(a[0]))

struct BinaryTree {
    char Value;
    BinaryTree *Left, *Right, *Parent;
    BinaryTree(char value, BinaryTree *left, BinaryTree *right, BinaryTree *parent):Value(value),Left(left),Right(right),Parent(parent) {}
};

BinaryTree* GetNext(BinaryTree * node) {
    if (!node) {
        return NULL;
    }

    // 有右节点
    if (node->Right) {
        BinaryTree * tmp = node->Right;
        while (tmp->Left){
            tmp = tmp->Left;
        }
        return tmp;
    }

    // 没有右节点, 并且是父亲节点的左节点
    if (node->Parent && !node->Right && node->Parent->Left == node) {
       return node->Parent;
    }

    // 没有右节点, 并且是父亲节点的右节点
     if (node->Parent && !node->Right && node->Parent->Right == node) {
        BinaryTree * tmp = node->Parent;
        while (tmp->Parent && tmp->Parent->Right == tmp){
            tmp = tmp->Parent;
        }
        return tmp->Parent;
    }

    return NULL;
}

// 中序
void Inorder(BinaryTree *root) {
    if (!root) {
        return;
    }

    Inorder(root->Left);
    std::cout << root->Value << " ";
    Inorder(root->Right);
}

int main(PARAMS) {

    BinaryTree a = BinaryTree('a', NULL, NULL, NULL);
    BinaryTree b = BinaryTree('b', NULL, NULL, &a);
    BinaryTree c = BinaryTree('c', NULL, NULL, &a);
    BinaryTree d = BinaryTree('d', NULL, NULL, &b);
    BinaryTree e = BinaryTree('e', NULL, NULL, &b);
    BinaryTree f = BinaryTree('f', NULL, NULL, &c);
    BinaryTree g = BinaryTree('g', NULL, NULL, &c);
    BinaryTree h = BinaryTree('h', NULL, NULL, &e);
    BinaryTree i = BinaryTree('i', NULL, NULL, &e);

    a.Left = &b;
    a.Right = &c;

    b.Left = &d;
    b.Right = &e;

    c.Left = &f;
    c.Right = &g;

    e.Left = &h;
    e.Right = &i;

    Inorder(&a);
    std::cout << std::endl;

    BinaryTree *fund = &a;
    BinaryTree *p = GetNext(fund);
    if (p) {
        std::cout << fund->Value << " -> " << p->Value << std::endl;
    }

    return 0;
}
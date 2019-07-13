#include <iostream>
#include <exception>
#include <string>

/*
    输入某二叉树的前序遍历和中序遍历的结果, 请重建该二叉树. 
    假设输入的前序遍历和中序遍历的结果中都不包含重复的数字. 例如, 输入
    前序遍历{1,2,4,7,3,5,6,8}和中序遍历{4,7,2,1,5,3,8,6}, 则
    重建如图 2.6 所示的二叉树并输出它的头结点. 二叉树节点的定义如下:
    struct BinaryTreeNode {
        int m_nValue;
        BinaryTreeNode* m_pLeft, m_pRight;
    };
*/


#ifndef PARAMS
#define PARAMS int argc, char ** argv
#endif

#define SIZE(a) (sizeof(a) / sizeof(a[0]))

struct BinaryTreeNode {
    int             m_nValue;
    BinaryTreeNode  *m_pLeft, *m_pRight;
};

void destroy(BinaryTreeNode *root) {
    if (!root) {
        return ;
    }
    destroy(root->m_pLeft);
    destroy(root->m_pRight);
    std::cout << "delete => " << root->m_nValue << std::endl;
    delete root;
}

void preorder(BinaryTreeNode *root) {
    if (!root) {
        return ;
    }
    std::cout << root->m_nValue << ", ";
    preorder(root->m_pLeft);
    preorder(root->m_pRight);
}

void inorder(BinaryTreeNode *root) {
    if (!root) {
        return ;
    }
    inorder(root->m_pLeft);
    std::cout << root->m_nValue << ", ";
    inorder(root->m_pRight);
}

BinaryTreeNode* constructCore(int *startPreorder, int *endPreorder, int *startInorder, int *endInorder) {
    
    int rootValue = startPreorder[0];
    BinaryTreeNode *root = new BinaryTreeNode;
    root->m_nValue = rootValue;
    root->m_pLeft = root->m_pRight = NULL;

    if (startPreorder == endPreorder) {
        if (startInorder == endInorder && *startInorder == *endInorder) {
            return root;
        }
        std::cout << "Invalid input!";
        return NULL;
    }

    int *inorderRoot = startInorder;
    while (inorderRoot <= endInorder && *inorderRoot != rootValue) {
        ++inorderRoot;
    }

    if (inorderRoot == endInorder && *inorderRoot != rootValue) {
        std::cout << "Invalid input!";
        return NULL;
    }

    int leftLen = inorderRoot - startInorder;
    if (leftLen > 0) {
        root->m_pLeft = constructCore(startPreorder + 1, startPreorder + leftLen, startInorder, inorderRoot -1);
    }
    if (endInorder - inorderRoot > 0) {
        root->m_pRight = constructCore(startPreorder + leftLen + 1, endPreorder, inorderRoot + 1, endInorder);
    }

    return root;
}

BinaryTreeNode* construct(int preorder[], int inorder[], int len) {
    if (preorder == NULL || inorder == NULL || len <= 0) {
        return NULL;
    }
    return constructCore(preorder, preorder + len - 1, inorder, inorder + len - 1);
}



int main(PARAMS) {

    int preorderArray[] = {1, 2, 4, 7, 3, 5, 6 ,8};
    int inorderArray[] = {4, 7, 2, 1, 5, 3, 8, 6};
    BinaryTreeNode *root = construct(preorderArray, inorderArray , SIZE(preorderArray));
    preorder(root);
    std::cout << std::endl;
    inorder(root);
    std::cout << std::endl;
    destroy(root);


    int one[] = {1};
    root = construct(one, one, 1);
    preorder(root);
    std::cout << std::endl;
    inorder(root);
    std::cout << std::endl;
    destroy(root);

    int zero[] = {};
    root = construct(zero, zero, 0);
    preorder(root);
    std::cout << std::endl;
    inorder(root);
    std::cout << std::endl;
    destroy(root);

    return 0;
}
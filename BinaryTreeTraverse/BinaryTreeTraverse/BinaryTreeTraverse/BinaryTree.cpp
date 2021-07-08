#include <iostream>
#include "BinaryTree.h"
using namespace std;
typedef int BTData;

BTreeNode* MakeBTreeNode()
{
    BTreeNode* nd = new BTreeNode;

    nd->left = NULL;
    nd->right = NULL;
    return nd;
}


int GetData(BTreeNode* main)
{
    return main->data;
}

BTreeNode* GetLeftSubTree(BTreeNode* main)
{
    return main->left;
}

BTreeNode* GetRightSubTree(BTreeNode* main)
{
    return main->left;
}



void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub)
{
    if (main->left != NULL)
        delete main->left;

    main->left = sub;
}

void MakeRightSubTree(BTreeNode* main, BTreeNode* sub)
{
    if (main->right != NULL)
        delete main->right;

    main->right = sub;
}

void SetData(BTreeNode* bt, BTData data)
{
    bt->data = data;
}


void DeleteBTreeNode(BTreeNode* bt)
{
    delete bt;
}

void PreorderTraverse(BTreeNode* bt)
{
    if (bt == NULL)
        return;

    cout << bt->data << endl;
    PreorderTraverse(bt->left);
    PreorderTraverse(bt->right);
}

void InorderTraverse(BTreeNode* bt)
{
    if (bt == NULL)
        return;

    InorderTraverse(bt->left);
    cout << bt->data << endl;
    InorderTraverse(bt->right);
}

void PostorderTraverse(BTreeNode* bt)
{
    if (bt == NULL)
        return;

    PostorderTraverse(bt->left);
    InorderTraverse(bt->right);
    cout << bt->data << endl;
}
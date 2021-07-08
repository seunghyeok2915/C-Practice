#pragma once

typedef int BTData;

typedef struct _bTreeNode
{
    BTData data;
    struct _bTreeNode* left;
    struct _bTreeNode* right;
}BTreeNode;

int GetData(BTreeNode* main);

BTreeNode* GetLeftSubTree(BTreeNode* main);

BTreeNode* GetRightSubTree(BTreeNode* main);

void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub);

void MakeRightSubTree(BTreeNode* main, BTreeNode* sub);

void SetData(BTreeNode* bt, BTData data);

BTreeNode* MakeBTreeNode();

void DeleteBTreeNode(BTreeNode* bt);

void PreorderTraverse(BTreeNode* bt);
void InorderTraverse(BTreeNode* bt);
void PostorderTraverse(BTreeNode* bt);

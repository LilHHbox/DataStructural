#pragma once

typedef int ElementType;
struct TreeNode;
typedef struct TreeNode* Position;//��ʾָ��һ���ڵ�
typedef struct TreeNode* SearchTree;//��ʾָ�����
SearchTree MakeEmpty(SearchTree T);//����
Position Find(ElementType X, SearchTree T);
Position FindMin(SearchTree T);
Position FindMax(SearchTree T);
SearchTree Insert(ElementType X, SearchTree T);
SearchTree Delete(ElementType X, SearchTree T);
SearchTree Insert(ElementType X, SearchTree T);
int Height(SearchTree T);
int Deep(SearchTree T);
void PrintDeep(SearchTree T);


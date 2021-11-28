#pragma once

typedef int ElementType;
struct TreeNode;
typedef struct TreeNode* Position;//表示指向一个节点
typedef struct TreeNode* SearchTree;//表示指向的树
SearchTree MakeEmpty(SearchTree T);//空树
Position Find(ElementType X, SearchTree T);
Position FindMin(SearchTree T);
Position FindMax(SearchTree T);
SearchTree Insert(ElementType X, SearchTree T);
SearchTree Delete(ElementType X, SearchTree T);
SearchTree Insert(ElementType X, SearchTree T);
int Height(SearchTree T);
int Deep(SearchTree T);
void PrintDeep(SearchTree T);


#pragma once
typedef int ElementType;
struct AvlNode;
typedef struct AvlNode* Position;//表示任意节点
typedef struct AvlNode* AvlTree;//表示该数
AvlTree MakeEmpty(AvlTree T);//清空一个树
Position Find(ElementType X, AvlTree T);
Position FindMin(AvlTree T);
Position FindMax(AvlTree T);
AvlTree Insert(ElementType X,AvlTree T);
AvlTree Delete(ElementType X, AvlTree T);
ElementType Retrieve(Position P);


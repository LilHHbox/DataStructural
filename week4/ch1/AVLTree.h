#pragma once
typedef int ElementType;
struct AvlNode;
typedef struct AvlNode* Position;//��ʾ����ڵ�
typedef struct AvlNode* AvlTree;//��ʾ����
AvlTree MakeEmpty(AvlTree T);//���һ����
Position Find(ElementType X, AvlTree T);
Position FindMin(AvlTree T);
Position FindMax(AvlTree T);
AvlTree Insert(ElementType X,AvlTree T);
AvlTree Delete(ElementType X, AvlTree T);
ElementType Retrieve(Position P);


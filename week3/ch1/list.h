#pragma once
typedef int ElementType;
struct Node;
typedef struct Node* PtrToNode;
typedef PtrToNode List;//表示整个链表，指向表头
typedef PtrToNode Position;//表示位置，可以指向任何地方

List MakeEmpty(List L);
int IsEmpty(List L);
int IsLast(Position P, List L);
void Delete(ElementType X, List L);
Position FindPrevious(ElementType X, List L);//根据元素找到前驱元素
Position FindPrevious1(int P, List L);//根据位置找到前驱元素
void Insert(ElementType X, List L, Position P);
void DeleteList(List L);
Position Header(List L);//找到头
Position Advance(Position P);//返回下一个值
ElementType Retrieve(Position P);//返回元素
void PrintOut(List L);
void PrintLost(List L, List P);//打印p数组元素位置对应的元素
void Swap(int P, List L);//用指针交换两个相邻的元素
void Inter(List L, List P);//交集
void Union(List L, List P, int N);//并集
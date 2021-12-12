#pragma once
struct TreeNode;
typedef struct TreeNode* PriorityQueue;
typedef struct HeapStruct* PriorityQueue1;
typedef  int ElementType ;

PriorityQueue Initialize(PriorityQueue H);
ElementType FindMin(PriorityQueue H);
int IsEmpty(PriorityQueue H);
PriorityQueue Merge(PriorityQueue H1, PriorityQueue H2);
PriorityQueue Merge1(PriorityQueue H1, PriorityQueue H2);
PriorityQueue Insert1(ElementType X, PriorityQueue H);
PriorityQueue DeleteMin1(PriorityQueue H);
void SwapChildren(PriorityQueue H);

#pragma once
//分离链接法：
//将散列到同一个值的元素保留在一个表中
typedef int ElementType;
typedef unsigned int Index;

struct  ListNode;//链表
typedef struct ListNode* Position;
typedef struct ListNode* List;
struct HashTbl;//hash表
typedef struct HashTbl* HashTable;

HashTable InitializeTable(int TableSize);
void DestoryTable(HashTable H);
Position Find(ElementType Key, HashTable H);
void Insert(ElementType Key, HashTable H);


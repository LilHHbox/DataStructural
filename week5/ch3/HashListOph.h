#pragma once


//再散列


typedef int ElementType;

typedef unsigned int Index;
typedef Index Position;

struct HashTbl;
typedef struct HashTbl* HashTable;
HashTable InitializeTable1(int TableSize);
void DestoryTable(HashTable H);

Position Find1(ElementType Key, HashTable H, int TableSize);
void Insert1(ElementType Key,HashTable H,int TableSize);
HashTable Rehash(HashTable H,int TableSize);//再散列
int Checklist1(HashTable H, int TableSize);


Position Find2(ElementType Key, HashTable H, int TableSize);
void Insert2(ElementType Key, HashTable H, int TableSize);
int Checklist2(HashTable H, int TableSize);

HashTable InitializeTable3(int TableSize);
Position Find3(ElementType Key, HashTable H, int TableSize);
void Insert3(ElementType Key, HashTable H, int TableSize);
int Checklist3(HashTable H, int TableSize);




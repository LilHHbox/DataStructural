#pragma once
//�������ӷ���
//��ɢ�е�ͬһ��ֵ��Ԫ�ر�����һ������
typedef int ElementType;
typedef unsigned int Index;

struct  ListNode;//����
typedef struct ListNode* Position;
typedef struct ListNode* List;
struct HashTbl;//hash��
typedef struct HashTbl* HashTable;

HashTable InitializeTable(int TableSize);
void DestoryTable(HashTable H);
Position Find(ElementType Key, HashTable H);
void Insert(ElementType Key, HashTable H);


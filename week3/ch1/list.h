#pragma once
typedef int ElementType;
struct Node;
typedef struct Node* PtrToNode;
typedef PtrToNode List;//��ʾ��������ָ���ͷ
typedef PtrToNode Position;//��ʾλ�ã�����ָ���κεط�

List MakeEmpty(List L);
int IsEmpty(List L);
int IsLast(Position P, List L);
void Delete(ElementType X, List L);
Position FindPrevious(ElementType X, List L);//����Ԫ���ҵ�ǰ��Ԫ��
Position FindPrevious1(int P, List L);//����λ���ҵ�ǰ��Ԫ��
void Insert(ElementType X, List L, Position P);
void DeleteList(List L);
Position Header(List L);//�ҵ�ͷ
Position Advance(Position P);//������һ��ֵ
ElementType Retrieve(Position P);//����Ԫ��
void PrintOut(List L);
void PrintLost(List L, List P);//��ӡp����Ԫ��λ�ö�Ӧ��Ԫ��
void Swap(int P, List L);//��ָ�뽻���������ڵ�Ԫ��
void Inter(List L, List P);//����
void Union(List L, List P, int N);//����
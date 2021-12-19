#include<stdio.h>
#include<stdlib.h>
#include"PairHeap.h"
typedef struct PairHeap* Position;
typedef struct PairHeap* Pair;
typedef int ElementType;
struct PairHeap
{
	ElementType Element;
	Pair NextSibiling;
	Pair Prev;
	Pair LeftChild;
};
static Position NullNode = NULL;
Pair Initilize(void)
{
	if (NullNode == NULL)
	{
		NullNode = (Position)malloc(sizeof(struct PairHeap));
		NullNode->LeftChild = NullNode->NextSibiling = NullNode->Prev = NullNode;
	}
	return NullNode;
}
Position CompareAndLink(Position First, Position Second)//合并两个子堆的过程
{
	if (Second == NULL)
		return First;
	else if (First->Element <= Second->Element)
	{
		Second->Prev = First;
		First->NextSibiling = Second->NextSibiling;
		if (First->NextSibiling != NULL)
			First->NextSibiling->Prev = First;
		Second->NextSibiling = First->LeftChild;
		if (Second->NextSibiling != NULL)
			Second->NextSibiling->Prev = Second;
		First->LeftChild = Second;
		return First;
	}
	else
	{
		Second->Prev = First->Prev;
		First->Prev = Second;
		First->NextSibiling = Second->LeftChild;
		if (First->NextSibiling != NULL)
			First->NextSibiling->Prev = First;
		Second->LeftChild = First;
		return Second;
	}
}
Pair Insert(ElementType Item, Pair H, Position* Loc)
{
	Position NewNode;
	NewNode = (Position)malloc(sizeof(struct PairHeap));
	NewNode->LeftChild = NewNode->NextSibiling = NewNode->Prev = NULL;


	*Loc = NewNode;
	if (H == NULL)
		return NewNode;
	else
		return CompareAndLink(H, NewNode);
}
Pair DecreaseKey(Position P, ElementType Delta, Pair H)
{
	P->Element -= Delta;
	if (P == H)
		return H;
	if (P->NextSibiling != NULL)
		P->NextSibiling->Prev = P->Prev;
	if (P->Prev->LeftChild == P)
		P->Prev->LeftChild = P->NextSibiling;
	else
		P->Prev->NextSibiling = P->NextSibiling;

	P->NextSibiling = NULL;
	return CompareAndLink(H, P);

}
Pair DeleteMin(ElementType* MinItem,Pair H)
{
	Position NewRoot = NULL;
	*MinItem = H->Element;
	if (H->LeftChild != NULL)
		NewRoot = CombineSiblings(H->LeftChild);
	free(H);
	return NewRoot;
}








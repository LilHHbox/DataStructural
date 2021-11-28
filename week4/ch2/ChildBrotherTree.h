#pragma once

typedef int ElementType;
struct TreeNode;
typedef struct TreeNode* Position;
typedef struct TreeNode* ChildBrotherTree;
ChildBrotherTree MakeEmpty(ChildBrotherTree);
ChildBrotherTree InsertSon(ElementType X, ChildBrotherTree T);
ChildBrotherTree InsertBrother(ElementType X, ChildBrotherTree T);
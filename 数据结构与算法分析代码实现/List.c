#include "List.h"
#include <stdio.h>
#include <stdlib.h>

struct Node
{
	ElementType Element;	//节点里的元素
	PtrToNode Next;		//Next指针
};

List MakeEmpty()	//创建空链表
{
	List L = (List)malloc(sizeof(List));
	L->Next = NULL;
	return L;
}
int IsEmpty(List L)	//判断链表是否空, O(1)
{
	return L->Next == NULL;
}
int IsLast(Position P, List L) //判断是否是尾节点, O(1)
{
	return P->Next == NULL;
}
Position Find(ElementType X, List L) //查找某个元素，如果没找到就返回头节点，O(N)
{
	Position P = L;
	while (P->Next != NULL && P->Element != X)
	{
		P = P->Next;
	}
	return P;	
}
void Delete(ElementType X, List L) //删除元素对应的节点，若元素出现多次，则只删除第一次出现的，O(N)
{
	Position P = FindPrevious(X, L);		//先找到该元素的前驱
	Position tmp = NULL;	//暂存节点
	if ( !IsLast(P,L))	//只要P不是最后一个节点
	{
		tmp = P->Next;
		P->Next = tmp->Next;
		free(tmp);	//释放内存
		tmp = NULL;	//防止野指针
	}
}
void Insert(ElementType X, List L, Position P) //在P节点后插入一个新的元素节点, O(1)
{
	Position tmp = (Position)malloc(sizeof(struct Node));
	if (tmp == NULL)
		printf("Out of memory");	//内存不足

	tmp->Element = X;
	tmp->Next = P->Next;
	P->Next = tmp;
}
Position FindPrevious(ElementType X, List L) //查找X元素节点的前驱， O(N)
{
	Position P = L;
	while (P->Next != NULL && P->Next->Element != X)
		P = P->Next;
	
	return P;	//若没找到，就返回最后一个节点
}
void DeleteList(List L)	//链表的清空
{
	Position P = L->Next;
	Position tmp = NULL;
	while (P != NULL)
	{
		tmp = P->Next;
		free(P);
		P = tmp;
	}
	L->Next = NULL;
}
Position Header(List L)	//获取表头header，注意header不是第一个节点，是专门的头节点
{
	return L;
}
Position First(List L)	//获取链表的第一个节点
{
	if (L->Next != NULL)
		return L->Next;
}
Position Advance(Position P) //
{

}
ElementType Retrieve(Position P)
{

}


#include "List.h"
#include <stdio.h>
#include <stdlib.h>

struct Node
{
	ElementType Element;	//�ڵ����Ԫ��
	PtrToNode Next;		//Nextָ��
};

List MakeEmpty()	//����������
{
	List L = (List)malloc(sizeof(List));
	L->Next = NULL;
	return L;
}
int IsEmpty(List L)	//�ж������Ƿ��, O(1)
{
	return L->Next == NULL;
}
int IsLast(Position P, List L) //�ж��Ƿ���β�ڵ�, O(1)
{
	return P->Next == NULL;
}
Position Find(ElementType X, List L) //����ĳ��Ԫ�أ����û�ҵ��ͷ���ͷ�ڵ㣬O(N)
{
	Position P = L;
	while (P->Next != NULL && P->Element != X)
	{
		P = P->Next;
	}
	return P;	
}
void Delete(ElementType X, List L) //ɾ��Ԫ�ض�Ӧ�Ľڵ㣬��Ԫ�س��ֶ�Σ���ֻɾ����һ�γ��ֵģ�O(N)
{
	Position P = FindPrevious(X, L);		//���ҵ���Ԫ�ص�ǰ��
	Position tmp = NULL;	//�ݴ�ڵ�
	if ( !IsLast(P,L))	//ֻҪP�������һ���ڵ�
	{
		tmp = P->Next;
		P->Next = tmp->Next;
		free(tmp);	//�ͷ��ڴ�
		tmp = NULL;	//��ֹҰָ��
	}
}
void Insert(ElementType X, List L, Position P) //��P�ڵ�����һ���µ�Ԫ�ؽڵ�, O(1)
{
	Position tmp = (Position)malloc(sizeof(struct Node));
	if (tmp == NULL)
		printf("Out of memory");	//�ڴ治��

	tmp->Element = X;
	tmp->Next = P->Next;
	P->Next = tmp;
}
Position FindPrevious(ElementType X, List L) //����XԪ�ؽڵ��ǰ���� O(N)
{
	Position P = L;
	while (P->Next != NULL && P->Next->Element != X)
		P = P->Next;
	
	return P;	//��û�ҵ����ͷ������һ���ڵ�
}
void DeleteList(List L)	//��������
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
Position Header(List L)	//��ȡ��ͷheader��ע��header���ǵ�һ���ڵ㣬��ר�ŵ�ͷ�ڵ�
{
	return L;
}
Position First(List L)	//��ȡ����ĵ�һ���ڵ�
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


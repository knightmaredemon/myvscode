/*����ʵ��*/
#pragma once
#define _List_H

#ifdef _List_H
typedef int ElementType;	//�ڵ���Ԫ�����ͣ�������Զ�̬���޸�
struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

List MakeEmpty();	//������պ���
int IsEmpty(List L);	//�ж������Ƿ��
int IsLast(Position P, List L); //�ж��Ƿ���β�ڵ�
Position Find(ElementType X, List L); //����ĳ��Ԫ��
void Delete(ElementType X, List L); //ɾ��Ԫ�ض�Ӧ�Ľڵ�
void Insert(ElementType X, List L, Position P); //��P�ڵ�����һ���µ�Ԫ�ؽڵ�
Position FindPrevious(ElementType X, List L); //����Ԫ��X��Ӧ�ڵ��ǰ��
void DeleteList(List L);	//�����ɾ��
Position Header(List L);	//��ȡ��ͷheader��ע��header���ǵ�һ���ڵ㣬��ר�ŵ�ͷ�ڵ�
Position First( List L);	//��ȡ����ĵ�һ���ڵ�
Position Advance(Position P); //
ElementType Retrieve(Position P);
	


#endif // _List_H

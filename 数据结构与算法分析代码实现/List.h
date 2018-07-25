/*链表实现*/
#pragma once
#define _List_H

#ifdef _List_H
typedef int ElementType;	//节点中元素类型，这个可以动态的修改
struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

List MakeEmpty();	//链表清空函数
int IsEmpty(List L);	//判断链表是否空
int IsLast(Position P, List L); //判断是否是尾节点
Position Find(ElementType X, List L); //查找某个元素
void Delete(ElementType X, List L); //删除元素对应的节点
void Insert(ElementType X, List L, Position P); //在P节点后插入一个新的元素节点
Position FindPrevious(ElementType X, List L); //查找元素X对应节点的前驱
void DeleteList(List L);	//链表的删除
Position Header(List L);	//获取表头header，注意header不是第一个节点，是专门的头节点
Position First( List L);	//获取链表的第一个节点
Position Advance(Position P); //
ElementType Retrieve(Position P);
	


#endif // _List_H

/*对于稀疏多项式，采用数组存储效率低下，因此考虑采用链表结构，
节点包括系数，指数，next指针三个域。多项式的运算中，主要要考虑
的是同类项合并的问题，这实际是一个数组元素去重的问题（合并幂
相同的节点），因此可以采用先排序（快排平均O(Nlog(N))），后遍历（O(N)）的方式完成。
总时间O(nlog(n))*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int coef;
	int exponent;
	struct node* next;
}node;

typedef struct List {
	node* next;
}List;

//打印多项式
void print_poly(List* poly)
{
	node* p = poly->next;
	while (p != NULL)
	{
		printf("%d*x^%d + ", p->coef,p->exponent);
		p = p->next;
	}
	printf("\n");
}

//创建空表
List* make_empty()
{
	List* list = (List*)malloc(sizeof(List));
	list->next = NULL;
	return list;
}

//在链表p节点后插入一个节点
void insert_node(List* list, node* p,int coef,int exponent)
{
	if (list == NULL)
		return;
	node* p_new = (node*)malloc(sizeof(node));
	p_new->coef = coef;
	p_new->exponent = exponent;
	if (p == NULL)//在头部插入
	{
		p_new->next = list->next;
		list->next = p_new;	
	}
	else
	{
		p_new->next = p->next;
		p->next = p_new;
	}
}


//获取链表长度
int length(List* list)
{
	int len = 0;
	node* pCur = list->next;
	while (pCur != NULL)
	{
		++len;
	}
	return len;
}

//获取尾部节点
node* last_node(List* list)
{
	node* p_node = list->next;
	while (p_node->next != NULL)
	{
		p_node = p_node->next;
	}
	return p_node;
}
//交换两节点内容
void swap_node(node* n1,node* n2)
{
	int tmp_coef = n1->coef;
	int tmp_exponent = n1->exponent;
	n1->coef = n2->coef;
	n1->exponent = n2->exponent;
	n2->coef = tmp_coef;
	n2->exponent = tmp_exponent;
}
//快速排序的分割，随机选取一个基准，把小于它的放到前面，大于的放到后面
node* partition(node* start, node* end)
{
	//取第一个数作为基准数，这其实有问题，当为有序数组时速度很慢，应当选(start+end)/2位置的数，保证一定的随机性
	node* p = start;
	node* q = p->next;	//q比p初始快一步
	node* reference = start;	//基准
	//从start开始向后进行一次遍历（单链表无法从后向前）
	while (/*q != NULL &&*/ q != end->next)
	{
		if (q->exponent < reference->exponent)
		{
			p = p->next;	//p永远指向的是当前已遍历过且比基准数小的最后一个数
			swap_node(p, q);
		}
		q = q->next;
	}
	swap_node(p, reference);	//最后将位于头部的基准与p交换，完成当前段的分割
	return p;
}

void quick_sort(node* start,node* end)
{
	if (start == end || start == NULL || end == NULL) //这个停止条件要注意必须保证start和end非空
	{
		return;
	}
	node* mid = partition(start, end);

	quick_sort(start, mid);
	quick_sort(mid->next, end);
}
//链表多项式的排序，同时合并指数相同的项
void sort_list(List* list)	
{
	if ((list->next == NULL) || (list->next->next == NULL))
	{
		return;
	}
	node* start = list->next;
	node* end = last_node(list);
	quick_sort(start, end);	
}

//多项式乘法返回一个新多项式链表
List* mult_polynomial(List* list_in1, List* list_in2)	
{
	//先准备好新的多项式链表的大小
	List* prod = make_empty();
	node* p_node_in1 = list_in1->next;
	node* p_node_in2 = list_in2->next;

	int prod_exponent = 0;
	int prod_coef = 0;

	while (p_node_in1 != NULL)
	{
		p_node_in2 = list_in2->next;	//这里记住要及时返回
		while (p_node_in2 != NULL)
		{
			prod_coef = p_node_in1->coef * p_node_in2->coef;
			prod_exponent = p_node_in1->exponent + p_node_in2->exponent;
			insert_node(prod, NULL, prod_coef, prod_exponent);	//每次都在头部插入

			p_node_in2 = p_node_in2->next;
		}
		p_node_in1 = p_node_in1->next;
	}

	//链表排序
	sort_list(prod);

	//合并同类项
	node* pCur = prod->next;
	node* pDelete = NULL;
	int i = 0;
	while (pCur->next != NULL)
	{
		if (pCur->exponent == pCur->next->exponent)
		{
			pCur->coef += pCur->next->coef;
			//删除多余节点
			pDelete = pCur->next;
			pCur->next = pDelete->next;
			free(pDelete);
			pDelete = NULL;
			continue;	//这个很关键，因为这里的if中修改了节点的next的指向，因此pCur就不能进行步进，而应当停留原地
		}
		pCur = pCur->next;
	}
	return prod;
}

int main____()
{
	List* poly1 = (List*)malloc(sizeof(List));
	List* poly2 = (List*)malloc(sizeof(List));

	node* x1 = (node*)malloc(sizeof(node));
	x1->coef = 3; x1->exponent = 7;	//3x^3

	node* x2 = (node*)malloc(sizeof(node));
	x2->coef = 5; x2->exponent = 12;	//5x^1

	node* x3 = (node*)malloc(sizeof(node));
	x3->coef = 2; x3->exponent = 15;	//2x^6

	node* x4 = (node*)malloc(sizeof(node));
	x4->coef = 9; x4->exponent = 6;	//9x^6



	x1->next = x2;
	x2->next = x3;
	x3->next = x4;
	x4->next = NULL;
	poly1->next = x1;

	node* y1 = (node*)malloc(sizeof(node));
	y1->coef = 4; y1->exponent = 7;	//4x^2

	node* y2 = (node*)malloc(sizeof(node));
	y2->coef = 1; y2->exponent = 6;	//1x^5

	node* y3 = (node*)malloc(sizeof(node));
	y3->coef = 3; y3->exponent = 12;	//3x^4

	node* y4 = (node*)malloc(sizeof(node));
	y4->coef = 7; y4->exponent = 5;	//7x^5


	y1->next = y2;	
	y2->next = y3; 
	y3->next = y4;
	y4->next = NULL;
	poly2->next = y1;

	sort_list(poly1);
	sort_list(poly2);

	print_poly(poly1);
	print_poly(poly2);
	List* prod = mult_polynomial(poly1, poly2);
	print_poly(prod);

	return 0;
}
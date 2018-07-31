/*����ϡ�����ʽ����������洢Ч�ʵ��£���˿��ǲ�������ṹ��
�ڵ����ϵ����ָ����nextָ�������򡣶���ʽ�������У���ҪҪ����
����ͬ����ϲ������⣬��ʵ����һ������Ԫ��ȥ�ص����⣨�ϲ���
��ͬ�Ľڵ㣩����˿��Բ��������򣨿���ƽ��O(Nlog(N))�����������O(N)���ķ�ʽ��ɡ�
��ʱ��O(nlog(n))*/
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

//��ӡ����ʽ
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

//�����ձ�
List* make_empty()
{
	List* list = (List*)malloc(sizeof(List));
	list->next = NULL;
	return list;
}

//������p�ڵ�����һ���ڵ�
void insert_node(List* list, node* p,int coef,int exponent)
{
	if (list == NULL)
		return;
	node* p_new = (node*)malloc(sizeof(node));
	p_new->coef = coef;
	p_new->exponent = exponent;
	if (p == NULL)//��ͷ������
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


//��ȡ������
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

//��ȡβ���ڵ�
node* last_node(List* list)
{
	node* p_node = list->next;
	while (p_node->next != NULL)
	{
		p_node = p_node->next;
	}
	return p_node;
}
//�������ڵ�����
void swap_node(node* n1,node* n2)
{
	int tmp_coef = n1->coef;
	int tmp_exponent = n1->exponent;
	n1->coef = n2->coef;
	n1->exponent = n2->exponent;
	n2->coef = tmp_coef;
	n2->exponent = tmp_exponent;
}
//��������ķָ���ѡȡһ����׼����С�����ķŵ�ǰ�棬���ڵķŵ�����
node* partition(node* start, node* end)
{
	//ȡ��һ������Ϊ��׼��������ʵ�����⣬��Ϊ��������ʱ�ٶȺ�����Ӧ��ѡ(start+end)/2λ�õ�������֤һ���������
	node* p = start;
	node* q = p->next;	//q��p��ʼ��һ��
	node* reference = start;	//��׼
	//��start��ʼ������һ�α������������޷��Ӻ���ǰ��
	while (/*q != NULL &&*/ q != end->next)
	{
		if (q->exponent < reference->exponent)
		{
			p = p->next;	//p��Զָ����ǵ�ǰ�ѱ������ұȻ�׼��С�����һ����
			swap_node(p, q);
		}
		q = q->next;
	}
	swap_node(p, reference);	//���λ��ͷ���Ļ�׼��p��������ɵ�ǰ�εķָ�
	return p;
}

void quick_sort(node* start,node* end)
{
	if (start == end || start == NULL || end == NULL) //���ֹͣ����Ҫע����뱣֤start��end�ǿ�
	{
		return;
	}
	node* mid = partition(start, end);

	quick_sort(start, mid);
	quick_sort(mid->next, end);
}
//�������ʽ������ͬʱ�ϲ�ָ����ͬ����
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

//����ʽ�˷�����һ���¶���ʽ����
List* mult_polynomial(List* list_in1, List* list_in2)	
{
	//��׼�����µĶ���ʽ����Ĵ�С
	List* prod = make_empty();
	node* p_node_in1 = list_in1->next;
	node* p_node_in2 = list_in2->next;

	int prod_exponent = 0;
	int prod_coef = 0;

	while (p_node_in1 != NULL)
	{
		p_node_in2 = list_in2->next;	//�����סҪ��ʱ����
		while (p_node_in2 != NULL)
		{
			prod_coef = p_node_in1->coef * p_node_in2->coef;
			prod_exponent = p_node_in1->exponent + p_node_in2->exponent;
			insert_node(prod, NULL, prod_coef, prod_exponent);	//ÿ�ζ���ͷ������

			p_node_in2 = p_node_in2->next;
		}
		p_node_in1 = p_node_in1->next;
	}

	//��������
	sort_list(prod);

	//�ϲ�ͬ����
	node* pCur = prod->next;
	node* pDelete = NULL;
	int i = 0;
	while (pCur->next != NULL)
	{
		if (pCur->exponent == pCur->next->exponent)
		{
			pCur->coef += pCur->next->coef;
			//ɾ������ڵ�
			pDelete = pCur->next;
			pCur->next = pDelete->next;
			free(pDelete);
			pDelete = NULL;
			continue;	//����ܹؼ�����Ϊ�����if���޸��˽ڵ��next��ָ�����pCur�Ͳ��ܽ��в�������Ӧ��ͣ��ԭ��
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
#include <iostream>
#include <list>
using std::list;

typedef struct _BinaryTreeNode {
	char				m_cValue;
	_BinaryTreeNode*		m_pLeft;
	_BinaryTreeNode*		m_pRight;
}BinaryTreeNode;

//构造表达式树
BinaryTreeNode* create_exp_BinaryTree(char* post_infix, size_t length)
{

	if (post_infix == NULL)
		return NULL;
	
	list<BinaryTreeNode*> lstStack;
	for (size_t i = 0; i < length; i++)
	{
		//若为运算符则取出栈顶2个
		if (post_infix[i] == '+'
			|| post_infix[i] == '-'
			|| post_infix[i] == '*'
			|| post_infix[i] == '/')
		{
			BinaryTreeNode* pNode = new BinaryTreeNode;
			pNode->m_cValue = post_infix[i];
			pNode->m_pRight = lstStack.back();
			lstStack.pop_back();

			pNode->m_pLeft = lstStack.back();
			lstStack.pop_back();
			lstStack.push_back(pNode);
		}
		else
		{
			BinaryTreeNode* pNode = new BinaryTreeNode;
			pNode->m_cValue = post_infix[i];
			pNode->m_pLeft = NULL;
			pNode->m_pRight = NULL;
			lstStack.push_back(pNode);
		}
	}
	BinaryTreeNode* pRoot = new BinaryTreeNode;
	pRoot = lstStack.back();
	return pRoot;
}

//打印二叉树，后续遍历
void print_node(BinaryTreeNode* pRoot)
{
	if (pRoot == NULL)
		return;

	BinaryTreeNode* pNode = pRoot;
	if (pNode->m_pLeft != NULL)
	{
		print_node(pNode->m_pLeft);
	}
	if (pNode->m_pRight != NULL)
	{
		print_node(pNode->m_pRight);
	}

	std::cout << pRoot->m_cValue;
}

int main_midfix_postfix()
{
	char postfix[] = "ab+cde+**";
	BinaryTreeNode* pRoot = create_exp_BinaryTree(postfix, strlen(postfix));
	print_node(pRoot);

	return 0;
}
#include <iostream>



struct BinaryTreeNode
{
	int m_Value;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
	BinaryTreeNode()
	{
		m_pLeft = NULL;
		m_pRight = NULL;
	}
};

//清空一棵树

BinaryTreeNode* MakeTreeEmpty(BinaryTreeNode* pRoot)
{
	if (pRoot != NULL)
	{
		MakeTreeEmpty(pRoot->m_pLeft);
		MakeTreeEmpty(pRoot->m_pRight);
		delete pRoot;
	}
	return NULL;
}

//查找树的搜索
BinaryTreeNode* Find(int iValue,BinaryTreeNode* pNode)
{
	if (pNode != NULL)
	{
		if (pNode->m_Value == iValue)
			return pNode;
		if (pNode->m_Value < iValue)
			return Find(iValue,pNode->m_pLeft);
		if (pNode->m_Value > iValue)
			return Find(iValue, pNode->m_pRight);
	}
	return NULL;
}

BinaryTreeNode* Insert(int iValue , BinaryTreeNode* pRoot)
{
	if (pRoot == NULL)
	{
		pRoot = new BinaryTreeNode;
		pRoot->m_Value = iValue;
		pRoot->m_pLeft = NULL;
		pRoot->m_pRight = NULL;
	}
	else
	{
		if (iValue < pRoot->m_Value)
		{
			pRoot->m_pLeft = Insert(iValue, pRoot->m_pLeft);
		}
		else
		{
			pRoot->m_pRight = Insert(iValue, pRoot->m_pRight);
		}
	}
	return pRoot;
}

BinaryTreeNode* FindMin(BinaryTreeNode* pRoot)
{
	if (pRoot != NULL)
	{
		while (pRoot->m_pLeft != NULL)
			pRoot = pRoot->m_pLeft;
	}
	return pRoot;
}
/**/
BinaryTreeNode* Delete(int iValue ,BinaryTreeNode* pRoot)
{
	if (pRoot == NULL)
		return NULL;

	if (iValue == pRoot->m_Value)
	{
		if (pRoot->m_pLeft != NULL && pRoot->m_pRight != NULL)
		{
			//有两个儿子
			//被替换的节点必然是右子树的最小节点
			BinaryTreeNode* pMin = FindMin(pRoot->m_pRight);
			pRoot->m_Value = pMin->m_Value;
			pRoot->m_pRight = Delete(pRoot->m_Value, pRoot->m_pRight);
		}
		else
		{
			//只有一个或没有儿子
			if (pRoot->m_pLeft)
				pRoot = pRoot->m_pLeft;
			else if (pRoot->m_pRight)
				pRoot = pRoot->m_pRight;
		}

	}
	else if (iValue < pRoot->m_Value)
	{
		pRoot->m_pLeft = Delete(iValue, pRoot->m_pLeft);	//往左走
	}
	else if (iValue > pRoot->m_Value)
	{
		pRoot->m_pRight = Delete(iValue, pRoot->m_pRight);	//往左走
	}
	return pRoot;
}

int main()
{
	BinaryTreeNode* pRoot = NULL;
	pRoot = Insert(6, pRoot);
	pRoot = Insert(2, pRoot);
	pRoot = Insert(8, pRoot);
	pRoot = Insert(1, pRoot);
	pRoot = Insert(4, pRoot);
	pRoot = Insert(3, pRoot);

	pRoot = Delete(2, pRoot);
	return 0;
}
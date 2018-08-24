#include <iostream>
#include <list>
using std::list;

bool Isbalance(const char* str, int len)
{
	bool ret = false;
	list<char> stack;
	for (size_t i = 0; i < len; i++)
	{
		if (str[i] == '(' || str[i] == '[' || str[i] == '{')
		{
			stack.push_back(str[i]);
		}
		else if (str[i] == ')')
		{
			if (stack.back() == '(')
			{
				stack.pop_back();
			}
			else
				break;
		}
		else if (str[i] == ']')
		{
			if (stack.back() == '[')
			{
				stack.pop_back();
			}
			else
				break;
		}
		else if (str[i] == '}')
		{
			if (stack.back() == '{')
			{
				stack.pop_back();
			}
			else
				break;
		}

	}

	if (stack.empty())
	{
		ret = true;
	}
	return ret;
}

int main_isbalanced()
{
	char str[] = "[P{qwe[wq]e}]";
	if (Isbalance(str,strlen(str)))
	{
		std::cout << "balance \n" << std::endl;
	}
	else
	{
		std::cout << "not balance \n" << std::endl;
	}
	return 0;
}
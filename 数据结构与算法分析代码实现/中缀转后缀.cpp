#include <iostream>
#include <list>
using std::list;

/*��ʾ���ݲ����������пո�*/
bool is_a_Lower_b(const char& a, const char& b)
{
	if (a == '+' || a == '-')
	{
		if (b == '+' || b == '-')
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	if (a == '*' || a == '/')
	{
		if (b == '+' || b == '-')
		{
			return false;
		}
		else if(b == '(')
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	if (a == '(')
		return false;
}

void infix_to_postfix(list<char>& lstOutPut, char expression[], size_t length)
{
	list<char> lstStack;
	//list<char> lstOutPut;
	for (size_t i = 0; i < length; i++)
	{
		if (expression[i] == '+'
			|| expression[i] == '-'
			|| expression[i] == '*'
			|| expression[i] == '/'
			|| expression[i] == '(')
		{
			//��Ϊ�������Ҫ����ջ�����ȼ���+ = - < * = / < (
			while (!lstStack.empty())
			{
				char tmp = lstStack.back();
				if (is_a_Lower_b(tmp, expression[i]) || (tmp == '('))
				{
					break;
				}
				lstOutPut.push_back(tmp);
				lstStack.pop_back();
			}
			lstStack.push_back(expression[i]);
		}
		else if (expression[i] == ')')
		{
			while (!lstStack.empty())
			{
				if (lstStack.back() != '(')
				{
					char tmp = lstStack.back();
					lstStack.pop_back();
					lstOutPut.push_back(tmp);
				}
				else
				{
					lstStack.pop_back();	//����'('�����䲻�������
					break;
				}
			}


		}
		else
		{
			//������ֱ�����
			lstOutPut.push_back(expression[i]);
		}
	}

	while (!lstStack.empty())
	{
		lstOutPut.push_back(lstStack.back());
		lstStack.pop_back();
	}
}


int main_infix_to_postfix()
{
	list<char> output;
	char str[] = "a+b*c+(d*e+f)*g";

	infix_to_postfix(output, str, strlen(str));


	return 0;
}
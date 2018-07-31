#include <list>
#include <iostream>
using  std::list;
using std::cout;
using std::endl;


void print_arr(int arr[], int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

//获取数组中最高位位数
int GetMaxDigit(int arr[], int length)
{
	int digit = 1;
	int base = 10;
	for (size_t i = 0; i < length; i++)
	{
		while (arr[i] >= base)
		{
			++digit;
			base *= 10;
		}
	}
	return digit;
}

void radix_sort(int arr[], int length)
{
	//生成10个链表
	list<int> lists[10];
	
	int MaxDigit = GetMaxDigit(arr,length);		//最高位
	int D = 1;
	while (MaxDigit--)
	{
		for (int i = 0;i < length; i++)
		{
			int tail = (arr[i] / (D)) % 10;
			lists[tail].push_back(arr[i]);
		}
		int i = 0;
		int j = 0;
		
		while (j<length)
		{
			while (!lists[i].empty())
			{
				arr[j] = lists[i].front();
				lists[i].pop_front();
				j++;
			}
			i++;
		}	
		print_arr(arr, length);
		D = D * 10;
	}
}

int main()
{
	int arr[10] = { 64,8,216,512,27,729,0,1,343,125 };
	radix_sort(arr, 10);
	return 0;
}
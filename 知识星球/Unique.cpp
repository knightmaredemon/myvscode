/*Ԫ��ȥ��*/
/*���룺����/���� S (��Ϊ��int��)
�����ȥ��S�е��ظ�Ԫ��

������7��9��3��9��2��1��7��2
�����7��9��3��2��1��˳�����⣩*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//������nlog(n)����L��R˫�߽����n����ʱ��=nlog(n) + n=nlog(n)
void Unique_1(vector<int>& vec)
{
	sort(vec.begin(), vec.end());
	int len = vec.size();
	int L = 0, R = 0;
	for (L = 0,R=L+1; R<len; ++R)
	{
		if (vec[L] != vec[R])	//���Ⱦ����������L
		{
			cout << vec[L] << " ";
			L = R;
		}
	}
	if (len > 0)
	{
		cout << vec[L] << endl;
	}
}
int main()
{
	vector<int> S = { 7,9,3,9,2,1,7,2,5,8,10,13,43,34,13,11,8,5,2 };
	Unique_1(S);
	return 0;
	

}
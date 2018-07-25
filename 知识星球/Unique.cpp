/*元素去重*/
/*输入：数组/向量 S (认为是int型)
输出：去除S中的重复元素

算例：7，9，3，9，2，1，7，2
结果：7，9，3，2，1（顺序随意）*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//先排序nlog(n)，再L，R双边界遍历n，总时间=nlog(n) + n=nlog(n)
void Unique_1(vector<int>& vec)
{
	sort(vec.begin(), vec.end());
	int len = vec.size();
	int L = 0, R = 0;
	for (L = 0,R=L+1; R<len; ++R)
	{
		if (vec[L] != vec[R])	//不等就输出并更新L
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
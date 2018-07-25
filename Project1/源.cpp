#include <iostream>
#include <utility>
#include <thread>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <WINSOCK2.H>
using namespace std;

void print()
{
	
}

template <typename T,typename... Types>
void print(const T& firstArg, const Types&... args)
{
	cout << firstArg << endl;
	print(args...);
}
template < typename... Types>
void print( const Types&... args)
{
	cout << args << endl;
}

void print(initializer_list<int> vals)
{
	for (auto p = vals.begin();p != vals.end();++p)
	{
		cout << *p << endl;
	}

}

class P
{
public:
	P(int a, int b)
	{
		cout << "P(int ,int),a=" << a << "," << "b=" << b << endl;
	}

	P(initializer_list<int> inilists)
	{
		cout << "P(initializer_list<int>)" << endl;
	}
};

class MyClass
{
public:

	 MyClass();
// 	 MyClass(initializer_list<int>)
// 	 {
// 		 cout << "initializer_list<int>" << endl;
// 	 }
	  MyClass(int a, int b, int c)
	 {
		 cout << "explicit" << endl;
	 }
	  ~MyClass()  = default;
	void foo(char) {};
	void foo(int) = delete;

private:

};

MyClass::MyClass()
{
}

template<typename T>
using  Vec = std::vector<T,allocator<T>>;

Vec<int> coll = {1,2,3,4};

template<typename T1,typename T2>
auto add(T1 x, T2 y)->decltype(x + y)
{
	return x + y;
}

template<typename T>
void test_decltype(T obj)
{
	typedef typename decltype(obj)::iterator iType;
	iType i;
	
}

int main()
{

	int ccc = 10;
	int bbb = 1;
	auto I = [ccc,&bbb]()mutable ->int {
		++ccc;
		bbb++;
		cout << " hello" << endl;
		return bbb;
	};
	int tmpbbb = I();
	map<string, float> mp;
	test_decltype(mp);
	int sm = add(1, 5);

	int sd = 10 / 8;
	decltype(sd) qw;

	int al[8] = {1,23,43,56,34,27,98,76};
	vector<int > vi(al, al + 8);
	cout << count_if(vi.begin(), vi.end(),
			not1(bind2nd(less<int>(), 40)));
	
	char str[] = {"123 456 555"};
	size_t n = strspn(str,"123");
	char* url = strpbrk(str, "3");
	*url++ = '\0';

	
	MyClass m;
	
	m.foo('a');
	for (int& i : vector<int>{1,3,5,6,83,1})
	{
		i *= 3;
	}


	vector<double> vec{ 1.1,2.2,3.3,4.4 };
	
	for (auto elem : vec)
	{
		elem *= 3;
		cout << elem << endl;
	}
	

	MyClass mc  = { 1,2,3 };

	tuple<int, float, string> t(41, 6.3, "nico");
	print({ 1,2,3,4,5,6,7,8 });
	initializer_list<int> aa = { 1,2,34,5,6 };
	vector<int> i{ 1,2,4,5,98,1 };
	for (auto it : i)
	{
		cout << it << endl;
	}

	
	P({ 1,3 });
	P(1, 2);

	return 0;
}


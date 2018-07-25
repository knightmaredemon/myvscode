#include <iostream>  
#include <utility>  

std::pair<uint64_t, uint64_t> Fib(size_t n)
{
	if (n > 0)
	{
		auto PF = Fib(n / 2); //C++11新特性，auto返回值由编译器根据初值确定  
		auto t0 = PF.first;    //Fm  
		auto t1 = PF.second;   //Fm+1  
		if (n % 2 == 1)
			return { t0 * t0 + t1 * t1, (2 * t0 + t1) * t1 };
		else
			return { (2 * t1 - t0) * t0, t0 * t0 + t1 * t1 };
	}
	return { 0,1 }; // n = 0  
}


int main_Fib(int argc, char* agrv[])
{
	if (argc < 2)
	{
		std::cout << "please input n" << std::endl;
		return 0;
	}

	size_t n = atoi(agrv[1]);
	std::cout << "n=" << n << std::endl;

	auto F = Fib(n);
	std::cout << "F" << n << "=" << F.first << "," << "F" << n + 1 << "=" << F.second << std::endl;
	return 0;
}

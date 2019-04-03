#include <iostream>

int main()
{
	unsigned long N;
	std::cin >> N;

	if ( N & 1 )
	{
		// Nが奇数なら2倍する
		std::cout << N * 2 << std::endl;
	}
	else
	{
		// Nが偶数なら、それで確定
		std::cout << N << std::endl;
	}

	return ( 0 );
}

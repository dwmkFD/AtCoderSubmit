#include <iostream>

int main()
{
	unsigned long N;
	std::cin >> N;

	if ( N & 1 )
	{
		// N����Ȃ�2�{����
		std::cout << N * 2 << std::endl;
	}
	else
	{
		// N�������Ȃ�A����Ŋm��
		std::cout << N << std::endl;
	}

	return ( 0 );
}

#include <iostream>

int main()
{
	unsigned long N;
	std::cin >> N;

	if ( N & 1 )
	{
		// N‚ªŠï”‚È‚ç2”{‚·‚é
		std::cout << N * 2 << std::endl;
	}
	else
	{
		// N‚ª‹ô”‚È‚çA‚»‚ê‚ÅŠm’è
		std::cout << N << std::endl;
	}

	return ( 0 );
}

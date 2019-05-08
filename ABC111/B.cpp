#include <iostream>

int main()
{
	int N;
	std::cin >> N;

	const int table[] = {
		111, 222, 333, 444, 555, 666, 777, 888, 999
	};

	for ( int i = 0; i < sizeof( table ) / sizeof( table[0] ); i++ )
	{
		if ( N <= table[i] )
		{
			std::cout << table[i] << std::endl;
			break;
		}
	}

	return ( 0 );
}

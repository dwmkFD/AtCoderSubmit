#include <iostream>

int main()
{
	int n;
	std::cin >> n;

	int c = 100;
	int result = 0;
	for ( int i = 0; i < 3; i++ )
	{
		int tmp = n / c;
		if ( tmp == 1 )
		{
			result += 9;
		}
		else if ( tmp == 9 )
		{
			result += 1;
		}
		else
		{
			result += tmp;
		}
		result *= 10;
		n %= c;
		c /= 10;
	}

	std::cout << result / 10 << std::endl;

	return ( 0 );
}

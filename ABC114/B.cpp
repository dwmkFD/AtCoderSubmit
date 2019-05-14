#include <iostream>
#include <string>

int main()
{
	std::string S;
	std::cin >> S;

	unsigned long long x = 0;
	for ( int i = 0; i < S.size(); i++ )
	{
		x *= 10;
		x += S[i] - '0';
	}

	unsigned int diff = 1e9;
	for ( ; x > 0; x /= 10 )
	{
		int y = x % 1000;
		int z = std::abs( 753 - y );

		if ( z < diff )
		{
			diff = z;
		}
	}

	std::cout << diff << std::endl;

	return ( 0 );
}

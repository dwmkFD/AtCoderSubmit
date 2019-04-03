#include <iostream>

int main()
{
	unsigned int n, k;
	std::cin >> n >> k;

	if ( n == k )
	{
		// NとKが等しければ1回で終わり
		std::cout << "1" << std::endl;
	}
	else
	{
		if ( ( n - 1 ) % ( k - 1 ) )
		{
			// 余りが出るなら切り上げる
			std::cout << ( ( n - 1 ) / ( k - 1 ) ) + 1 << std::endl;
		}
		else
		{
			std::cout << ( n - 1 ) / ( k - 1 ) << std::endl;
		}
	}

	return ( 0 );
}

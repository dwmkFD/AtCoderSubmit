#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int N;
	std::cin >> N;

	std::vector<int> v( N );
	std::vector<int> c( N );
	std::vector<int> Cost( N );

	for ( int i = 0; i < N; i++ )
	{
		std::cin >> v[i];
	}

	for ( int i = 0; i < N; i++ )
	{
		std::cin >> c[i];
	}

	for ( int i = 0; i < N; i++ )
	{
		Cost[i] = v[i] - c[i];
	}

	std::sort( Cost.begin(), Cost.end(), []( int x, int y ) {
			return ( y > x );
		} );

	int result = 0;

	for ( int i = 0; i < N; i++ )
	{
		if ( Cost[i] > 0 )
		{
			result += Cost[i];
		}
	}

	std::cout << result << std::endl;

	return ( 0 );
}

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int N;
	std::cin >> N;

	std::vector<int> v( N );
	for ( int i = 0; i < N; i++ )
	{
		std::cin >> v[i];
	}

	std::sort( v.begin(), v.end(), []( int a, int b ) {
			return( a > b );
		} );

	int total = 0;
	for ( int i = 1; i < N; i++ )
	{
		total += v[i];
	}

	if ( total > v[0] )
	{
		std::cout << "Yes" << std::endl;
	}
	else
	{
		std::cout << "No" << std::endl;
	}

	return ( 0 );
}

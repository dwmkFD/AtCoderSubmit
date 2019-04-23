#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int iAbs( int x )
{
	return ( x > 0 ? x : -x );
}

int iMin( int x, int y )
{
	return ( x < y ? x : y );
}

int main()
{
	int N, K;
	std::cin >> N >> K;

	std::vector<int> v( N );
	for ( int i = 0; i < N; i++ )
	{
		std::cin >> v[i];
	}

	int mindiff = INT_MAX;
	for ( int i = 0; i <= N - K; i++ )
	{
		int l_to_r = iAbs( v[i] ) + iAbs( v[i + K - 1] - v[i] );
		int r_to_l = iAbs( v[i + K - 1] ) + iAbs( v[i + K - 1] - v[i] );
		int tmp = iMin( l_to_r, r_to_l );

		if ( tmp < mindiff )
		{
			mindiff = tmp;
		}
	}

	std::cout << mindiff << std::endl;

	return ( 0 );
}

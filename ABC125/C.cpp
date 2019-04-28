#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

template<typename T> T gcd( T x, T y )
{
	return ( y ? gcd( y, x % y ) : x );
}


int main()
{
	long N;
	std::cin >> N;
	std::vector<long> v( N );

	for ( int i = 0; i < N; i++ )
	{
		std::cin >> v[i];
	}

	// —İÏGCD‚ğ¶‰E‚©‚ç‹‚ß‚é
	std::vector<long> left( N + 1, 0 );
	std::vector<long> right( N + 1, 0 );

	for ( int i = 0; i < N; i++ )
	{
		left[i + 1] = gcd( left[i], v[i] );
	}
	for ( int i = N - 1; i >= 0; i-- )
	{
		right[i] = gcd( right[i + 1], v[i] );
	}

	// Å‘å’l‚ğ‹‚ß‚é
	long result = 0;
	for ( int i = 0; i < N; i++ )
	{
		long lmax = left[i];
		long rmax = right[i + 1];
		long tmp = gcd( lmax, rmax );

		if ( result < tmp )
		{
			result = tmp;
		}
	}

	std::cout << result << std::endl;

	return ( 0 );
}

#include <iostream>
#include <vector>
#include <algorithm>

long myABS( long x )
{
	return ( x > 0 ? x : -x );
}

long gcd( long a, long b )
{
	return ( b == 0 ? a : gcd( b, a % b ) );
}

int main()
{
	long N, X;
	std::cin >> N >> X;

	long max = 1000000001;
	std::vector<long> v( N + 1 );
	for ( long i = 0; i < N; i++ )
	{
		std::cin >> v[i];
	}
	v[N] = X;

	if ( N == 1 )
	{
		max = myABS( X - v[0] );
	}
	else
	{
		std::sort( v.begin(), v.end() );

		std::vector<long> vv( N + 1 );
		for ( long i = 0; i < N; i++ )
		{
			vv[i] = v[i + 1] - v[i];
		}

		for ( long i = 0; i < N - 1; i++ )
		{
			long tmp = gcd( vv[i + 1], vv[i] );
			if ( tmp < max )
			{
				max = tmp;
			}
		}
	}

	std::cout << max << std::endl;

	return ( 0 );
}

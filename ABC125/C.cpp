#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int main()
{
	long N;
	std::cin >> N;
	std::vector<long> v( N );

	for ( int i = 0; i < N; i++ )
	{
		std::cin >> v[i];
	}

	long tmp = 32767;
	std::vector<long> prime;

	prime.emplace_back( 2 );
	prime.emplace_back( 3 );

	for ( int i = 5; i < tmp; i += 2 )
	{
		int j = 0;
		for ( auto &&it : prime )
		{
			if ( ( i % it ) == 0 )
			{
				break;
			}
			j++;
		}

		if ( j == prime.size() )
		{
			prime.emplace_back( i );
		}
	}

	std::vector<long> vv( N );
	for ( auto &&itt : v )
	{
		std::cout << "itt = " << itt << std::endl;
		for ( auto &&ittt : prime )
		{
			if ( ( itt % ittt ) == 0 )
			{
				if ( ittt < N )
				{
					vv[ittt]++;
				}
			}
		}
	}

	for ( long i = vv.size() - 1; i >= 0; i-- )
	{
		std::cout << "vv[" << i << "] = " << vv[i] << std::endl;
		if ( ( vv[i] == N ) || ( vv[i] == N - 1 ) )
		{
			std::cout << i << std::endl;
			break;
		}
	}

	return ( 0 );
}

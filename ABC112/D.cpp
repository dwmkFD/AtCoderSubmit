#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int N, M;
	std::cin >> N >> M;

	std::vector<int> v;
	for ( int i = 1; i * i <= M; i++ )
	{
		if ( M % i != 0 )
		{
			continue;
		}
		else
		{
			v.emplace_back( i );
			v.emplace_back( M / i );
		}
	}

	std::sort( v.begin(), v.end() );

	int d = 1;
	for ( auto &&it : v )
	{
		if ( it > M / N )
		{
			break;
		}

		if ( d < it )
		{
			d = it;
		}
	}

	std::cout << d << std::endl;

	return ( 0 );
}

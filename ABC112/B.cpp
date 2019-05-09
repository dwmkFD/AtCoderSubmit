#include <iostream>
#include <vector>

int main()
{
	int N, T;
	std::cin >> N >> T;

	std::vector<std::pair<int, int> > v;
	for ( int i = 0; i < N; i++ )
	{
		int c, t;
		std::cin >> c >> t;
		v.emplace_back( std::make_pair( c, t ) );
	}

	int cost = 1e5;
	for ( auto &&it : v )
	{
		if ( it.second <= T )
		{
			if ( cost > it.first )
			{
				cost = it.first;
			}
		}
	}

	if ( cost == 1e5 )
	{
		std::cout << "TLE" << std::endl;
	}
	else
	{
		std::cout << cost << std::endl;
	}

	return ( 0 );
}

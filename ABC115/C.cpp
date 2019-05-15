#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int N, K;
	std::cin >> N >> K;

	std::vector<int> v( N );
	for ( int i = 0; i < N; i++ )
	{
		std::cin >> v[i];
	}

	std::sort( v.begin(), v.end() );

	int diff = 1e9 + 1;
	for ( int i = 0; i < N - K + 1; i++ )
	{
		if ( diff > ( v[i + K - 1] - v[i] ) )
		{
			diff = v[i + K - 1] - v[i];
		}
	}

	std::cout << diff << std::endl;

	return ( 0 );
}

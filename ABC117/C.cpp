#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int N, M;
	std::cin >> N >> M;

	std::vector<int> v( M );
	for ( int i = 0; i < M; i++ )
	{
		std::cin >> v[i];
	}
	std::sort( v.begin(), v.end() );

	std::vector<int> vv( M - 1 );
	for ( int i = 0; i < M - 1; i++ )
	{
		vv[i] = v[i + 1] - v[i];
	}
	std::sort( vv.begin(), vv.end() );

	// 両端を除いて（M-2）、N-1個のコマを配置する？
	long long dist = 0;
	for ( int i = 0; i <= M - 2 - ( N - 1 ); i++ )
	{
		dist += vv[i];
	}

	std::cout << dist << std::endl;

	return ( 0 );
}

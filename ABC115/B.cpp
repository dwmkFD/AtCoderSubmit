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

	std::sort( v.begin(), v.end() );

	int total = 0;
	for ( int i = 0; i < N - 1; i++ )
	{
		total += v[i];
	}

	total += v[N - 1] / 2;

	std::cout << total << std::endl;

	return ( 0 );
}

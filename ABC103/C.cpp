#include <iostream>
#include <vector>

int main()
{
	int N;
	std::cin >> N;

	std::vector<int> v( N );

	for ( int i = 0; i < N; i++ )
	{
		std::cin >> v[i];
	}

	// あるXについて、余りの最大値は、X-1である
	long total = 0;
	for ( auto &&it : v )
	{
		total += it - 1;	//	つまり、最大値を全部合計すれば良い
	}

	std::cout << total << std::endl;

	return ( 0 );
}

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	unsigned int N;
	std::vector<unsigned long> v;

	std::cin >> N;

	for ( int i = 0; i < N; i++ )
	{
		unsigned long tmp;
		std::cin >> tmp;
		v.emplace_back( tmp );
	}

	// 要素を降順ソートする
	std::sort( v.begin(), v.end(), []( unsigned long a, unsigned long b ) {
			return ( a > b );
		} );

	// 最初と最後の差分が最大値になる
	std::cout << v[0] - v.back() << std::endl;

	return ( 0 );
}

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int A, B, C, D, E;
	std::cin >> A >> B >> C >> D >> E;

	std::vector<int> v = { A, B, C, D, E };

	// 1の位の値が大きい順にソートする
	std::sort( v.begin(), v.end(), []( int a, int b ) {
			return ( a % 10 > b % 10 );
		} );

	// さらに1の位が0のものを前に持ってくる
	std::sort( v.begin(), v.end(), []( int a, int b ) {
			return ( a % 10 == 0 );
		} );

	int total = 0;
	for ( int i = 0; i < 5; i++ )
	{
		total += v[i];
		int mod = total % 10;

		if ( ( mod != 0 ) && ( i != 4 ) )	//	最後の要素は除外する
		{
			total += 10 - mod;
		}
	}

	std::cout << total << std::endl;

	return ( 0 );
}

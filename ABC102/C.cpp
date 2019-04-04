#include <iostream>
#include <vector>
#include <algorithm>

long funcABS( long x )
{
	return ( x > 0 ? x : -x );
}

int main()
{
	unsigned int N;
	std::vector<long> v;

	std::cin >> N;

	for ( int i = 0; i < N; i++ )
	{
		long tmp;
		std::cin >> tmp;
		v.emplace_back( tmp );
	}

	// 式を変形すると、、、
	// abs( A_i - i - b )

	// A_i - i を先に計算する
	long A_total = 0;
	for ( int i = 0; i < N; i++ )
	{
		A_total += ( v[i] - ( i + 1 ) );
	}

	// A_total - N * bが一番小さくなるようなbを求める
	// -> A_total / Nで良い？
	long b = funcABS( A_total ) / N;
	if ( A_total < 0 )
	{
		b *= -1;
		if ( funcABS( A_total ) % N )
		{
			// 負の値で余りがある場合は切り捨て＝絶対値が1大きくなる
			b -= 1;
		}
	}

	// 計算する
	long sad_value = 0;
	for ( int i = 0; i < N; i++ )
	{
		sad_value += funcABS( v[i] - ( b + ( i + 1 ) ) );
	}

	std::cout << sad_value << std::endl;

	return ( 0 );
}

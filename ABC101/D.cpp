#include <iostream>
#include <vector>

unsigned long long funcS( unsigned long long n )
{
	unsigned long long result = 0;
	for ( ; n > 0; n /= 10 )
	{
		result += n % 10;
	}

	return ( result );
}

unsigned int getD( unsigned long long input )
{
	unsigned int digit = 0;
	for ( ; input > 0; input /= 10 )
	{
		digit++;
	}

	return ( digit );
}

unsigned long long pow10( unsigned int input )
{
	unsigned long long result = 1;
	for ( int i = 0; i < input; i++ )
	{
		result *= 10;
	}

	return ( result );
}

int main()
{
	unsigned long long K;
	std::cin >> K;

	std::vector<unsigned long long> v = {
		1, 2, 3, 4, 5, 6, 7, 8, 9, 19,			//	問題文で与えられて、すでに判明している
	};

	// Kが10以下なら、既知の値をそのまま出力して終了
	if ( K <= 10 )
	{
		for ( int i = 0; i < K; i++ )
		{
			std::cout << v[i] << std::endl;
		}
	}
	else
	{
		// Kが10より大きければ、追加分を探す
		unsigned long long counter = 10;
		unsigned long long diff = 10;
		for ( unsigned long long k_ = 29; counter < K; k_ += diff )	//	続きは29から探す
		{
			bool bFind = true;
			for ( unsigned int d = 0; d < getD( k_ ); d++ ) // k_の桁数分ループ
			{
				// 候補となる値を計算する
				unsigned long long x = pow10( d + 1 );
				x *= (unsigned long long)( ( (double)k_ / pow10( d + 1 ) ) + 1 );
				x -= 1;

				if ( (double)k_ / funcS( k_ ) > (double)x / funcS( x ) )
				{
					bFind = false;
					break;
				}
			}

			if ( bFind )
			{
				diff = k_ - v.back();	//	差分を再計算して計算範囲を絞り込む
				v.emplace_back( k_ );
				counter++;
			}
		}

		for ( auto &&it : v )
		{
			std::cout << it << std::endl;
		}
	}

	return ( 0 );
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int main()
{
	long long N;
	std::cin >> N;

	std::vector<long long> v;

	while ( N != 0 )	//	ピッタリ0になるまでループ
	{
		long long p = 0;
		long long tmp = 0;
		long long sum = 0;

		if ( N > 0 )
		{
			// -2^pを計算する（正の数側）
			while ( N > sum )
			{
				tmp = pow( -2, p );
				sum += tmp;	//	足し合わせていく
				p += 2;		//	正の数だけ考えるので、2ずつ
			}
			v.emplace_back( p - 2 );	//	1回余分に回ってるので調整
			N -= tmp;
		}
		else
		{
			// -2^pを計算する（負の数側）
			p = 1;
			while ( N < sum )
			{
				tmp = pow( -2, p );
				sum += tmp;
				p += 2;
			}
			v.emplace_back( p - 2 );
			N -= tmp;	//	sumは負の値なので、減算でOK
		}
	}

	// 見つけた-2^pのpの値を昇順に探す
	std::vector<int> v_res;
	long long findCounter = 0;
	for ( int i = 0; findCounter < v.size(); i++ )
	{
		auto result = std::find( v.begin(), v.end(), i );
		v_res.emplace_back( result != v.end() ? findCounter++, 1 : 0 );
	}
 
	// 下位ビットから格納したので、逆順に出力する
	if ( 0 == findCounter )
	{
		std::cout << "0";	//	0は特別対応
	}
	for ( auto it = v_res.rbegin(); it != v_res.rend(); it++ )
	{
		std::cout << ( *it );
	}
	std::cout << std::endl;

	return ( 0 );
}

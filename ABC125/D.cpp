#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	long N;
	std::cin >> N;
	std::vector<long> v( N );

	long negCounter = 0;
	for ( long i = 0; i < N; i++ )
	{
		std::cin >> v[i];
		if ( v[i] <= 0 )
		{
			++negCounter;	//	負の値（と0）の個数をカウントしておく
		}
	}

	// 絶対値に変換した入力列を作る
	std::vector<long> vv( N );
	for ( int i = 0; i < v.size(); i++ )
	{
		if ( v[i] <= 0 )
		{
			vv[i] = -v[i];
		}
		else
		{
			vv[i] = v[i];
		}
	}

	long long result = 0;
	if ( negCounter % 2 )
	{
		// 負の値が奇数個なら、どこかが必ず負の値として残ってしまう
		// 入力の絶対値を昇順ソートして、一番小さいものだけを負の数にする
		std::sort( vv.begin(), vv.end() );

		for ( auto &&it : vv )
		{
			result += it;
		}

		// 先頭要素だけ減算する
		result -= vv[0] * 2;	//	1回余分に足してるので
	}
	else
	{
		// 負の値が偶数個なら、全部正の数にできるので、入力の絶対値を足して終わり
		for ( auto &&it : vv )
		{
			result += it;
		}
	}

	std::cout << result << std::endl;

	return ( 0 );
}

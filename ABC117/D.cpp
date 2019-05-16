#include <iostream>
#include <vector>
#include <algorithm>

using ull = unsigned long long;

// 1になっている最上位ビットを求める
ull getmsb( ull x )
{
	x |= ( x >> 1  );
	x |= ( x >> 2  );
	x |= ( x >> 4  );
	x |= ( x >> 8  );
	x |= ( x >> 16 );
	x |= ( x >> 32 );

	return ( x ^ ( x >> 1 ) );
}

// 1の数を求める
ull popcnt( ull x )
{
    ull t = 0;
    t = ( x & 0x5555555555555555 ) + ( ( x >> 1  ) & 0x5555555555555555 );
    t = ( t & 0x3333333333333333 ) + ( ( t >> 2  ) & 0x3333333333333333 );
    t = ( t & 0x0f0f0f0f0f0f0f0f ) + ( ( t >> 4  ) & 0x0f0f0f0f0f0f0f0f );
    t = ( t & 0x00ff00ff00ff00ff ) + ( ( t >> 8  ) & 0x00ff00ff00ff00ff );
    t = ( t & 0x0000ffff0000ffff ) + ( ( t >> 16 ) & 0x0000ffff0000ffff );
    t = ( t & 0x00000000ffffffff ) + ( ( t >> 32 ) & 0x00000000ffffffff );

    return ( t );
}

// 1になったビットがLSB側から何ビット目かを求める
ull tzcnt( ull x )
{
	return ( popcnt( ~x & ( x - 1 ) ) );
}

int main()
{
	ull N, K;
	std::cin >> N >> K;

	ull sum = 0;
	std::vector<ull> v( N );
	std::vector<ull> vv( 64 );
	for ( int i = 0; i < N; i++ )
	{
		std::cin >> v[i];
		sum += v[i] ^ K;	//	X == Kが最適の可能性もある

		for ( int j = 0; j < 64; j++ )
		{
			// jビット目が1？
			v[i] & ( 1 << j ) ? vv[j]++ : 0;
		}
	}

	// とりあえず、Kを考慮せずに最適っぽいXを求める
	ull X = 0;
	for ( int i = 0; i <= tzcnt( getmsb( K ) ); i++ )
	{
		if ( vv[i] < ( N + 1 ) / 2 )
		{
			// iビット目が1になっている値の方が少ないので
			// Xのiビット目は1にするべき
			X |= ( 1 << i );
		}
	}

	if ( X > K )
	{
		for ( int i = tzcnt( getmsb( K ) ); i >= 0; --i )
		{
			if ( K & ( 1 << i ) )
			{
				ull tmpK = K & ~( 1 << i );	//	iビット目を落とす
				ull tmpSum = 0;

				for ( int j = 0; j < N; j++ )
				{
					tmpSum += v[j] ^ tmpK;
				}

				if ( tmpSum > sum )
				{
					// 今回の方が大きくなった＝Kのiビット目は落とした方が良い
					// -> iビット目を落とした以上、i-1, i-2, ... 1ビット目は
					// 好き勝手に選んでもKより大きくならないので、
					// 先ほど求めた「理想のXの値」から流用して良い
					K &= ~( ( 1 << ( i + 1 ) ) - 1 ); 			// iビット目以下を全部落とす
					K |= ( ( ( 1 << ( i + 1 ) ) - 1 ) & X );	// iビット目以下は全部Xにする
					break;
				}
			}
		}
	}
	else
	{
		K = X;	//	理想のXがK以下の条件を満たしているので、そのまま採用する
	}

	ull result = 0;
	for ( int i = 0; i < N; i++ )
	{
		result += v[i] ^ K;
	}

	std::cout << result << std::endl;

	return ( 0 );
}

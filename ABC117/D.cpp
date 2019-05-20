#include <iostream>
#include <vector>
 
using ull = unsigned long long;
using ll = long long;
 
// 1�ɂȂ��Ă���ŏ�ʃr�b�g�����߂�
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
 
// 1�̐������߂�
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
 
// 1�ɂȂ����r�b�g��LSB�����牽�r�b�g�ڂ������߂�
ull tzcnt( ull x )
{
	return ( popcnt( ~x & ( x - 1 ) ) );
}

template<typename T> bool chmax( T &a, T b ) { if ( a < b ) { a = b; return ( true ); } else { return ( false ); } }
 
int main()
{
	ll N, K;
	std::cin >> N >> K;
 
	std::vector<ll> v( N );
	for ( int i = 0; i < N; i++ )
	{
		std::cin >> v[i];
	}

	std::vector<std::vector<ll> > dp( 128, std::vector<ll>( 2, -1 ) );
	dp[0][0] = 0;

	for ( int i = 0; i < 64; i++ )	//	�ォ��i���ڂ�0/1�����߂�
	{
		ll d = 64 - ( i + 1 );
		ll num = 0;
		for ( int j = 0; j < N; j++ )
		{
			if ( v[j] & ( 1LL << d ) )
			{
				num++;
			}
		}

		// d���ڂ�0�̏ꍇ�A1�̏ꍇ���ꂼ��̌���
		ll cost0 = num * ( 1LL << d );
		ll cost1 = ( N - num ) * ( 1LL << d );

		if ( dp[i][1] != -1 )
		{
			// 0/1��Greedy�Ɍ��߂ėǂ�
			chmax( dp[i + 1][1], dp[i][1] + std::max( cost0, cost1 ) );
		}

		if ( dp[i][0] != -1 )
		{
			// K��i�r�b�g�ڂ�1��������AX��i�r�b�g�ڂ�0�ɂ���
			if ( K & ( 1LL << d ) )
			{
				chmax( dp[i + 1][1], dp[i][0] + cost0 );
			}
		}

		if ( dp[i][0] != -1 )
		{
			// K��X��i�r�b�g�ڂ����킹��
			if ( K & ( 1LL << d ) )
			{
				chmax( dp[i + 1][0], dp[i][0] + cost1 );
			}
			else
			{
				chmax( dp[i + 1][0], dp[i][0] + cost0 );
			}
		}
	}

	std::cout << std::max( dp[64][0], dp[64][1] ) << std::endl;

	return ( 0 );
}

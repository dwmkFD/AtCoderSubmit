#include <iostream>
#include <vector>
#include <algorithm>

using ull = unsigned long long;

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
		sum += v[i] ^ K;	//	X == K���œK�̉\��������

		for ( int j = 0; j < 64; j++ )
		{
			// j�r�b�g�ڂ�1�H
			v[i] & ( 1 << j ) ? vv[j]++ : 0;
		}
	}

	// �Ƃ肠�����AK���l�������ɍœK���ۂ�X�����߂�
	ull X = 0;
	for ( int i = 0; i <= tzcnt( getmsb( K ) ); i++ )
	{
		if ( vv[i] < ( N + 1 ) / 2 )
		{
			// i�r�b�g�ڂ�1�ɂȂ��Ă���l�̕������Ȃ��̂�
			// X��i�r�b�g�ڂ�1�ɂ���ׂ�
			X |= ( 1 << i );
		}
	}

	if ( X > K )
	{
		for ( int i = tzcnt( getmsb( K ) ); i >= 0; --i )
		{
			if ( K & ( 1 << i ) )
			{
				ull tmpK = K & ~( 1 << i );	//	i�r�b�g�ڂ𗎂Ƃ�
				ull tmpSum = 0;

				for ( int j = 0; j < N; j++ )
				{
					tmpSum += v[j] ^ tmpK;
				}

				if ( tmpSum > sum )
				{
					// ����̕����傫���Ȃ�����K��i�r�b�g�ڂ͗��Ƃ��������ǂ�
					// -> i�r�b�g�ڂ𗎂Ƃ����ȏ�Ai-1, i-2, ... 1�r�b�g�ڂ�
					// �D������ɑI��ł�K���傫���Ȃ�Ȃ��̂ŁA
					// ��قǋ��߂��u���z��X�̒l�v���痬�p���ėǂ�
					K &= ~( ( 1 << ( i + 1 ) ) - 1 ); 			// i�r�b�g�ڈȉ���S�����Ƃ�
					K |= ( ( ( 1 << ( i + 1 ) ) - 1 ) & X );	// i�r�b�g�ڈȉ��͑S��X�ɂ���
					break;
				}
			}
		}
	}
	else
	{
		K = X;	//	���z��X��K�ȉ��̏����𖞂����Ă���̂ŁA���̂܂܍̗p����
	}

	ull result = 0;
	for ( int i = 0; i < N; i++ )
	{
		result += v[i] ^ K;
	}

	std::cout << result << std::endl;

	return ( 0 );
}

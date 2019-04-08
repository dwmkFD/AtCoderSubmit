#include <iostream>
#include <vector>
#include <algorithm>

long funcABS( long x )
{
	return ( x > 0 ? x : -x );
}

long calc_sad( const std::vector<long> &v, long b )
{
	long total = 0;
	for ( int i = 0; i < v.size(); i++ )
	{
		total += funcABS( v[i] - ( b + ( i + 1 ) ) );
	}

	return ( total );
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

	// ����ό`����ƁA�A�A
	// abs( A_i - i - b )

	// A_i - i ���Ɍv�Z����
	std::vector<long> vA;
	for ( int i = 0; i < N; i++ )
	{
		vA.emplace_back( v[i] - ( i + 1 ) );
	}

	// vA���\�[�g����
	std::sort( vA.begin(), vA.end(), []( long a, long b ) {
			return ( a < b );
		} );

	// �����l�����
	// �����l�́AN�������̏ꍇ��2�ʂ�v�Z���Ă���
	long b = vA[N / 2];

	// �v�Z����
	long sad_value = 0;
	sad_value = calc_sad( v, b );

	if ( ( N & 1 ) == 0 )	//	�����̏ꍇ�͂��������v�Z����
	{
		long sad_value2 = 0;
		long b_even = vA[N / 2 - 1];
		sad_value2 = calc_sad( v, b_even );

		if ( sad_value > sad_value2 )
		{
			std::cout << sad_value2 << std::endl;
		}
		else
		{
			std::cout << sad_value << std::endl;
		}
	}
	else
	{
		std::cout << sad_value << std::endl;
	}

	return ( 0 );
}

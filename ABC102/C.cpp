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

	// ����ό`����ƁA�A�A
	// abs( A_i - i - b )

	// A_i - i ���Ɍv�Z����
	long A_total = 0;
	for ( int i = 0; i < N; i++ )
	{
		A_total += ( v[i] - ( i + 1 ) );
	}

	// A_total - N * b����ԏ������Ȃ�悤��b�����߂�
	// -> A_total / N�ŗǂ��H
	long b = funcABS( A_total ) / N;
	if ( A_total < 0 )
	{
		b *= -1;
		if ( funcABS( A_total ) % N )
		{
			// ���̒l�ŗ]�肪����ꍇ�͐؂�̂ā���Βl��1�傫���Ȃ�
			b -= 1;
		}
	}

	// �v�Z����
	long sad_value = 0;
	for ( int i = 0; i < N; i++ )
	{
		sad_value += funcABS( v[i] - ( b + ( i + 1 ) ) );
	}

	std::cout << sad_value << std::endl;

	return ( 0 );
}

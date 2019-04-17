#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int main()
{
	long long N;
	std::cin >> N;

	std::vector<long long> v;

	while ( N != 0 )	//	�s�b�^��0�ɂȂ�܂Ń��[�v
	{
		long long p = 0;
		long long tmp = 0;
		long long sum = 0;

		if ( N > 0 )
		{
			// -2^p���v�Z����i���̐����j
			while ( N > sum )
			{
				tmp = pow( -2, p );
				sum += tmp;	//	�������킹�Ă���
				p += 2;		//	���̐������l����̂ŁA2����
			}
			v.emplace_back( p - 2 );	//	1��]���ɉ���Ă�̂Œ���
			N -= tmp;
		}
		else
		{
			// -2^p���v�Z����i���̐����j
			p = 1;
			while ( N < sum )
			{
				tmp = pow( -2, p );
				sum += tmp;
				p += 2;
			}
			v.emplace_back( p - 2 );
			N -= tmp;	//	sum�͕��̒l�Ȃ̂ŁA���Z��OK
		}
	}

	// ������-2^p��p�̒l�������ɒT��
	std::vector<int> v_res;
	long long findCounter = 0;
	for ( int i = 0; findCounter < v.size(); i++ )
	{
		auto result = std::find( v.begin(), v.end(), i );
		v_res.emplace_back( result != v.end() ? findCounter++, 1 : 0 );
	}
 
	// ���ʃr�b�g����i�[�����̂ŁA�t���ɏo�͂���
	if ( 0 == findCounter )
	{
		std::cout << "0";	//	0�͓��ʑΉ�
	}
	for ( auto it = v_res.rbegin(); it != v_res.rend(); it++ )
	{
		std::cout << ( *it );
	}
	std::cout << std::endl;

	return ( 0 );
}

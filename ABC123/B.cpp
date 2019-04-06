#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int A, B, C, D, E;
	std::cin >> A >> B >> C >> D >> E;

	std::vector<int> v = { A, B, C, D, E };

	// 1�̈ʂ̒l���傫�����Ƀ\�[�g����
	std::sort( v.begin(), v.end(), []( int a, int b ) {
			return ( a % 10 > b % 10 );
		} );

	// �����1�̈ʂ�0�̂��̂�O�Ɏ����Ă���
	std::sort( v.begin(), v.end(), []( int a, int b ) {
			return ( a % 10 == 0 );
		} );

	int total = 0;
	for ( int i = 0; i < 5; i++ )
	{
		total += v[i];
		int mod = total % 10;

		if ( ( mod != 0 ) && ( i != 4 ) )	//	�Ō�̗v�f�͏��O����
		{
			total += 10 - mod;
		}
	}

	std::cout << total << std::endl;

	return ( 0 );
}

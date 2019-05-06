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
			++negCounter;	//	���̒l�i��0�j�̌����J�E���g���Ă���
		}
	}

	// ��Βl�ɕϊ��������͗�����
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
		// ���̒l����Ȃ�A�ǂ������K�����̒l�Ƃ��Ďc���Ă��܂�
		// ���͂̐�Βl�������\�[�g���āA��ԏ��������̂����𕉂̐��ɂ���
		std::sort( vv.begin(), vv.end() );

		for ( auto &&it : vv )
		{
			result += it;
		}

		// �擪�v�f�������Z����
		result -= vv[0] * 2;	//	1��]���ɑ����Ă�̂�
	}
	else
	{
		// ���̒l�������Ȃ�A�S�����̐��ɂł���̂ŁA���͂̐�Βl�𑫂��ďI���
		for ( auto &&it : vv )
		{
			result += it;
		}
	}

	std::cout << result << std::endl;

	return ( 0 );
}

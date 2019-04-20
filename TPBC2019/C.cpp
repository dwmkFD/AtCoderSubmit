#include <iostream>
#include <string>
#include <vector>

int main()
{
	int N;
	std::string S;
	std::cin >> N >> S;

	std::vector<int> v( N );
	bool color = false;	//	������n�܂�Ƃ��Ă���
	int pos = 0;

	for ( int i = 0; i < S.length(); i++ )
	{
		if ( S[i] == '#' )
		{
			if ( color == false )	//	���Ȃ�F��ς���
			{
				// �F�����ɂ��ăC���f�b�N�X��i�߂�
				color = true;
				++pos;
			}
			v[pos]++;
		}
		else
		{
			if ( color == true )	//	���Ȃ�F��ς���
			{
				// �F�𔒂ɂ��ăC���f�b�N�X��i�߂�
				color = false;
				++pos;
			}
			v[pos]++;
		}
	}

	int TransNum = 0;
	int memoIdx = -1;

	for ( int i = 2; i <= pos; i += 2 )	//	v[2n]�͕K�����̌��in>=0�j�ł���Av[0]�͕ϊ��s�v�Ȃ̂Ŗ������ėǂ�
	{
		if ( v[i] < v[i - 1] )
		{
			// ���̍����̍��̌������g��葽���Ȃ�A������ϊ�����ׂ�
			TransNum += v[i];
			v[i + 1] += ( v[i] + v[i - 1] );	//	���������ɂ����̂ŁA���̔��ɂƂ��Ă̍����̍��̌����ς��
			memoIdx = i;
		}
		else
		{
			// �����łȂ��Ȃ�A�����̍��̕���ϊ�����ׂ�
			TransNum += v[i - 1];
			if ( memoIdx == i - 2 )
			{
				// �O��ϊ������͈͂�ΏۂɑI�񂾏ꍇ
				TransNum -= ( v[i - 2] * 2 );	//	�]���ɉ��Z�����̂ŁA����
			}
		}
	}

	std::cout << TransNum << std::endl;

	return ( 0 );
}

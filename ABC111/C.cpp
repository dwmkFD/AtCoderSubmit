#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using myPair = std::pair<int, int>;

int main()
{
	int n;
	std::cin >> n;

	std::vector<int> v( n );
	for ( int i = 0; i < n; i++ )
	{
		std::cin >> v[i];
	}

	std::map<int, int> m1, m2;
	std::vector<myPair> vv1;
	std::vector<myPair> vv2;
	for ( int i = 0; i < n; i++ )
	{
		if ( i % 2 )
		{
			m1[v[i]]++;
		}
		else
		{
			m2[v[i]]++;
		}
	}

	// �o���p�x�̕����L�[�ɂ�����
	for ( auto it = m1.begin(); it != m1.end(); it++ )
	{
		vv1.emplace_back( std::make_pair( (*it).second, (*it).first ) );
	}
	for ( auto it = m2.begin(); it != m2.end(); it++ )
	{
		vv2.emplace_back( std::make_pair( (*it).second, (*it).first ) );
	}

	// �~���\�[�g����
	std::sort( vv1.begin(), vv1.end(), []( myPair a, myPair b ) {
			return ( a.first > b.first );
		} );
	std::sort( vv2.begin(), vv2.end(), []( myPair a, myPair b ) {
			return ( a.first > b.first );
		} );

	int counter = 0;
	if ( vv1[0].second == vv2[0].second )
	{
		//	�ŕp�o�̒l���_�u����
		// ��F 1 1 1 1 1 2 �Ȃ�
		// ��vvX[0]�������������AvvX[1]�̒l�ɏ���������
		if ( vv1[0].first > vv2[0].first )
		{
			counter += ( ( n / 2 ) - vv2[1].first ); // ���������Ȃ��̂�vv2[1]�̒l
			counter += ( ( n / 2 ) - vv1[0].first ); // ���������Ȃ��̂�vv1[0]�̒l
		}
		else if ( vv1[0].first < vv2[0].first )
		{
			counter += ( ( n / 2 ) - vv1[1].first );
			counter += ( ( n / 2 ) - vv2[0].first );
		}
		else
		{
			// �p�x���ꏏ�̏ꍇ
			if ( vv1[1].first > vv2[1].first )
			{
				counter += ( ( n / 2 ) - vv1[1].first );
				counter += ( ( n / 2 ) - vv2[0].first );
			}
			else
			{
				counter += ( ( n / 2 ) - vv2[1].first );
				counter += ( ( n / 2 ) - vv1[0].first );
			}
		}
	}
	else
	{
		// vv1��vv2�̏�ʗv�f�ȊO�����ׂď���������
		counter += n - ( vv1[0].first + vv2[0].first );
	}

	std::cout << counter << std::endl;

	return ( 0 );
}

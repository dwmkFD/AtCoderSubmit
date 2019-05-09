#include <iostream>
#include <cstdio>
#include <vector>
#include <tuple>
#include <string>
#include <algorithm>

using myTuple = std::tuple<int, int, int>;
using myPair = std::pair<int, std::string>;

int main()
{
	int N, M;
	std::cin >> N >> M;

	std::vector<myTuple> v;
	for ( int i = 0; i < M; i++ )
	{
		int tmpP, tmpY;
		std::cin >> tmpP >> tmpY;
		v.emplace_back( std::make_tuple( tmpP, tmpY, i ) ); // ��Ō��̏��Ԃɖ߂����߂ɃC���f�b�N�X�������
	}

	// �a�������N�㏇�Ƀ\�[�g
	std::sort( v.begin(), v.end(), []( myTuple a, myTuple b ) {
			return ( std::get<1>( a ) < std::get<1>( b ) );
		} );

	// �s��ID���Ƀ\�[�g�i����j
	std::stable_sort( v.begin(), v.end(), []( myTuple a, myTuple b ) {
			return ( std::get<0>( a ) < std::get<0>( b ) );
		} );

	int pCounter = 1;
	std::vector<myPair> vv;

	for ( int i = 0; i < v.size(); i++ )
	{
		char tmpbuf[128] = { 0 };
		sprintf( tmpbuf, "%06d%06d", std::get<0>( v[i] ), pCounter++ );
		vv.emplace_back( std::make_pair( std::get<2>( v[i] ), tmpbuf ) );
		if ( i < v.size() - 1 )
		{
			if ( std::get<0>( v[i] ) != std::get<0>( v[i + 1] ) )
			{
				pCounter = 1;
			}
		}
	}

	// ���̏��Ԃɖ߂��ďo��
	std::sort( vv.begin(), vv.end(), []( myPair a, myPair b ) {
			return ( a.first < b.first );
		} );

	for ( auto &&it : vv )
	{
		std::cout << it.second << std::endl;
	}

	return ( 0 );
}

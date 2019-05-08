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

	// 出現頻度の方をキーにし直す
	for ( auto it = m1.begin(); it != m1.end(); it++ )
	{
		vv1.emplace_back( std::make_pair( (*it).second, (*it).first ) );
	}
	for ( auto it = m2.begin(); it != m2.end(); it++ )
	{
		vv2.emplace_back( std::make_pair( (*it).second, (*it).first ) );
	}

	// 降順ソートする
	std::sort( vv1.begin(), vv1.end(), []( myPair a, myPair b ) {
			return ( a.first > b.first );
		} );
	std::sort( vv2.begin(), vv2.end(), []( myPair a, myPair b ) {
			return ( a.first > b.first );
		} );

	int counter = 0;
	if ( vv1[0].second == vv2[0].second )
	{
		//	最頻出の値がダブった
		// 例： 1 1 1 1 1 2 など
		// →vvX[0]が小さい方を、vvX[1]の値に書き換える
		if ( vv1[0].first > vv2[0].first )
		{
			counter += ( ( n / 2 ) - vv2[1].first ); // 書き換えないのはvv2[1]の値
			counter += ( ( n / 2 ) - vv1[0].first ); // 書き換えないのはvv1[0]の値
		}
		else if ( vv1[0].first < vv2[0].first )
		{
			counter += ( ( n / 2 ) - vv1[1].first );
			counter += ( ( n / 2 ) - vv2[0].first );
		}
		else
		{
			// 頻度も一緒の場合
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
		// vv1とvv2の上位要素以外をすべて書き換える
		counter += n - ( vv1[0].first + vv2[0].first );
	}

	std::cout << counter << std::endl;

	return ( 0 );
}

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <bitset>
#include <tuple>
#include <cmath>
#include <map>

template<typename T> bool chmax( T &a, T b ) { if ( a < b ) { a = b; return ( true ); } else { return ( false ); } }
template<typename T> bool chmin( T &a, T b ) { if ( a > b ) { a = b; return ( true ); } else { return ( false ); } }

using namespace std;

using ll = long long;
using ull = unsigned long long;

using Pll  = pair<ll, ll>;
using Pull = pair<ull, ull>;

#define eb emplace_back
#define pb push_back
#define mp( a, b ) make_pair( a, b )
#define mt( ... ) make_tuple( __VA_ARGS__ )

#define F first
#define S second

#define rep( i, n ) for ( int i = 0; i < (int)( n ); ++i )
#define reps( i, n ) for ( int i = 1; i <= (int)( n ); ++i )
#define rrep( i, n ) for ( int i = (int)( ( n ) - 1 ); i >= 0; --i )
#define rreps( i, n ) for ( int i = (int)( ( n ) ); i > 0; --i )

#define ALL( c ) ( c ).begin(), ( c ).end()
#define RALL( c ) ( c ).rbegin(), ( c ).rend()

#define MOD ( (ll)( 1e9 + 7 ) )

int main()
{
	int N, M;
	cin >> N >> M;

	int k;
	vector<vector<int>> s( M );
	vector<bitset<10>> b( M );
	rep( i, M )
	{
		cin >> k;
		s[i].resize( k );
		rep( j, k )
		{
			// 各電球についてのマスクビットを作る
			cin >> s[i][j];
			b[i].set( s[i][j] - 1 );
		}
	}

	vector<int> p( M );
	rep( i, M )
	{
		cin >> p[i];
	}

	ll count = 0;
	const int loop = pow( 2, N );
	rep( i, loop )
	{
		bool chk = true;
		rep( j, M )
		{
			bitset<10> tmp = i;
			auto res = b[j] & tmp;
			if ( ( res.count() % 2 ) != p[j] )
			{
				chk = false;
				break;
			}
		}
		if ( chk ) count++;
	}

	cout << count << endl;

	return ( 0 );
}

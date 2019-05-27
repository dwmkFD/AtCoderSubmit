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
	int N, K;
	cin >> N >> K;

	string S;
	cin >> S;

	vector<int> v;
	v.eb( 0 );	//	最初の始点
	reps( i, N - 1 )
	{
		if ( S[i] != S[i - 1] )
		{
			v.eb( i );
		}
	}
	v.eb( N );

	vector<int> max;
	rep( i, v.size() )
	{
		if ( S[v[i]] == '0' )
		{
			if ( i + 2 * K > v.size() - 1 )
			{
				// K回も操作をしなくても残り全部1になる場合
				max.eb( N - v[i] );
				break;
			}
			else
			{
				max.eb( v[i + 2 * K] - v[i] );
			}
		}
		else
		{
			if ( i + 2 * K + 1 > v.size() - 1 )
			{
				max.eb( N - v[i] );
				break;
			}
			else
			{
				max.eb( v[i + 2 * K + 1] - v[i] );
			}
		}
	}

	int result = 1;
	for ( auto &&it : max )
	{
		chmax( result, it );
	}

	cout << result << endl;

	return ( 0 );
}

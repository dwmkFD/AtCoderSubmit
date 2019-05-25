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

#define MOD ( 1e9 + 7 )


int main()
{
	ll N, M;
	cin >> N >> M;

	vector<ll> v( N );
	rep( i, N )
	{
		cin >> v[i];
	}

	vector<Pll> vv( M );
	rep( i, M )
	{
		cin >> vv[i].F >> vv[i].S;
	}

	// Aiの昇順にソート
	sort( ALL( v ) );

	// Cの値で降順ソート
	sort ( ALL( vv ), []( Pll a, Pll b ) {
			return ( a.S > b.S );
		} );

	ll ptr = 0;
	rep( i, M )
	{
		// vは値の昇順にソートされているので、前から書き換えて行けばOK
		rep( j, vv[i].F )
		{
			if ( v[ptr] < vv[i].S )
			{
				v[ptr++] = vv[i].S;
			}
			else
			{
				goto end;
			}
		}
	}
end:

	ll sum = 0;
	for ( auto &&it : v )
	{
		sum += it;
	}

	cout << sum << endl;

	return ( 0 );
}

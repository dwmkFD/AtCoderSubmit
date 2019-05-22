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
#define F first
#define S second
#define mp( a, b ) make_pair( a, b )
#define mt( ... ) make_tuple( __VA_ARGS__ )

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

	vector<Pll> v( N );
	rep( i, N )
	{
		ll a, b;
		cin >> a >> b;
		v[i] = { a, b };
	}

	sort( ALL( v ), []( Pll a, Pll b ) {
			return( a.F < b.F );
		} );

	ll num = 0;
	ll cost = 0;
	rep( i, N )
	{
		if ( num + v[i].S < M )
		{
			cost += v[i].F * v[i].S;
			num += v[i].S;
		}
		else
		{
			cost += v[i].F * ( M - num );
			break;
		}
	}

	cout << cost << endl;

	return ( 0 );
}

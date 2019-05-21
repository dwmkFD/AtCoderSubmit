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

#define rep( i, n ) for ( int i = 0; i < (int)( n ); ++i )
#define reps( i, n ) for ( int i = 1; i <= (int)( n ); ++i )
#define rrep( i, n ) for ( int i = (int)( ( n ) - 1 ); i >= 0; --i )
#define rreps( i, n ) for ( int i = (int)( ( n ) ); i > 0; --i )

#define ALL( c ) ( c ).begin(), ( c ).end()
#define RALL( c ) ( c ).rbegin(), ( c ).rend()

#define MOD ( 1e9 + 7 )

#define INF  ( 1e12 )
#define MINF ( -1e12 )

int main()
{
	int A, B, Q;
	cin >> A >> B >> Q;

	vector<ll> vS( A + 2 );
	rep( i, A )
	{
		cin >> vS[i];
	}

	vector<ll> vT( B + 2 );
	rep( i, B )
	{
		cin >> vT[i];
	}

	vector<ll> vX( Q );
	rep( i, Q )
	{
		cin >> vX[i];
	}

	// vS, vT に正負の無限遠の点を入れておく
	vS[A] = MINF; vS[A + 1] = INF;
	vT[B] = MINF; vT[B + 1] = INF;

	sort( ALL( vS ) ); sort( ALL( vT ) );

	for ( auto &&it : vX )
	{
		// 問itに対して、一番近い左右の寺2社2を求める
		auto AB = upper_bound( ALL( vS ), it );
		ll sB = *AB;
		ll sA = *prev( AB );

		auto CD = upper_bound( ALL( vT ), it );
		ll tD = *CD;
		ll tC = *prev( CD );

		/* 上記4箇所の訪れ方の最小値を求める */
		// 1. A -> C
		ll ac = abs( sA - it ) + abs( tC - sA );

		// 2. A -> D
		ll ad = abs( sA - it ) + abs( tD - sA );

		// 3. C -> A
		ll ca = abs( tC - it ) + abs( sA - tC );

		// 4. D -> A
		ll da = abs( tD - it ) + abs( sA - tD );

		// 5. B -> C
		ll bc = abs( sB - it ) + abs( tC - sB );

		// 6. B -> D
		ll bd = abs( sB - it ) + abs( tD - sB );

		// 7. C -> B
		ll cb = abs( tC - it ) + abs( sB - tC );

		// 8. D -> B
		ll db = abs( tD - it ) + abs( sB - tD );

		cout << min( { ac, ad, ca, da, bc, bd, cb, db } ) << endl;
	}

	return ( 0 );
}

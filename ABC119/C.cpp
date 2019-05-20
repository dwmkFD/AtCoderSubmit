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
#define INF ( 1e9 )
#define MINF ( -1e9 )

int N, A, B, C;
vector<int> v;

int solv( int n, int a, int b, int c )
{
	if ( n == N )
	{
		if ( min( { a, b, c } ) > 0 )
		{
			return ( abs( A - a ) + abs( B - b ) + abs( C - c ) - 30 );
		}
		else
		{
			return ( INF );
		}
	}

	int r0 = solv( n + 1, a, b, c );
	int r1 = solv( n + 1, a + v[n], b, c ) + 10;
	int r2 = solv( n + 1, a, b + v[n], c ) + 10;
	int r3 = solv( n + 1, a, b, c + v[n] ) + 10;

	return ( min( { r0, r1, r2, r3 } ) );
}

int main()
{
	cin >> N >> A >> B >> C;

	rep( i, N )
	{
		int tmp;
		cin >> tmp;
		v.eb( tmp );
	}

	cout << solv( 0, 0, 0, 0 ) << endl;

	return ( 0 );
}

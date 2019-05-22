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

int main()
{
	ll A, B;
	cin >> A >> B;

	// a ^ ( a + 1 ) == 1を利用する
	// また、a ^ a = 0から、F( A, B ) = F( 0, A - 1) ^ F( 0, B )である
	// -> ( 0 ^ 1 ^ 2 ^ ... (A - 1) ) ^ ( 0 ^ 1 ^ 2 ^ ... (A - 1) ^ A ^ ... B )
	//    となるので、 ( 0 ^ 0 ) ^ ( 1 ^ 1 ) ^ ... となり、(A-1)までは全て0となる
	ll rA = ( ( A / 2 ) % 2 );
	if ( A % 2 )
	{
		// 最大の偶数が残る
		rA ^= ( A - 1 );
	}

	ll rB = ( ( ( B + 1 ) / 2 ) % 2 );
	if ( ( B % 2 ) == 0 )
	{
		rB ^= B;
	}

	cout << ( rA ^ rB ) << endl;

	return ( 0 );
}

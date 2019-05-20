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

#define ep emplace_back
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

long gcd( long a, long b )
{
	return ( b == 0 ? a : gcd( b, a % b ) );
}

int main()
{
	int N;
	cin >> N;

	vector<int> v( N );
	rep( i, N )
	{
		cin >> v[i];
	}

	// Å‘åŒö–ñ”‚ğ‹‚ß‚ê‚ÎOKH
	long result = 1e9 + 1;
	rep( i, N - 1 )
	{
		chmin( result, gcd( v[i], v[i + 1] ) );
	}

	cout << result << endl;

	return ( 0 );
}

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
	ll N, Q;
	string S;
	cin >> N >> Q;
	cin >> S;

	vector<Pll> v( Q );
	rep( i, Q )
	{
		cin >> v[i].F >> v[i].S;
	}

	vector<ll> vv( N + 1 );
	vv[0] = 0;
	reps( i, N - 1 )
	{
		vv[i] = vv[i - 1];
		if ( S[i] == 'C' )
		{
			if ( S[i - 1] == 'A' )
			{
				vv[i] += 1;
			}
		}
	}

	rep( i, Q )
	{
		cout << ( vv[v[i].S - 1] - vv[v[i].F - 1] ) << endl;
	}

	return ( 0 );
}

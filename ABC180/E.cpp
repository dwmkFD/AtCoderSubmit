#include <algorithm>
#include <iostream>
#include <iomanip>
#include <numeric>
#include <vector>
#include <string>
#include <bitset>
#include <stack>
#include <queue>
#include <tuple>
#include <regex>
#include <cmath>
#include <map>
#include <set>
#include <functional>
#include <cstring>

using namespace std;

template<typename T> bool chmax( T &a, const T b ) { if ( a < b ) { a = b; return ( true ); } else { return ( false ); } }
template<typename T> bool chmin( T &a, const T b ) { if ( a > b ) { a = b; return ( true ); } else { return ( false ); } }

using ll = long long;
using Pint = pair<int, int>;
using Pll  = pair<ll, ll>;

#define eb emplace_back
#define pb push_back
#define mp make_pair

#define F first
#define S second

#define popcnt __builtin_popcountll

#define rep( i, n ) for ( ll i = 0; i < (ll)( n ); ++i )
#define reps( i, n ) for ( ll i = 1; i <= (ll)( n ); ++i )
#define rrep( i, n ) for ( ll i = (ll)( ( n ) - 1 ); i >= 0; --i )
#define rreps( i, n ) for ( ll i = (ll)( ( n ) ); i > 0; --i )
#define arep( i, v ) for ( auto &&i : ( v ) )

#define ALL( c ) ( c ).begin(), ( c ).end()
#define RALL( c ) ( c ).rbegin(), ( c ).rend()
#define UNIQUE( c ) ( c ).erase( unique( ( c ).begin(), ( c ).end() ), ( c ).end() )

template<typename T = ll> constexpr T MAX = numeric_limits<T>::max();
template<typename T> T gcd( const T a, const T b ) { return ( b ? gcd( b, a % b ) : a ); }
template<typename T> T lcm( const T a, const T b ) { return ( a / gcd( a, b ) * b ); }

struct Edge {
	int to, cost;
	Edge( int t = 0, int c = 0 ) {
		to = t; cost = c;
	}
};

int main()
{
	ll n; cin >> n;
	vector<int> x( n ), y( n ), z( n );
	rep( i, n ) cin >> x[i] >> y[i] >> z[i];

	constexpr int inf = 1e9;
	vector<vector<int>> dp( 1 << n, vector<int>( n, -1 ) );
	vector<vector<int>> cost( n, vector<int>( n, inf ) );
	rep( i, n )
	{
		for ( ll j = i + 1; j < n; ++j )
		{
			int c = abs( x[i] - x[j] ) + abs( y[i] - y[j] );
			int c1 = c + max( 0, z[j] - z[i] );
			int c2 = c + max( 0, z[i] - z[j] );
			cost[i][j] = c1;
			cost[j][i] = c2;
		}
	}

	auto dfs = [&]( auto &&dfs, int s, int v ) -> int {
		if ( dp[s][v] >= 0 )
			return ( dp[s][v] );
		if ( s == ( 1 << n ) - 1 && v == 0 )
			return ( dp[s][v] = 0 );

		int res = inf;
		rep( u, n )
		{
			if ( ( ( s >> u ) & 1 ) == 0 )
				chmin( res, dfs( dfs, s | ( 1 << u ), u ) + cost[v][u] );
		}

		dp[s][v] = res;
		return ( res );
	};

	cout << dfs( dfs, 0, 0 ) << endl;

	return ( 0 );
}

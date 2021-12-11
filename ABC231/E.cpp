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

template<typename T> bool chmax( T &a, const T b ) { if ( a <= b ) { a = b; return ( true ); } else { return ( false ); } }
template<typename T> bool chmin( T &a, const T b ) { if ( a >= b ) { a = b; return ( true ); } else { return ( false ); } }

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


int main()
{
	ll n, x; cin >> n >> x;
	vector<ll> a( n );
	rep( i, n ) cin >> a[i];

	auto dfs = [&]( auto &&dfs, ll pay, ll cnt ) -> ll {
		auto dfs2 = [&]( auto &&dfs2, ll pay, ll i ) -> ll {
			ll result = 0, result2 = 0;
			if ( i == 0 ) return ( pay );
			if ( a[i] > pay ) result += dfs2( dfs2, pay, i - 1 );
			else
			{
				result = ( pay / a[i] ) + dfs2( dfs2, pay % a[i], i - 1 );
				result2 = dfs2( dfs2, pay, i - 1 );
				chmin( result, result2 );
			}
			return ( result );
		};
		ll res = 1e18, res2 = 0;
		auto it = lower_bound( ALL( a ), pay );
		if ( it == a.end() ) it--;
		ll y = *it - pay;

		ll idx = distance( a.begin(), it );
		if ( y > 0 )
			res = dfs( dfs, y, cnt + 1 );
		res2 = dfs2( dfs2, pay, idx );
		chmin( res, res2 );

		return ( res );
	};

	cout << dfs( dfs, x, 0 ) << endl;

	return ( 0 );
}

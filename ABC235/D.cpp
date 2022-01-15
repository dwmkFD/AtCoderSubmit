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
	ll a, n; cin >> a >> n;
	vector<ll> dp( 1e6 + 10, 1e18 );
	dp[1] = 0;

	auto calc_ = []( ll x ) {
		ll res = 0;
		do {
			x /= 10;
			++res;
		} while ( x > 0 );
		return ( res );
	};

	auto calc1 = [calc_]( ll x ) {
		ll t1 = calc_( x ) - 1;
		ll t2 = pow( 10, t1 );
		ll y = ( x / t2 ) + ( x % t2 ) * 10;
		return ( y );
	};
	auto calc2 = [calc_]( ll x ) {
		ll t1 = calc_( x ) - 1;
		ll t2 = pow( 10, t1 );
		ll y = ( x % 10 ) * t2 + x / 10;
		return ( y );
	};

	rep( _, 10 )
	{
	for ( ll i = 1; i * a <= n; i *= a )
	{
		chmin( dp[i * a], dp[i] + 1 );
	}

	reps( i, 1e6 )
	{
		if ( dp[i] < 1e18 && i > 10 && i % 10 != 0 )
		{
			ll idx = calc2( i );
			chmin( dp[idx], dp[i] + 1 );
		}
	}
	}
	if ( dp[n] < 1e18 )
		cout << dp[n] << endl;
	else
		cout << -1 << endl;

	return ( 0 );
}

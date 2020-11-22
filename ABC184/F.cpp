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
	ll n, t; cin >> n >> t;
	vector<ll> a( n );
	rep( i, n ) cin >> a[i];
	if ( n % 2 ) a.pb( t + 1 );

	vector<ll> v1, v2;
	for ( ll bit = 0; bit < ( 1 << n / 2 ); ++bit )
	{
		ll sum = 0;
		rep( i, n / 2 )
		{
			if ( bit & ( 1 << i ) )
				sum += a[i];
		}
		v1.pb( sum );
	}
	for ( ll bit = 0; bit < ( 1 << ( n + 1 ) / 2 ); ++bit )
	{
		ll sum = 0;
		rep( i, ( n + 1 ) / 2 )
		{
			if ( bit & ( 1 << i ) )
				sum += a[n / 2 + i];
		}
		v2.pb( sum );
	}

	sort( ALL( v2 ) );
//	arep( it, v2 ) cout << it << " "; cout << endl;
	ll ans = 0;
	arep( it, v1 )
	{
		if ( t - it >= 0 )
			chmax( ans, it + *( upper_bound( ALL( v2 ), t - it ) - 1 ) );
	}

	cout << ans << endl;

	return ( 0 );
}

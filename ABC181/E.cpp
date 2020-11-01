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
	ll n, m; cin >> n >> m;
	vector<ll> h( n ), w( m );
	rep( i, n ) cin >> h[i];
	rep( i, m ) cin >> w[i];

	sort( ALL( h ) );
	vector<ll> d1, d2;
	rep( i, n / 2 )
	{
		d1.pb( h[i * 2 + 1] - h[i * 2] );
		d2.pb( h[n - 1 - i * 2] - h[n - 1 - i * 2 - 1] );
	}
	reverse( ALL( d2 ) );
	vector<ll> d1s( n ), d2s( n );
	rep( i, d1.size() )
	{
		d1s[i + 1] = d1s[i] + d1[i];
		d2s[i + 1] = d2s[i] + d2[i];
	}

	ll ans = 1e18;
	rep( i, m )
	{
		auto it = upper_bound( ALL( h ), w[i] );
		ll idx = it - h.begin();
		ll tmp = 0;
		tmp += d1s[idx / 2];
		tmp += ( d2s[d2.size()] - d2s[idx / 2] );
		if ( idx % 2 )
			tmp += abs( h[idx - 1] - w[i] );
		else
			tmp += abs( w[i] - h[idx] );
		chmin( ans, tmp );
	}

	cout << ans << endl;

	return ( 0 );
}

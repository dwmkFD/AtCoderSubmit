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
	ll n; cin >> n;
	vector<ll> a( 3 * n );
	rep( i, 3 * n ) cin >> a[i];

	ll ans = 0;
	for ( ll i = 3 * n - 1; i >= 5; i -= 3 )
	{
		vector<ll> vv;
		for ( ll j = i - 5; j < i; ++j )
			vv.eb( a[j] );
		sort( ALL( vv ) );
		if ( vv[0] == vv[2] )
		{
			++ans;
			a[i - 5] = vv[3];
			a[i - 4] = vv[4];
		}
		else if ( vv[1] == vv[3] )
		{
			++ans;
			a[i - 5] = vv[0];
			a[i - 4] = vv[4];
		}
		else if ( vv[2] == vv[4] )
		{
			++ans;
			a[i - 5] = vv[0];
			a[i - 4] = vv[1];
		}
	}

	if ( a[0] == a[1] && a[1] == a[2] )
		++ans;

	cout << ans << endl;

	return ( 0 );
}

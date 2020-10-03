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
	string s; cin >> s;
	vector<ll> a( n + 1 ), t( n + 1 ), c( n + 1 ), g( n + 1 );
	rep( i, n )
	{
		switch ( s[i] )
		{
		case 'A':
			a[i + 1] = a[i] + 1; t[i + 1] = t[i];
			c[i + 1] = c[i]; g[i + 1] = g[i];
			break;
		case 'T':
			a[i + 1] = a[i]; t[i + 1] = t[i] + 1;
			c[i + 1] = c[i]; g[i + 1] = g[i];
			break;
		case 'C':
			a[i + 1] = a[i]; t[i + 1] = t[i];
			c[i + 1] = c[i] + 1; g[i + 1] = g[i];
			break;
		case 'G':
			a[i + 1] = a[i]; t[i + 1] = t[i];
			c[i + 1] = c[i]; g[i + 1] = g[i] + 1;
			break;
		}
	}

	ll ans = 0;
	for ( ll i = 0; i < n; ++i )
	{
		for ( ll j = i + 1; j <= n; ++j )
		{
			ll an = a[j] - a[i];
			ll tn = t[j] - t[i];
			ll cn = c[j] - c[i];
			ll gn = g[j] - g[i];


			ll x = min( { an, tn, cn, gn } );
			ll y = max( { an, tn, cn, gn } );

			if ( x == y && x > 0 )
				ans += 1;
			else
			{
				if ( an == tn && cn == gn )
						ans += 1;
			}

//			cout << an << ", " << tn << ", " << cn << ", " << gn << endl;
//			cout << s.substr( i, j - i ) << " : " << ans << endl;
		}
	}

	cout << ans << endl;

	return ( 0 );
}

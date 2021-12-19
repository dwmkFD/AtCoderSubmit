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
	vector<vector<ll>> g( n, vector<ll>( n, 0 ) );
	vector<vector<ll>> h( n, vector<ll>( n, 0 ) );
	rep( i, m )
	{
		ll a, b; cin >> a >> b;
		--a; --b;
		g[a][b] = g[b][a] = 1;
	}
	rep( i, m )
	{
		ll a, b; cin >> a >> b;
		--a; --b;
		h[a][b] = h[b][a] = 1;
	}

	vector<ll> v( n );
	iota( ALL( v ), 0 );
	do {
		bool ok = true;
		rep( i, n )
		{
			if ( ok == false ) break;
			for ( ll j = i + 1; j < n; ++j )
			{
				if ( g[i][j] != h[v[i]][v[j]] )
				{
					ok = false;
					break;
				}
			}
		}
		if ( ok )
		{
			cout << "Yes" << endl;
			return ( 0 );
		}
	} while ( next_permutation( ALL( v ) ) );

	cout << "No" << endl;

	return ( 0 );
}

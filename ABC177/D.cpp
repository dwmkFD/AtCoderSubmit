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

template<typename T = ll> struct UnionFind {
	vector<T> par;

	UnionFind( T n ) : par( n, -1 ) {}

	void init( T n ) { par.assign( n, -1 ); }
	T find( T x ) {
		if ( par[x] < 0 ) return ( x );
		else return ( par[x] = find( par[x] ) );
	}
	bool isSame( T x, T y ) {
		return ( find( x ) == find( y ) );
	}
	bool unite( T x, T y ) {
		x = find( x ); y = find( y );
		if ( x == y ) return ( false );
		if ( par[x] > par[y] ) swap( x, y );
		par[x] += par[y];
		par[y] = x;
		return ( true );
	}
	T size( T x ) { return ( -par[find( x )] ); }
};


int main()
{
	ll n, m; cin >> n >> m;
	UnionFind<ll> uf( n + 10 );

	rep( i, m )
	{
		ll a, b; cin >> a >> b;
		uf.unite( a, b );
	}

	ll ans = 0;
	rep( i, n )
	{
		chmax( ans, uf.size( i + 1 ) );
	}

	cout << ans << endl;

	return ( 0 );
}

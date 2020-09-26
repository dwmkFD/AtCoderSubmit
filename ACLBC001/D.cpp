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

template<typename Monoid, typename T = ll> struct SegTree {
	using Func = function<Monoid( Monoid, Monoid )>;
	const Func func;
	const Monoid UNITY;
	T SIZE_R;
	vector<Monoid> data;

	SegTree( T n, const Func f, const Monoid &unity ) :
		func( f ), UNITY( unity ) {
			init( n );
		}

	void init( T n ) {
		SIZE_R = 1;
		while ( SIZE_R < n ) SIZE_R *= 2;
		data.assign( SIZE_R * 2, UNITY );
	}

	void set( T idx, const Monoid &val ) { data[idx + SIZE_R] = val; }
	void build() {
		for ( T k = SIZE_R - 1; k > 0; --k )
			data[k] = func( data[k * 2], data[k * 2 + 1] );
	}

	void update( T idx, const Monoid &val ) {
		T k = idx + SIZE_R;
		data[k] = val;
		while ( k >>= 1 ) data[k] = func( data[k * 2], data[k * 2 + 1] );
	}

	Monoid get( T a, T b ) {
		Monoid vleft = UNITY, vright = UNITY;
		for ( T left = a + SIZE_R, right = b + SIZE_R;
			  left < right;
			  left >>= 1, right >>= 1 ) {
			if ( left & 1 ) vleft = func( vleft, data[left++] );
			if ( right & 1 ) vright = func( data[--right], vright );
		}

		return ( func( vleft, vright ) );
	}

	inline Monoid operator[]( ll idx ) { return ( data[idx + SIZE_R] ); }
};


int main()
{
	ll n, k; cin >> n >> k;
	vector<ll> a( n );
	rep( i, n ) cin >> a[i];


	return ( 0 );
}

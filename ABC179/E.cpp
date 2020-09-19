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

template<typename T> struct Fp {
	T val, MOD;

	constexpr Fp( T input = 0, T MOD = 1e9 + 7 ) noexcept : val( input % MOD ) {
		if ( val < 0 ) val += MOD;
		this->MOD = MOD;
	}
	constexpr T getmod() { return ( MOD ); }
	constexpr Fp operator-() const noexcept {
		return ( val ? MOD - val : 0 );
	}
	constexpr Fp operator+( const Fp &r ) const noexcept { return ( ( Fp( *this ) += r ) ); }
	constexpr Fp operator-( const Fp &r ) const noexcept { return ( ( Fp( *this ) -= r ) ); }
	constexpr Fp operator*( const Fp &r ) const noexcept { return ( ( Fp( *this ) *= r ) ); }
	constexpr Fp operator/( const Fp &r ) const noexcept { return ( ( Fp( *this ) /= r ) ); }

	constexpr Fp &operator+=( const Fp &r ) noexcept {
		val += r.val;
		if ( val >= MOD ) val -= MOD;
		return ( *this );
	}

	constexpr Fp &operator-=( const Fp &r ) noexcept {
		val -= r.val;
		if ( val < 0 ) val += MOD;
		return ( *this );
	}

	constexpr Fp &operator*=( const Fp &r ) noexcept {
		val = ( val * r.val ) % MOD;
		return ( *this );
	}

	constexpr Fp &operator/=( const Fp &r ) noexcept {
		T a = r.val, b = MOD, u = 1, v = 0;
		while ( b ) {
			T t = a / b;
			a -= t * b; swap( a, b );
			u -= t * v; swap( u, v );
		}
		val = ( val * u ) % MOD;
		if ( val < 0 ) val += MOD;
		return ( *this );
	}

	constexpr bool operator==( const Fp &r ) noexcept {
		return ( val == r.val );
	}

	constexpr bool operator!=( const Fp &r ) noexcept {
		return ( val != r.val );
	}

	friend constexpr ostream& operator<<( ostream &os, const Fp<T>&x ) noexcept {
		return ( os << x.val );
	}

	friend constexpr Fp<T> modpow( const Fp<T> &a, T n ) noexcept {
		if ( n == 0 ) return ( 1 );
		auto t = Fp<T>( modpow( a, n / 2 ).val, a.MOD );
		t *= t;
		if ( n & 1 ) t *= a;
        return ( t );
	}
};

using mint = Fp<ll>;


int main()
{
	ll n, x, m;
	cin >> n >> x >> m;

	mint X( x, m );
	mint val( 2LL, m );
	val = mint( modpow( val, 2 * n - 1 ).val, m );
	X = mint( modpow( X, val.val ).val, m );

	mint ans( ( ( ( X + x ) * n ) / 2 ).val , m );
	cout << ans << endl;

	return ( 0 );
}

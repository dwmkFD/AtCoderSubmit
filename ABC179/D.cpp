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

template<typename T, T MOD> struct Fp {
	T val;

	constexpr Fp( T input = 0 ) noexcept : val( input % MOD ) {
		if ( val < 0 ) val += MOD;
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

	friend constexpr ostream& operator<<( ostream &os, const Fp<T, MOD>&x ) noexcept {
		return ( os << x.val );
	}

	friend constexpr Fp<T, MOD> modpow( const Fp<T, MOD> &a, T n ) noexcept {
		if ( n == 0 ) return ( 1 );
		auto t = modpow( a, n / 2 );
		t = t * t;
		if ( n & 1 ) t = t * a;
        return ( t );
	}
};

template<typename T, T MOD> struct BiCoef {
	using mint = Fp<T, MOD>;
	vector<mint> fact_, inv_, finv_;

	constexpr BiCoef() {}
	constexpr BiCoef( T n ) noexcept :
		fact_( n, 1 ), inv_( n, 1 ), finv_( n, 1 )
	{
		init( n );
	}

	constexpr void init( T n ) {
		fact_.assign( n, 1 ); inv_.assign( n, 1 ); finv_.assign( n, 1 );
		for ( T i = 2; i < n; i++ ) {
			fact_[i] = fact_[i - 1] * i;
			inv_[i] = -inv_[MOD % i] * ( MOD / i );
			finv_[i] = finv_[i - 1] * inv_[i];
       }
    }

    constexpr mint comb( T n, T k ) const noexcept {
		if ( n < k || n < 0 || k < 0 ) return ( 0 );
		if ( n - k < k ) k = n - k;
		return ( fact_[n] * finv_[k] * finv_[n - k] );
    }

    constexpr mint fact( T n ) const noexcept {
		if ( n < 0 ) return ( 0 );
		return ( fact_[n] ) ;
    }

    constexpr mint inv( T n ) const noexcept {
		if ( n < 0 ) return ( 0 );
		return ( inv_[n] );
    }

    constexpr mint finv( T n ) const noexcept {
		if ( n < 0 ) return ( 0 );
		return ( finv_[n] );
    }
};

constexpr ll MOD = 1000000007LL;
using mint = Fp<ll, MOD>;


int main()
{
	ll n, K; cin >> n >> K;
	vector<ll> l( K ), r( K );
	rep( i, K ) cin >> l[i] >> r[i];

	vector<mint> dp( n * 2 + 10 );

	return ( 0 );
}

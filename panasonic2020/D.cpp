#include <algorithm>
#include <iostream>
#include <iomanip>
#include <numeric>
#include <vector>
#include <string>
#include <bitset>
#include <queue>
#include <tuple>
#include <regex>
#include <cmath>
#include <map>
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
#define mt make_tuple

#define F first
#define S second

#define rep( i, n ) for ( int i = 0; i < (int)( n ); ++i )
#define reps( i, n ) for ( int i = 1; i <= (int)( n ); ++i )
#define rrep( i, n ) for ( int i = (int)( ( n ) - 1 ); i >= 0; --i )
#define rreps( i, n ) for ( int i = (int)( ( n ) ); i > 0; --i )
#define arep( i, v ) for ( auto &&i : ( v ) )

#define ALL( c ) ( c ).begin(), ( c ).end()
#define RALL( c ) ( c ).rbegin(), ( c ).rend()
#define UNIQUE( c ) ( c ).erase( unique( ( c ).begin(), ( c ).end() ), ( c ).end() )

template<typename T = ll> constexpr T MAX = numeric_limits<T>::max();
template<typename T> T gcd( const T a, const T b ) { return ( b ? gcd( b, a % b ) : a ); }
template<typename T> T lcm( const T a, const T b ) { return ( a / gcd( a, b ) * b ); }

template<typename T = ll> struct UnionFind {
	vector<T> par, siz;

	UnionFind( T n ) {
		par.resize( n ); siz.resize( n );
		rep( i, n ) {
			par[i] = i; siz[i] = 1;
		}
	}

	T find( T x ) {
		if ( x == par[x] )
			return ( x );
		else
			return( par[x] = find( par[x] ) );
	}

	void unite( T x, T y ) {
		T xx = find( x ); T yy = find( y );
		if ( xx == yy ) return;
		if ( siz[xx] <= siz[yy] )
			swap( xx, yy );
		par[yy] = xx;
		siz[xx] += siz[yy];
	}
};

template<typename T = ll> class CompareMax {
public:	T operator()( T a, T b ) { return ( max( a, b ) ); }
};
template<typename T = ll> class CompareMin {
public:	T operator()( T a, T b ) { return ( min( a, b ) ); }
};

template<typename T = ll, typename F = CompareMax<T>, T I = 0> struct SegTree {
	T N; F func; vector<T> v;

	SegTree( T n ) {
		N = n; v.resize( 4 * n );
		rep( i, 4 * n ) v[i] = I;
	}

	void update( T i, T x ) {
		i += N - 1;
		v[i] = x;
		while ( i > 0 ) {
			i = ( i - 1 ) / 2;
			v[i] = func( v[i * 2 + 1], v[i * 2 + 2] );
		}
	}

	T query( T a, T b, T k, T l, T r ) {
		if ( r <= a || b <= l ) return ( I );
		if ( a <= l && r <= b ) return ( v[k] );
		else {
			T vl = query( a, b, k * 2 + 1, l, ( l + r ) / 2 );
			T vr = query( a, b, k * 2 + 2, ( l + r ) / 2, r );
			return ( func( vl, vr ) );
		}
	}
};

template<typename T = ll> T solveLIS( const vector<T> &v ) {
	vector<T> dp( v.size(), numeric_limits<T>::max() );
	rep( i, v.size() ) {
		*lower_bound( ALL( dp ), v[i] ) = v[i];
	}
	return ( distance( dp.begin(), lower_bound( ALL( dp ), numeric_limits<T>::max() ) ) );
}

template<typename T, T MOD> struct Fp {
	T val;

	constexpr Fp( T input ) noexcept : val( input % MOD ) {
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
BiCoef<ll, MOD> bc;

/*
	regex reg( R"(^(dream|dreamer|erase|eraser)+$)" );
	smatch m;

	if ( regex_match( s, m, reg ) )
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
*/
/*
	cout << setprecision( 16 );
	cout << fixed << setprecision( 16 );
*/

template<typename T = int> vector<T> Zalgo( const string &S ) {
	T N = (T)S.size();
	vector<T> res(N);
	res[0] = N;
	T i = 1, j = 0;
	while ( i < N ) {
		while (i+j < N && S[j] == S[i+j]) ++j;
		res[i] = j;
		if ( j == 0 ) { ++i; continue; }
		int k = 1;
		while ( i + k < N && k + res[k] < j ) res[i + k] = res[k], ++k;
		i += k, j -= k;
	}
	return ( res );
}

void replace( string &s, string t, string r ) {
	string::size_type p = 0;
	while ( ( p = s.find( t, p ) ) != string::npos ) {
		s.replace( p, t.length(), r );
		p += r.length();
	}
}


int main()
{
	ll N; cin >> N;

	string tmp = "";
	rep( i, N ) tmp += 'a';

	if ( N == 1 )
	{
		cout << "a" << endl;
	}
	else if ( N == 2 )
	{
		cout << "aa" << endl;
		cout << "ab" << endl;
	}
	else
	{
		vector<vector<string>> v = {
			{ "a" },
			{ "a", "b" },
			{ "a", "b", "c" },
			{ "a", "b", "c", "d" },
			{ "a", "b", "c", "d", "e" },
			{ "a", "b", "c", "d", "e", "f" },
			{ "a", "b", "c", "d", "e", "f", "g" },
			{ "a", "b", "c", "d", "e", "f", "g", "h" },
			{ "a", "b", "c", "d", "e", "f", "g", "h", "i" },
			{ "a", "b", "c", "d", "e", "f", "g", "h", "i", "j" },
		};
	}

	return ( 0 );
}

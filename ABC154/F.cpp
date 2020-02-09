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

template<typename T> bool chmax( T &a, const T &b ) { if ( a <= b ) { a = b; return ( true ); } else { return ( false ); } }
template<typename T> bool chmin( T &a, const T &b ) { if ( a >= b ) { a = b; return ( true ); } else { return ( false ); } }

using namespace std;

using ll = long long;
using ull = unsigned long long;

using Pint = pair<int, int>;
using Pll  = pair<ll, ll>;
using Pull = pair<ull, ull>;

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

template<typename T> T gcd( const T a, const T b ) { return ( b ? gcd( b, a % b ) : a ); }
template<typename T> T lcm( const T a, const T b ) { return ( a / gcd( a, b ) * b ); }

#define ALL( c ) ( c ).begin(), ( c ).end()
#define RALL( c ) ( c ).rbegin(), ( c ).rend()
#define UNIQUE( c ) ( c ).erase( unique( ( c ).begin(), ( c ).end() ), ( c ).end() )

template<typename T = ll> constexpr T MAX = numeric_limits<T>::max();

#define y0 y3487465
#define y1 y8687969
#define j0 j1347829
#define j1 j234892
#define next asdnext
#define prev asdprev

template<typename T = ll> class UnionFind {
public:
	UnionFind( T n ) { par.resize( n ); siz.resize( n ); rep( i, n ) { par[i] = i; siz[i] = 1; } }
	T find( T x ) { if ( x == par[x] ) return ( x ); else return( par[x] = find( par[x] ) ); }
	void unite( T x, T y ) { T xx = find( x ); T yy = find( y ); if ( xx == yy ) return;
		if ( siz[xx] <= siz[yy] ) swap( xx, yy ); par[yy] = xx; siz[xx] += siz[yy]; }
private:
	vector<T> par, siz;
};

template<typename T = ll> class CompareMax {
public:	T operator()( T a, T b ) { return ( max( a, b ) ); }
};
template<typename T = ll> class CompareMin {
public:	T operator()( T a, T b ) { return ( min( a, b ) ); }
};

template<typename T = ll, typename F = CompareMax<T>, T I = 0> class SegTree {
public:
	SegTree( T n ) { N = n; v.resize( 4 * n ); rep( i, 4 * n ) v[i] = I; }
	void update( T i, T x ) { i += N - 1; v[i] = x; while ( i > 0 ) {
			i = ( i - 1 ) / 2; v[i] = func( v[i * 2 + 1], v[i * 2 + 2] ); } }
	T query( T a, T b, T k, T l, T r ) {
		if ( r <= a || b <= l ) return ( I );
		if ( a <= l && r <= b ) return ( v[k] );
		else { T vl = query( a, b, k * 2 + 1, l, ( l + r ) / 2 );
			T vr = query( a, b, k * 2 + 2, ( l + r ) / 2, r );
			return ( func( vl, vr ) ); }
	}
private:
	T N; F func; vector<T> v;
};

template<typename T = ll> T solveLIS( const vector<T> &v ) {
	vector<T> dp( v.size(), numeric_limits<T>::max() );
	rep( i, v.size() ) {
		*lower_bound( ALL( dp ), v[i] ) = v[i];
	}
	return ( distance( dp.begin(), lower_bound( ALL( dp ), numeric_limits<T>::max() ) ) );
}

template<typename T, T MOD> class Fp {
public:
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
private:
	T val;
};
constexpr ll MOD = 1000000007LL;
using mint = Fp<ll, MOD>;

constexpr ll COMBSIZE = 2000010;
ll fact[COMBSIZE];
ll inv[COMBSIZE];
ll inv_fact[COMBSIZE];

template<typename T> void initComb( T n, T m = MOD )
{
	fact[0] = fact[1] = inv_fact[0] = inv_fact[1] = 1;
	inv[1] = 1;
	for ( int i = 2; i < n; i++ ) {
		fact[i] = ( fact[i - 1] * i ) % m;
		inv[i] = m - inv[m % i] * ( m / i ) % m;
		inv_fact[i] = inv_fact[i - 1] * inv[i] % m;
	}
}

template<typename T> T comb( T n, T r, T m = MOD )
{
	if ( n < r ) return ( 0 );
	if ( n < 0 || r < 0 ) return ( 0 );
	return ( fact[n] * ( inv_fact[r] * inv_fact[n - r] % m ) % m );
}

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
	ll r1, r2, c1, c2;
	cin >> r1 >> c1 >> r2 >> c2;

	initComb( COMBSIZE );

	ll ans = 0;
	for ( int i = c1; i <= c2; ++i )
	{
		for ( int j = r1; j <= r2; ++j )
		{
			ans = ( ans + comb( i + j, j ) ) % MOD;
		}
	}

	cout << ans << endl;

	return ( 0 );
}

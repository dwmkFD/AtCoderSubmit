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

template<typename T = ll> class CompareMax {
public:	T operator()( T a, T b ) { return ( max( a, b ) ); }
};
template<typename T = ll> class CompareMin {
public:	T operator()( T a, T b ) { return ( min( a, b ) ); }
};

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

template<typename T> auto binsearch_idx( vector<T> &v, T val ) {
	ll left = -1, right = v.size();
	while ( abs( right - left ) > 1 )
	{
		ll mid = ( left + right ) / 2;
		if ( val > v[mid] )
			left = mid;
		else
			right = mid;
	}

	return ( mp( v[right] == val, right ) );
}


int main()
{
	ll h, w, k; cin >> h >> w >> k;
	vector<string> c( h );
	rep( i, h ) cin >> c[i];

	ll total = 0;
	rep( i, h ) rep( j, w ) if ( c[i][j] == '#' ) ++total;

	ll ans = 0;
	rep( i, 1LL << h )
	{
		rep( j, 1LL << w )
		{
			ll tmp = 0;
			rep( ii, h )
			{
				if ( i & ( 1LL << ii ) )
					rep( jj, w ) if ( c[ii][jj] == '#' ) ++tmp;
			}
			rep( jj, w )
			{
				if ( j & ( 1LL << jj ) )
					rep( ii, h )
						if ( ( c[ii][jj] == '#' ) && ( ( i & ( 1LL << ii ) ) == 0 ) ) ++tmp;
			}

			if ( total - tmp == k ) ++ans;
		}
	}

	cout << ans << endl;

	return ( 0 );
}

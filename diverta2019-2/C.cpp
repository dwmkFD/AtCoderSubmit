#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
#include <string>
#include <bitset>
#include <tuple>
#include <cmath>
#include <map>

template<typename T> bool chmax( T &a, const T &b ) { if ( a <= b ) { a = b; return ( true ); } else { return ( false ); } }
template<typename T> bool chmin( T &a, const T &b ) { if ( a >= b ) { a = b; return ( true ); } else { return ( false ); } }

using namespace std;

using ll = long long;
using ull = unsigned long long;

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

#define ALL( c ) ( c ).begin(), ( c ).end()
#define RALL( c ) ( c ).rbegin(), ( c ).rend()
#define UNIQUE( c ) ( c ).erase( unique( ( c ).begin(), ( c ).end() ), ( c ).end() )

constexpr ll MOD = 1000000007LL;

#define y0 y3487465
#define y1 y8687969
#define j0 j1347829
#define j1 j234892
#define next asdnext
#define prev asdprev

template<typename T = ll> class UnionFind {
public:
	UnionFind( T n ) { rep( i, n ) { par.resize( n ); siz.resize( n ); par[i] = i; siz[i] = 1; } }
	T find( T x ) { if ( x == par[x] ) return ( x ); else return( par[x] = find( par[x] ) ); }
	void unite( T x, T y ) { T xx = find( x ); T yy = find( y ); if ( xx == yy ) return;
		if ( siz[xx] <= siz[yy] ) swap( xx, yy ); par[yy] = xx; siz[xx] += siz[yy]; }
private:
	vector<T> par, siz;
};

template<typename T = ll> T power( T a, T b, T m = MOD ) {
	T res = 1;
	while ( b > 0 ) { if ( b & 1 ) res = res * a % m;
		a = a * a % m; b >>= 1; }
	return ( res );
}

/*
constexpr ll MAX = 500010;
ll fact[MAX];
ll inv[MAX];
ll inv_fact[MAX];

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
*/

void replace( string &s, string t, string r ) {
	string::size_type p = 0;
	while ( ( p = s.find( t, p ) ) != string::npos ) {
		s.replace( p, t.length(), r );
		p += r.length();
	}
}


int main()
{
	int N;
	cin >> N;

	int counter = 0;
	vector<int> v( N );
	rep( i, N )
	{
		cin >> v[i];
		if ( v[i] < 0 )
		{
			++counter;
		}
	}

	if ( N == 2 )
	{
		// 入力が2個しかなければ、max( a, b ) - min( a, b )で終わり
		cout << max( v[0], v[1] ) - min( v[0], v[1] ) << endl;
		cout << max( v[0], v[1] ) << " " << min( v[0], v[1] ) << endl;
		return ( 0 );
	}
	// 負の数の個数で場合分け
	ll total = 0;
	sort( ALL( v ) );
	if ( counter == 0 )
	{
		rep( i, N )
		{
			total += abs( v[i] );
		}
		total -= v[0] * 2;

		cout << total << endl;
		cout << v[0] << " " << v[N - 1] << endl;
		ll tmp = v[0] - v[N - 1];
		for ( int i = 1; i < N - 2; i++ )
		{
			cout << tmp << " " << v[i] << endl;
			tmp -= v[i];
		}
		cout << v[N - 2] << " " << tmp << endl;
	}
	else if ( counter == N )
	{
		// 全部負の数の場合
		// 基本的に負の数がゼロの場合と同じ（絶対値が一番小さいやつを除いて全部足す）
		rep( i, N )
		{
			total += abs( v[i] );
		}
		total += v[N - 1] * 2;	// 全部負の数なので、負の数がゼロの場合と逆になる

		cout << total << endl;
		cout << v[N - 1] << " " << v[0] << endl;
		ll tmp = v[N - 1] - v[0];
		for ( int i = 1; i < N - 2; i++ )
		{
			cout << tmp << " " << v[i] << endl;
			tmp -= v[i];
		}
		cout << tmp << " " << v[N - 2] << endl;
	}
	else if ( counter == N - 1 )
	{
		rep( i, N )
		{
			total += abs( v[i] );
		}
		cout << total << endl;

		ll tmp = v[N - 1];
		for ( int i = 0; i < N - 1; i++ )
		{
			cout << tmp << " " << v[i] << endl;
			tmp -= v[i];
		}
	}
	else
	{
		rep( i, N )
		{
			total += abs( v[i] );
		}

		cout << total << endl;
		auto it = lower_bound( ALL( v ), 0 );
		int index = distance( v.begin(), it );

		// v[index - 1]の負の数をひとつだけ残す
		ll tmp = v[index];
		for ( int i = 0; i < index - 1; i++ )
		{
			cout << tmp << " " << v[i] << endl;
			tmp -= v[i];
		}
		cout << v[index - 1] << " " << tmp << endl;
		tmp -= v[index - 1];

		for ( int i = index + 1; i < N - 1; i++ )
		{
			cout << -tmp << " " << v[i] << endl;
			tmp = v[i] + tmp;
		}
		cout << v[N - 1] << " " << -tmp << endl;
	}

	return ( 0 );
}

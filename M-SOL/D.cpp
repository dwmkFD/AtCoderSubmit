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

const ll MOD = 1000000007LL;

#define y0 y3487465
#define y1 y8687969
#define j0 j1347829
#define j1 j234892
#define next asdnext
#define prev asdprev

template<typename T = ll> class UnionFind {
public:
	UnionFind( T n ) { rep( i, n ) { par[i] = i; siz[i] = 1; } }
	T find( T x ) { if ( x == par[x] ) return ( x ); else return( par[x] = find( par[x] ) ); }
	void unite( T x, T y ) { T xx = find( x ); T yy = find( y ); if ( xx == yy ) return;
		if ( siz[xx] <= siz[yy] ) swap( xx, yy ); par[yy] = xx; siz[xx] += siz[yy]; }
private:
	vector<T> par, siz;
};

template<typename T = ll> T binpow( T a, T b, T m = MOD ) {
	T res = 1;
	while ( b > 0 ) { if ( b & 1 ) res = res * a % m;
		a = a * a % m; b >>= 1; }
	return ( res );
}


int main()
{
	ll N;
	cin >> N;

	vector<ll> vp( N, 0 );
	vector<vector<ll>> vv( N, vector<ll>( N, 0 ) );
	rep( i, N - 1 )
	{
		ll a, b;
		cin >> a >> b;
		--a, --b;
		vv[a][b] = 1;
		vv[b][a] = 1;
		vp[a]++;
		vp[b]++;
	}

	vector<Pll> v( N );
	vector<ll> vc( N );
	rep( i, N )
	{
		cin >> vc[i];
		v[i].F = i; v[i].S = vp[i];
	}

	// 繋がってる辺が多い頂点には大きい点数を割り当てたい（各辺に相手の重みを採用してあげられる）
	sort( ALL( vc ), []( ll a, ll b ) { return ( a > b ); } );
	stable_sort( ALL( v ), []( Pll a, Pll b ) { return ( a.S > b.S ); } );

	ll sum = 0;
	rep( i, N )
	{
		v[i].S = vc[i];
	}
	rep ( i, N )
	{
		for ( int j = i + 1; j < N; j++ )
		{
			if ( vv[i][j] != 0 )
			{
				vv[i][j] = min( v[i].S, v[j].S );
				sum += vv[i][j];
				vv[j][i] = 0;
			}
		}
	}
	sort( ALL( v ) );
	cout << sum << endl;
	rep( i, N )
	{
		cout << v[i].S << " ";
	}
	cout << endl;

	return ( 0 );
}

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <bitset>
#include <tuple>
#include <cmath>
#include <map>

template<typename T> bool chmax( T &a, T b ) { if ( a < b ) { a = b; return ( true ); } else { return ( false ); } }
template<typename T> bool chmin( T &a, T b ) { if ( a > b ) { a = b; return ( true ); } else { return ( false ); } }

using namespace std;

using ll = long long;
using ull = unsigned long long;

using Pint = pair<int, int>;
using Pll  = pair<ll, ll>;
using Pull = pair<ull, ull>;

#define eb emplace_back
#define pb push_back
#define F first
#define S second
#define mp( a, b ) make_pair( a, b )
#define mt( ... ) make_tuple( __VA_ARGS__ )

#define rep( i, n ) for ( int i = 0; i < (int)( n ); ++i )
#define reps( i, n ) for ( int i = 1; i <= (int)( n ); ++i )
#define rrep( i, n ) for ( int i = (int)( ( n ) - 1 ); i >= 0; --i )
#define rreps( i, n ) for ( int i = (int)( ( n ) ); i > 0; --i )

#define ALL( c ) ( c ).begin(), ( c ).end()
#define RALL( c ) ( c ).rbegin(), ( c ).rend()

#define MOD ( 1e9 + 7 )

class UnionFind {
public:
	UnionFind( ll n ) : par( n ), siz( n, 1LL )
	{
		rep( i, n )
		{
			par[i] = i;
		}
	}

	ll find( ll x )
	{
		if ( par[x] == x )
		{
			return ( x );
		}
		else
		{
			return ( par[x] = find( par[x] ) );
		}
	}

	ll size( ll x )
	{
		return ( siz[find( x )] );
	}

	void unite( ll x, ll y )
	{
		x = find( x );
		y = find( y );

		if ( x == y ) return;

		if ( siz[x] < siz[y] )
		{
			par[x] = y;
			siz[y] += siz[x];
		}
		else
		{
			par[y] = x;
			siz[x] += siz[y];
		}
	}

private:
	vector<ll> par;
	vector<ll> siz;
};

int main()
{
	ll N, M;
	cin >> N >> M;

	vector<Pll> v;
	rep( i, M )
	{
		ll a, b;
		cin >> a >> b;
		v.eb( mp( a - 1, b - 1 ) );
	}

	UnionFind uf( N );
	vector<ll> ans( M, 0 );
	ans[M - 1] = ( N * ( N - 1 ) ) / 2;

	for ( int i = M - 1; i >= 1; --i )
	{
		ll n1 = uf.size( v[i].F );
		ll n2 = uf.size( v[i].S );

		if ( uf.find( v[i].F ) == uf.find( v[i].S ) )
		{
			ans[i - 1] = ans[i];
		}
		else
		{
			ans[i - 1] = ans[i] - n1 * n2;
			uf.unite( v[i].F, v[i].S );
		}
	}

	rep( i, M )
	{
		cout << ans[i] << endl;
	}

	return ( 0 );
}

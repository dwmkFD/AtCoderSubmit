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
#define arep( i, v ) for ( auto &&i : v )

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

class UnionFind {
public:
	UnionFind( int n )
	{
		par.resize( n );
		siz.resize( n );

		rep( i, n )
		{
			par[i] = i;
			siz[i] = 1;
		}
	}

	int find( int x )
	{
		if ( x == par[x] ) return ( x );
		else return ( par[x] = find( par[x] ) );
	}

	void unite( int x, int y )
	{
		int pX = find( x );
		int pY = find( y );
		if ( pX == pY ) return;

		if ( siz[pX] < siz[pY] )
		{
			par[pY] = pX;
			siz[pX] += siz[pY];
		}
		else
		{
			par[pX] = pY;
			siz[pY] += siz[pX];
		}
	}

private:
	vector<int> par;
	vector<int> siz;
};

int main()
{
	int N, M;
	cin >> N >> M;

	UnionFind uf( N );
	rep( i, M )
	{
		int x, y, z;
		cin >> x >> y >> z;

		uf.unite( x - 1, y - 1 );
	}

	vector<int> v( N );
	rep( i, N )
	{
		v[i] = uf.find( i );
	}
	sort( ALL( v ) );
	UNIQUE( v );

	cout << v.size() << endl;

	return ( 0 );
}

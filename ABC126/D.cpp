#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <tuple>
#include <bitset>

template<typename T> bool chmax( T &a, T b ) { if ( a <= b ) { a = b; return ( true ); } else { return ( false ); } }
template<typename T> bool chmin( T &a, T b ) { if ( a >= b ) { a = b; return ( true ); } else { return ( false ); } }

using namespace std;

using ll = long long;
using ull = unsigned long long;

using Pll  = pair<ll, ll>;
using Pull = pair<ull, ull>;

#define eb emplace_back
#define pb push_back
#define mp( a, b ) make_pair( a, b )
#define mt make_tuple

#define F first
#define S second

#define rep( i, n ) for ( int i = 0; i < (int)( n ); ++i )
#define reps( i, n ) for ( int i = 1; i <= (int)( n ); ++i )
#define rrep( i, n ) for ( int i = (int)( ( n ) - 1 ); i >= 0; --i )
#define rreps( i, n ) for ( int i = (int)( ( n ) ); i > 0; --i )

#define ALL( c ) ( c ).begin(), ( c ).end()
#define RALL( c ) ( c ).rbegin(), ( c ).rend()

#define MOD ( 1e9 + 7 )

using Edge = pair<int, int>;
using Graph = vector<vector<Edge>>;

Graph G;
vector<int> res;

void dfs( int v, int p, int c )
{
	res[v] = c;	//	ノードvはcで塗る

	for ( auto &&e : G[v] )	//	ノードvに繋がっているノード全部
	{
		if ( e.F == p )
		{
			// 親は考慮不要
			continue;
		}
		if ( e.S % 2 )
		{
			// 繋がってるノードへの距離が奇数
			dfs( e.F, v, c ^ 1 );	//	子は違う色にする
		}
		else
		{
			dfs( e.F, v, c );	//	偶数なので同じ色
		}
	}
}

int main()
{
	ll N;
	cin >> N;

	G.assign( N, vector<Edge>() );
	res.assign( N, 0 );

	rep( i, N - 1 )
	{
		int u, v, w;
		cin >> u >> v >> w;

		--u; --v;

		G[u].emplace_back( Edge( v, w ) );
		G[v].emplace_back( Edge( u, w ) );
	}

	// 計算
	dfs( 0, -1, 0 );

	// 出力
	for ( auto &&it : res )
	{
		cout << it << endl;
	}

	return ( 0 );
}

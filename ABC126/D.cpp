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
	res[v] = c;	//	�m�[�hv��c�œh��

	for ( auto &&e : G[v] )	//	�m�[�hv�Ɍq�����Ă���m�[�h�S��
	{
		if ( e.F == p )
		{
			// �e�͍l���s�v
			continue;
		}
		if ( e.S % 2 )
		{
			// �q�����Ă�m�[�h�ւ̋������
			dfs( e.F, v, c ^ 1 );	//	�q�͈Ⴄ�F�ɂ���
		}
		else
		{
			dfs( e.F, v, c );	//	�����Ȃ̂œ����F
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

	// �v�Z
	dfs( 0, -1, 0 );

	// �o��
	for ( auto &&it : res )
	{
		cout << it << endl;
	}

	return ( 0 );
}

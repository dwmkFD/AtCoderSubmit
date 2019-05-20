#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <bitset>
#include <queue>
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
#define mp( a, b ) make_pair( a, b )
#define mt( ... ) make_tuple( __VA_ARGS__ )

#define rep( i, n ) for ( int i = 0; i < (int)( n ); ++i )
#define reps( i, n ) for ( int i = 1; i <= (int)( n ); ++i )
#define rrep( i, n ) for ( int i = (int)( ( n ) - 1 ); i >= 0; --i )
#define rreps( i, n ) for ( int i = (int)( ( n ) ); i > 0; --i )

#define ALL( c ) ( c ).begin(), ( c ).end()
#define RALL( c ) ( c ).rbegin(), ( c ).rend()

#define MOD ( 1e9 + 7 )
#define MINUSINF ( "-" )

void chmax( string &a, string b )
{
	if ( a == MINUSINF )
	{
		a = b;
	}
	else
	{
		if ( a.size() < b.size() )
		{
			a = b;
		}
		else if ( a.size() == b.size() )
		{
			if ( a < b )
			{
				a = b;
			}
		}
	}
}

int main()
{
	int N, M;
	cin >> N >> M;

	const int Am[] = {
		0, 2, 5, 5, 4, 5, 6, 3, 7, 6
	};

	vector<int> v( M );
	rep( i, M )
	{
		cin >> v[i];
	}

	vector<string> dp( N + 100, MINUSINF );
	dp[0] = "";

	rep( i, N + 1 )
	{
		if ( dp[i] == MINUSINF )
		{
			continue;
		}
		for ( auto &&it : v )
		{
			chmax( dp[i + Am[it]], dp[i] + (char)( it + '0' ) );
		}
	}

	cout << dp[N] << endl;

	return ( 0 );
}

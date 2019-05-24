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

#define MOD ( (ll)( 1e9 + 7 ) )

ll N;
vector<map<string, ll>> dp;

bool chk( const string &acgt )
{
	rep( i, 4 )
	{
		string tmp = acgt;
		if ( i >= 1 )
		{
			swap( tmp[i], tmp[i - 1] );
		}

		if ( tmp.find( "AGC" ) != string::npos )
		{
			return ( false );
		}
	}

	return ( true );
}

ll dfs( ll current, const string str3 )
{
	if ( dp[current][str3] != 0 )
	{
		return ( dp[current][str3] );
	}

	if ( current == N )
	{
		return ( 1 );
	}

	ll ret = 0;
	const string acgt = "ACGT";
	rep( i, 4 )
	{
		if ( chk( str3 + acgt[i] ) )
		{
			ret = ( ret + dfs( current + 1, str3.substr( 1, 2 ) + acgt[i] ) ) % MOD;
		}
	}
	dp[current][str3] = ret;

	return ( ret );
}

int main()
{
	cin >> N;
	dp.resize( N + 1 );

	cout << dfs( 0, "TTT" ) << endl;

	return ( 0 );
}

#include <algorithm>
#include <iostream>
#include <iomanip>
#include <numeric>
#include <vector>
#include <string>
#include <bitset>
#include <stack>
#include <queue>
#include <tuple>
#include <regex>
#include <cmath>
#include <map>
#include <set>
#include <functional>
#include <cstring>

using namespace std;

template<typename T> bool chmax( T &a, const T b ) { if ( a < b ) { a = b; return ( true ); } else { return ( false ); } }
template<typename T> bool chmin( T &a, const T b ) { if ( a >= b ) { a = b; return ( true ); } else { return ( false ); } }

using ll = long long;
using Pint = pair<int, int>;
using Pll  = pair<ll, ll>;

#define eb emplace_back
#define pb push_back
#define mp make_pair

#define F first
#define S second

#define popcnt __builtin_popcountll

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


int main()
{
	ll h, w; cin >> h >> w;
	vector<string> c( h );
	rep( i, h ) cin >> c[i];

	vector<vector<ll>> dp( h + 1, vector<ll>( w + 1, 1 ) );

	ll dx[] = { 0, 1 };
	ll dy[] = { 1, 0 };
	queue<Pll> q;
	q.push( mp( 0, 0 ) );
	while ( q.empty() == false )
	{
		auto t = q.front(); q.pop();
		ll x = t.F; ll y = t.S;
		rep( i, 2 )
		{
			ll nx = x + dx[i];
			ll ny = y + dy[i];
			if ( nx < h && ny < w )
			{
				if ( c[nx][ny] == '.' )
				{
					if ( chmax( dp[nx][ny], dp[x][y] + 1 ) )
						q.push( mp( nx, ny ) );
				}
			}
		}
	}

	ll ans = 0;
	rep( i, h )
	{
		rep( j, w )
		{
			chmax( ans, dp[i][j] );
		}
	}

	cout << ans << endl;

	return ( 0 );
}

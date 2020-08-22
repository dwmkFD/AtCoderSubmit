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

template<typename T> bool chmax( T &a, const T b ) { if ( a <= b ) { a = b; return ( true ); } else { return ( false ); } }
template<typename T> bool chmin( T &a, const T b ) { if ( a > b ) { a = b; return ( true ); } else { return ( false ); } }

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
	int h, w; cin >> h >> w;
	int ch, cw; cin >> ch >> cw;
	int dh, dw; cin >> dh >> dw;
	--ch; --cw; --dh; --dw;

	vector<string> s( h );
	rep( i, h ) cin >> s[i];

	const int cdh[] = { -1, 0, 1, 0 };
	const int cdw[] = { 0, -1, 0, 1 };
	constexpr int inf = 1e9;
	vector<vector<int>> cost( h, vector<int>( w, inf ) );
	cost[ch][cw] = 0;
	deque<Pint> dq;
	dq.push_front( mp( ch, cw ) );

	while ( dq.empty() == false )
	{
		auto x = dq.front(); dq.pop_front();
		rep( i, 4 )
		{
			ll nh = x.F + cdh[i];
			ll nw = x.S + cdw[i];
			if ( nh >= 0 && nw >= 0 && nh < h && nw < w )
			{
				if ( s[nh][nw] != '#' )
				{
					if ( chmin( cost[nh][nw], cost[x.F][x.S] ) )
						dq.push_front( mp( nh, nw ) );
				}
			}
		}

		// ƒ[ƒv
		for ( int i = max( 0, x.F - 2 ); i < min( x.F + 3, h ); ++i )
		{
			for ( int j = max( 0, x.S - 2 ); j < min( x.S + 3, w ); ++j )
			{
				if ( s[i][j] != '#' )
				{
					if ( chmin( cost[i][j], cost[x.F][x.S] + 1 ) )
					{
						dq.push_back( mp( i, j ) );
					}
				}
			}
		}

#if 0
		static int cnt = 1;
		cout << "[ " << cnt++ << " ]" << endl;
		rep( i, h )
		{
			rep( j, w )
			{
				cout << cost[i][j] << " ";
			}
			cout << endl;
		}
#endif
	}

	if ( cost[dh][dw] < inf )
		cout << cost[dh][dw] << endl;
	else
		cout << -1 << endl;

	return ( 0 );
}

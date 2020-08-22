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
	ll H, W, m;
	cin >> H >> W >> m;
	map<Pll, ll> mm;
	map<ll, ll> mh, mw;
	rep( i, m )
	{
		ll h, w; cin >> h >> w;
		--h; --w;
		mh[h]++; mw[w]++;
		mm[mp( h, w )]++;
	}

	vector<ll> tmphv, tmpwv;
	ll tmph = 0, tmpw = 0;
	ll hnum = 0, wnum = 0;
	rep( i, H )
	{
		if ( chmax( hnum, mh[i] ) )
		{
			tmph = i;
			tmphv.clear();
		}
		else if ( hnum == mh[i] )
		{
			tmphv.eb( tmph );
			tmphv.eb( i );
		}
	}
	rep( i, W )
	{
		if ( chmax( wnum, mw[i] ) )
		{
			tmpw = i;
			tmpwv.clear();
		}
		else if ( wnum == mw[i] )
		{
			tmpwv.eb( tmpw );
			tmpwv.eb( i );
		}
	}

	tmphv.eb( tmph );
	tmpwv.eb( tmpw );

	ll ans = mh[tmph] + mw[tmpw];
	if ( mm[mp( tmph, tmpw )] ) --ans;
	arep( ith, tmphv )
	{
		arep( itw, tmpwv )
		{
			if ( mm[mp( ith, itw )] == 0 )
			{
				ans = mh[ith] + mw[itw];
				cout << ans << endl;
				return ( 0 );
			}
		}
	}
	cout << ans << endl;

	return ( 0 );
}

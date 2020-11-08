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
	ll h, w, n, m;
	cin >> h >> w >> n >> m;
	vector<ll> a( n ), b( n ), c( m ), d( m );
	map<ll, set<ll>> ma, mb, mc, md;
	rep( i, n )
	{
		cin >> a[i] >> b[i];
		--a[i]; --b[i];
		ma[a[i]].insert( b[i] );
		mb[b[i]].insert( a[i] );
	}
	rep( i, m )
	{
		cin >> c[i] >> d[i];
		--c[i]; --d[i];
		mc[c[i]].insert( d[i] );
		md[d[i]].insert( c[i] );
	}

	ll ans = 0;
	rep( i, h )
	{
		rep( j, w )
		{
			if ( ma[i].size() > 0 )
			{
				if ( mc[i].size() > 0 )
				{
					auto it1 = ma[i].lower_bound( i );
					auto it2 = mc[i].lower_bound( i );
					if ( *it1 < *it2 )
						++ans;
				}
				else
					++ans;
			}
			else if ( mb[j].size() > 0 )
			{
				if ( md[j].size() > 0 )
				{
					auto it1 = mb[j].lower_bound( j );
					auto it2 = md[j].lower_bound( j );
					if ( *it1 < *it2 )
						++ans;
				}
				else
					++ans;
			}
		}
	}

	cout << ans << endl;
	return ( 0 );
}

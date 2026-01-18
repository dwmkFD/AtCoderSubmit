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

struct Edge {
	ll to, cost;
	Edge( ll t, ll c ) {
		to = t;
		cost = c;
	}
};

struct Check {
	ll to, cost, round;
	Check( ll t, ll c, ll r ) {
		to = t;
		cost = c;
		round = r;
	}
};

int main()
{
	ll n, m, l, s, t;
	cin >> n >> m >> l >> s >> t;

	vector<vector<Edge>> g( n );
	rep( i, m ) {
		ll u, v, c;
		cin >> u >> v >> c;
		--u; --v;
		g[u].eb( Edge( v, c ) );
	}

	vector<ll> ans;
	queue<Check> q;
	q.push( Check( 0, 0, 0 ) );
	while ( q.empty() == false ) {
		auto c = q.front();
		q.pop();

		if ( c.cost >= s && c.cost <= t ) {
			if ( c.round == l ) {
				ans.eb( c.to );
			}
		}

		arep( it, g[c.to] ) {
			if ( c.cost + it.cost <= t && c.round < l ) {
				q.push( Check( it.to, c.cost + it.cost, c.round + 1 ) );
			}
		}

	}

	sort( ALL( ans ) );
	UNIQUE( ans );
	rep( i, ans.size() ) {
		cout << ans[i] + 1 << " \n"[i == ans.size() - 1];
	}

	return ( 0 );
}

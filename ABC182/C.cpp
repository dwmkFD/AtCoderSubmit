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
	string n; cin >> n;
	ll tmp = 0;
	map<ll, ll> m;

	rep( i, n.size() )
	{
		ll x = ( n[i] - '0' ) % 3;
		m[x]++;
		tmp += x;
		tmp %= 3;
	}

	if ( tmp == 0 )
	{
		cout << 0 << endl;
		return ( 0 );
	}
	else if ( tmp == 1 )
	{
		if ( m[1] > 0 && m[1] < n.size() )
			cout << 1 << endl;
		else if ( m[2] >= 2 && m[2] < n.size() )
			cout << 2 << endl;
		else
			cout << -1 << endl;
		return ( 0 );
	}
	else if ( tmp == 2 )
	{
		if ( m[2] > 0 && m[2] < n.size() )
			cout << 1 << endl;
		else if ( m[1] >= 2 && m[1] < n.size() )
			cout << 2 << endl;
		else
			cout << -1 << endl;
		return ( 0 );
	}

	cout << -1 << endl;

	return ( 0 );
}

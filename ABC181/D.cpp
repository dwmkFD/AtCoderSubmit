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
	string s; cin >> s;
	bool ok = false;

	map<ll, ll> m;
	rep( i, s.size() )
		m[s[i] - '0']++;

	// 8 16 24 32 48 56 64 72 88 96 112 128 136 144 152 168 176 184 192

	if ( s.size() == 1 )
	{
		if ( s[0] == '8' ) ok = true;
	}
	else
	{
		if ( s.size() == 2 )
		{
			if ( m[1] >= 1 && m[6] >= 1 ) ok = true;
			if ( m[2] >= 1 && m[4] >= 1 ) ok = true;
			if ( m[3] >= 1 && m[2] >= 1 ) ok = true;
			if ( m[4] >= 1 && m[8] >= 1 ) ok = true;
			if ( m[5] >= 1 && m[6] >= 1 ) ok = true;
			if ( m[6] >= 1 && m[4] >= 1 ) ok = true;
			if ( m[7] >= 1 && m[2] >= 1 ) ok = true;
			if ( m[8] >= 2 ) ok = true;
			if ( m[9] >= 1 && m[6] >= 1 ) ok = true;
		}
		else
		{
			if ( m[1] >= 2 && m[2] >= 1 ) ok = true;
			if ( m[1] >= 1 && m[2] >= 1 && m[8] >= 1 ) ok = true;
			if ( m[1] >= 1 && m[3] >= 1 && m[6] >= 1 ) ok = true;
			if ( m[1] >= 1 && m[4] >= 2 ) ok = true;
			if ( m[1] >= 1 && m[2] >= 1 && m[5] >= 1 ) ok = true;
			if ( m[1] >= 1 && m[6] >= 1 && m[8] >= 1 ) ok = true;
			if ( m[1] >= 1 && m[7] >= 1 && m[6] >= 1 ) ok = true;
			if ( m[1] >= 1 && m[8] >= 1 && m[4] >= 1 ) ok = true;
			if ( m[1] >= 1 && m[9] >= 1 && m[2] >= 1 ) ok = true;
			ll x = 0;
			for ( ll i = 2; i <= 9; i += 2 ) x += m[i];

			if ( m[1] >= 1 && m[6] >= 1 && x >= 2 ) ok = true;
			if ( m[2] >= 1 && m[4] >= 1 && x >= 3 ) ok = true;
			if ( m[3] >= 1 && m[2] >= 1 && x >= 2 ) ok = true;
			if ( m[4] >= 1 && m[8] >= 1 && x >= 3 ) ok = true;
			if ( m[5] >= 1 && m[6] >= 1 && x >= 2 ) ok = true;
			if ( m[6] >= 1 && m[4] >= 1 && x >= 3 ) ok = true;
			if ( m[7] >= 1 && m[2] >= 1 && x >= 2 ) ok = true;
			if ( m[8] >= 2 && x >= 3 ) ok = true;
			if ( m[9] >= 1 && m[6] >= 1 && x >= 2 ) ok = true;
		}
	}

	cout << ( ok ? "Yes" : "No" ) << endl;

	return ( 0 );
}

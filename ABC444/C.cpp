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
	ll n; cin >> n;
	vector<ll> a( n );
	map<ll, ll> m;
	rep( i, n ) {
		cin >> a[i];
		m[a[i]]++;
	}
	sort( ALL( a ), greater<>() );

	if ( a.front() == a.back() ) {
		cout << a.front();
		if ( a.size() % 2 == 0 )
			cout << " " << a.front() * 2;
		cout << endl;
		return ( 0 );
	}

	vector<ll> ans;
	ll L = a[0];
	bool ok = true;
	if ( ( n - m[L] ) % 2 ) ok = false;
	map<ll, ll> m2 = m;
	reps( i, n - 1 ) {
		if ( m2[a[i]] <= 0 ) break;
		else if ( a[i] == L ) continue;
		if ( m2[L - a[i]] > 0 ) {
			--m2[L - a[i]];
		}
		else {
			ok = false;
			break;
		}
	}
	if ( ok ) ans.eb( L );

	ok = true;
	m2 = m;
	L = a.front() + a.back();
	rep( i, ( n + 1 ) / 2 ) {
		if ( m2[a[i]] <= 0 ) {
			ok = false;
			break;
		}
		if ( a[i] + a[n - 1 - i] != L ) {
			ok = false;
			break;
		}
	}
	if ( ok ) ans.eb( L );
	sort( ALL( ans ) );

	rep( i, ans.size() ) {
		cout << ans[i] << " \n"[i == ans.size() - 1];
	}

	return ( 0 );
}

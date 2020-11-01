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
	vector<ll> x( n ), y( n );
	rep( i, n ) cin >> x[i] >> y[i];
	vector<ll> x_bk = x;
	vector<ll> y_bk = y;

	sort( ALL( x ) );
	rep( i, n - 2 )
	{
		auto it = upper_bound( x.begin() + i, x.end(), x[i] );
		if ( it - ( x.begin() + i ) >= 3 && x[i] == *( it - 1 ) )
		{
			cout << "Yes" << endl;
			return ( 0 );
		}
	}

	sort( ALL( y ) );
	rep( i, n - 2 )
	{
		auto it = upper_bound( y.begin() + i, y.end(), x[i] );
		if ( it - ( y.begin() + i ) >= 3 && y[i] == *( it - 1 ) )
		{
			cout << "Yes" << endl;
			return ( 0 );
		}
	}

	ll cnt = 0;
	x = x_bk;
	y = y_bk;
	vector<ll> order( n );
	iota( ALL( order ), 0 );
	sort( ALL( order ), [&]( ll i, ll j ) { return ( x[i] < x[j] ); } );

	rep( i, n )
	{
		for ( ll j = i + 1; j < n; ++j )
		{
			ll x1 = x[order[j]] - x[order[i]];
			ll y1 = y[order[j]] - y[order[i]];

			for ( ll k = j + 1; k < n; ++k )
			{
				ll x2 = x[order[k]] - x[order[j]];
				ll y2 = y[order[k]] - y[order[j]];
#if 0
				cout << "------------------------" << endl;
				cout << x[order[i]] << ", " << y[order[i]] << endl;
				cout << x[order[j]] << ", " << y[order[j]] << endl;
				cout << x[order[k]] << ", " << y[order[k]] << endl;
				cout << x1 << ", " << y1 << ", " << x2 << ", " << y2 << endl;
				cout << "------------------------" << endl;
#endif
				if ( x1 * y2 == x2 * y1 )
				{
					cout << "Yes" << endl;
					return ( 0 );
				}
			}
		}
	}

	cout << "No" << endl;

	return ( 0 );
}

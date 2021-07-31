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

struct Data {
	ll to;
	ll start;
	ll end;

	Data( ll t, ll s, ll e ) {
		to = t; start = s; end = e;
	}

	bool operator<( const Data &obj ) const {
		return ( this->start < obj.start );
	}
};

int main()
{
	ll n, m, q;
	cin >> n >> m >> q;
	vector<set<Data>> v( n );

	rep( i, m )
	{
		ll a, b, s, t;
		cin >> a >> b >> s >> t;
		--a; --b;
		Data tmp( b, s, t );
		v[a].insert( tmp );
	}

	rep( _, q )
	{
		ll x, y, z;
		cin >> x >> y >> z;
		--y;
		while ( x < z )
		{
			Data tmp( 0, x, 0 );
			auto t = v[y].lower_bound( tmp );

			if ( t == v[y].end() )
			{
				cout << y + 1 << endl;
				break;
			}

			if ( t->end >= z )
			{
				if ( t->start >= z )
				{
					cout << y + 1 << endl;
					break;
				}
				else
				{
					cout << y + 1 << " " << t->to + 1 << endl;
					break;
				}
			}
			else
			{
				x = t->end;
				y = t->to;
			}
		}
	}

	return ( 0 );
}

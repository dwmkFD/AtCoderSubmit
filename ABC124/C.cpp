#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <bitset>
#include <tuple>
#include <cmath>
#include <map>

template<typename T> bool chmax( T &a, T b ) { if ( a < b ) { a = b; return ( true ); } else { return ( false ); } }
template<typename T> bool chmin( T &a, T b ) { if ( a > b ) { a = b; return ( true ); } else { return ( false ); } }

using namespace std;

using ll = long long;
using ull = unsigned long long;

using Pll  = pair<ll, ll>;
using Pull = pair<ull, ull>;

#define eb emplace_back
#define pb push_back
#define mp( a, b ) make_pair( a, b )
#define mt( ... ) make_tuple( __VA_ARGS__ )

#define F first
#define S second

#define rep( i, n ) for ( int i = 0; i < (int)( n ); ++i )
#define reps( i, n ) for ( int i = 1; i <= (int)( n ); ++i )
#define rrep( i, n ) for ( int i = (int)( ( n ) - 1 ); i >= 0; --i )
#define rreps( i, n ) for ( int i = (int)( ( n ) ); i > 0; --i )

#define ALL( c ) ( c ).begin(), ( c ).end()
#define RALL( c ) ( c ).rbegin(), ( c ).rend()

#define MOD ( (ll)( 1e9 + 7 ) )


int main()
{
	string S;
	cin >> S;

	int cnt[2] = { 0 };
	rep( i, S.size() )
	{
		if ( S[i] == '0' )
		{
			cnt[i % 2]++;
		}
	}

	int eB, eW, oB, oW;
	eB = cnt[0];
	oB = cnt[1];
	eW = ( ( S.size() + 1 ) / 2 ) - cnt[0];
	oW = ( S.size() - ( ( S.size() + 1 ) / 2 ) ) - cnt[1];

	int rB, rW;
	if ( oB < eB )
	{
		rB = eW;
		rB += oB;
	}
	else
	{
		rB = oW;
		rB += eB;
	}

	if ( oW < eW )
	{
		rW = eB;
		rW += oW;
	}
	else
	{
		rW = oB;
		rW += eW;
	}

	cout << min( rB, rW ) << endl;

	return ( 0 );
}

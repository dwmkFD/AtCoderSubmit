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
	int N, K;
	cin >> N >> K;

	vector<ll> v( N );
	rep( i, N )
	{
		cin >> v[i];
	}

	// 左右からの累積和を計算してみる
	vector<ll> vl( N + 1 );
	vector<ll> vr( N + 1 );
	vl[0] = vr[0] = 0;
	rep( i, N )
	{
		vl[i + 1] = vl[i] + v[i];
		vr[i + 1] = vr[i] + v[N - 1 - i];
	}

	// 左からK要素のうち、負の価値の個数を求める
	vector<ll> vvl = v;
	ll lcount = 0;
	sort( vvl.begin(), vvl.begin() + K );
	rep( i, K )
	{
		if ( vvl[i] <= 0 )
		{
			lcount++;
		}
		else
		{
			break;
		}
	}

	// 右も
	vector<ll> vvr = v;
	ll rcount = 0;
	sort( vvr.begin() + ( N - K  + 1 ), vvr.end() );
	rrep( i, K )
	{
		if ( vvr[i] <= 0 )
		{
			rcount++;
		}
		else
		{
			break;
		}
	}


	return ( 0 );
}

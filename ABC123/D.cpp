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
	ll X, Y, Z, K;
	cin >> X >> Y >> Z >> K;

	vector<ll> A( X ), B( Y ), C( Z );
	rep( i, X ) { cin >> A[i]; }
	rep( i, Y ) { cin >> B[i]; }
	rep( i, Z ) { cin >> C[i]; }

	// A/B/Cを降順ソート
	sort( ALL( A ), greater<ll>() );
	sort( ALL( B ), greater<ll>() );
	sort( ALL( C ), greater<ll>() );

	// A/B/Cからそれぞれi/j/k番目のケーキを選ぶパターンを
	// i * j * k <= K となるように全て選び、最後にソートする
	vector<ll> res;
	rep( i, X )
	{
		rep( j, Y )
		{
			rep( k, Z )
			{
				if ( ( i + 1 ) * ( j + 1 ) * ( k + 1 ) <= K )
				{
					res.eb( A[i] + B[j] + C[k] );
				}
				else
				{
					break;
				}
			}
		}
	}

	sort( ALL( res ), greater<ll>() );

	rep( i, K )
	{
		cout << res[i] << endl;
	}

	return ( 0 );
}

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <tuple>
#include <bitset>

template<typename T> bool chmax( T &a, T b ) { if ( a > b ) { a = b; return ( true ); } else { return ( false ); } }
template<typename T> bool chmin( T &a, T b ) { if ( a < b ) { a = b; return ( true ); } else { return ( false ); } }

using namespace std;

using ll = long long;
using ull = unsigned long long;

using Pll  = pair<ll, ll>;
using Pull = pair<ull, ull>;

#define ep emplace_back
#define pb push_back
#define mp( a, b ) make_pair( a, b )

#define rep( i, n ) for ( int i = 0; i < (int)( n ); ++i )
#define reps( i, n ) for ( int i = 1; i <= (int)( n ); ++i )
#define rrep( i, n ) for ( int i = (int)( ( n ) - 1 ); i >= 0; --i )
#define rreps( i, n ) for ( int i = (int)( ( n ) ); i > 0; --i )

#define ALL( c ) ( c ).begin(), ( c ).end()
#define RALL( c ) ( c ).rbegin(), ( c ).rend()

#define MOD ( 1e9 + 7 )


int main()
{
	int N, M;
	cin >> N >> M;

	vector<int> v( N, 0 );
	vector<tuple<int, int, int> > vt;
	rep( i, N )
	{
		int tmpX, tmpY, tmpZ;
		cin >> tmpX >> tmpY >> tmpZ;
		v.ep( make_tuple( tmpX, tmpY, tmpZ ) );

		if ( tmpZ % 2 )
		{
			// Zが偶数なら、AxiとAyiも偶数で確定
			v[tmpX - 1] = v[tmpY - 1] = 1;
		}
	}


	return ( 0 );
}

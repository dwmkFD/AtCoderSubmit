#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <tuple>
#include <bitset>
#include <cmath>
#include<iomanip>

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

double pow_1( double x )
{
	double base = 1;
	rep( i, x )
	{
		base /= 2;
	}

	return ( base );
}

int main()
{
	int N, K;
	cin >> N >> K;

	double result = N;
	vector<int> v;
	reps( i, N )
	{
		// iが出た時にKを超える確率を全部足す
		// iが出た時にKを超えるためには、コイントスでsqrt( K / i )の切り上げ回だけ
		// 表を出さなければならない（iがK以上であればコイントスは不要なので、1/Nを足すだけ）

		if ( i >= K )
		{
			break;
		}
		else
		{
			double tmp = ceil( (double)sqrt( K / i ) );
			v.ep( tmp );
		}
	}

	result -= v.size();
	double res2 = 0;
	double r = 0, t = 0;
	for ( auto it = v.rbegin(); it != v.rend(); it++ )
	{
		t = res2 + ( pow_1( *it ) ) + r;
		r = ( pow_1( *it ) + r ) - ( t - res2 );
		res2 = t;
	}

	cout << fixed << setprecision( 10 ) << ( ( result / N ) + ( res2 / N ) ) << endl;

	return ( 0 );
}

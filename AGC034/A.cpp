#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
#include <string>
#include <bitset>
#include <tuple>
#include <cmath>
#include <map>

template<typename T> bool chmax( T &a, const T &b ) { if ( a <= b ) { a = b; return ( true ); } else { return ( false ); } }
template<typename T> bool chmin( T &a, const T &b ) { if ( a >= b ) { a = b; return ( true ); } else { return ( false ); } }

using namespace std;

using ll = long long;
using ull = unsigned long long;

using Pll  = pair<ll, ll>;
using Pull = pair<ull, ull>;

#define eb emplace_back
#define pb push_back
#define mp make_pair
#define mt make_tuple

#define F first
#define S second

#define rep( i, n ) for ( int i = 0; i < (int)( n ); ++i )
#define reps( i, n ) for ( int i = 1; i <= (int)( n ); ++i )
#define rrep( i, n ) for ( int i = (int)( ( n ) - 1 ); i >= 0; --i )
#define rreps( i, n ) for ( int i = (int)( ( n ) ); i > 0; --i )
#define arep( i, v ) for ( auto &&i : ( v ) )

template<typename T> T gcd( const T a, const T b ) { return ( b ? gcd( b, a % b ) : a ); }

#define ALL( c ) ( c ).begin(), ( c ).end()
#define RALL( c ) ( c ).rbegin(), ( c ).rend()
#define UNIQUE( c ) ( c ).erase( unique( ( c ).begin(), ( c ).end() ), ( c ).end() )

const ll MOD = 1000000007LL;

#define y0 y3487465
#define y1 y8687969
#define j0 j1347829
#define j1 j234892
#define next asdnext
#define prev asdprev

template<typename T = ll> class UnionFind {
public:
	UnionFind( T n ) { rep( i, n ) { par[i] = i; siz[i] = 1; } }
	T find( T x ) { if ( x == par[x] ) return ( x ); else return( par[x] = find( par[x] ) ); }
	void unite( T x, T y ) { T xx = find( x ); T yy = find( y ); if ( xx == yy ) return;
		if ( siz[xx] <= siz[yy] ) swap( xx, yy ); par[yy] = xx; siz[xx] += siz[yy]; }
private:
	vector<T> par, siz;
};

template<typename T = ll> T binpow( T a, T b, T m = MOD ) {
	T res = 1;
	while ( b > 0 ) { if ( b & 1 ) res = res * a % m;
		a = a * a % m; b >>= 1; }
	return ( res );
}


int main()
{
	int N, A, B, C, D;
	string S;
	cin >> N >> A >> B >> C >> D >> S;
	--A, --B, --C, --D;

	bitset<200000> b;
	rep( i, N )
	{
		if ( S[i] == '.' )
		{
			b[i] = 0;
		}
		else
		{
			b[i] = 1;
		}
	}

	bool ans = true;
	// ���E�������ʒu�������ւ��Ȃ��ꍇ
	// -> B->D���Ɉړ�������Ηǂ�
	// --> B<->D�ԂɊ₪2�A���Œu����Ă��Ȃ����OK
	// ---> ���l�ɁAA<->C�ԂɊ₪2�A���Œu����Ă��Ȃ����OK
	for ( int i = A; i < C - 1; i++ )
	{
		if ( b[i] & b[i + 1] )
		{
			ans = false;
			break;
		}
	}
	for ( int i = B; i < D - 1; i++ )
	{
		if ( b[i] & b[i + 1] )
		{
			ans = false;
			break;
		}
	}

	if ( C < D )
	{
		// ��̌��������ŏI���
	}
	else
	{
		// ���E�������ʒu�������ւ��ꍇ
		// -> A->C���ړ��������Ȃ����NG
		if ( ans )
		{
			// �A���z�u�͂Ȃ�����
			bool empty3 = false;
			// A<->D�ԂɊ₪�������3���K�v�i�łȂ���B��ǂ��z���Ȃ��j
			for ( int i = A; i <= D - 1; i++ )	// D��荶�ɂ��Ȃ��ƁAB��D�ɒu���Ȃ�
			{
				if ( ( b[i] | b[i + 1] | b[i + 2] ) == 0 )
				{
					if ( B != i + 2 )
					{
						// B�̏����z�u��������_��
						empty3 = true;
						break;
					}
				}
			}

			b[B] = 1;	//	B���∵���ɂ���
			if ( empty3 == false )
			{
				// 3�A���󂢂��ꏊ�͂Ȃ����ǁAB���∵������2�A���₪�Ȃ����OK
				for ( int i = A; i < C - 1; i++ )
				{
					if ( b[i] & b[i + 1] )
					{
						ans = false;
						break;
					}
				}
			}
		}
	}

	cout << ( ans ? "Yes" : "No" ) << endl;

	return ( 0 );
}

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
#include <string>
#include <bitset>
#include <queue>
#include <tuple>
#include <cmath>
#include <map>
#include <cstring>

#include <random>

template<typename T> bool chmax( T &a, const T &b ) { if ( a <= b ) { a = b; return ( true ); } else { return ( false ); } }
template<typename T> bool chmin( T &a, const T &b ) { if ( a >= b ) { a = b; return ( true ); } else { return ( false ); } }

using namespace std;

using ll = long long;
using ull = unsigned long long;

using Pint = pair<int, int>;
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
template<typename T> T lcm( const T a, const T b ) { return ( a / gcd( a, b ) * b ); }

#define ALL( c ) ( c ).begin(), ( c ).end()
#define RALL( c ) ( c ).rbegin(), ( c ).rend()
#define UNIQUE( c ) ( c ).erase( unique( ( c ).begin(), ( c ).end() ), ( c ).end() )

constexpr ll MOD = 1000000007LL;
template<typename T = ll> constexpr T MAX = numeric_limits<T>::max();

#define y0 y3487465
#define y1 y8687969
#define j0 j1347829
#define j1 j234892
#define next asdnext
#define prev asdprev

template<typename T = ll> class UnionFind {
public:
	UnionFind( T n ) { par.resize( n ); siz.resize( n ); rep( i, n ) { par[i] = i; siz[i] = 1; } }
	T find( T x ) { if ( x == par[x] ) return ( x ); else return( par[x] = find( par[x] ) ); }
	void unite( T x, T y ) { T xx = find( x ); T yy = find( y ); if ( xx == yy ) return;
		if ( siz[xx] <= siz[yy] ) swap( xx, yy ); par[yy] = xx; siz[xx] += siz[yy]; }
private:
	vector<T> par, siz;
};

template<typename T = ll> class CompareMax {
public:	T operator()( T a, T b ) { return ( max( a, b ) ); }
};
template<typename T = ll> class CompareMin {
public:	T operator()( T a, T b ) { return ( min( a, b ) ); }
};

template<typename T = ll, typename F = CompareMax<T>, T I = 0> class SegTree {
public:
	SegTree( T n ) { N = n; v.resize( 4 * n ); rep( i, 4 * n ) v[i] = I; }
	void update( T i, T x ) { i += N - 1; v[i] = x; while ( i > 0 ) {
			i = ( i - 1 ) / 2; v[i] = func( v[i * 2 + 1], v[i * 2 + 2] ); } }
	T query( T a, T b, T k, T l, T r ) {
		if ( r <= a || b <= l ) return ( I );
		if ( a <= l && r <= b ) return ( v[k] );
		else { T vl = query( a, b, k * 2 + 1, l, ( l + r ) / 2 );
			T vr = query( a, b, k * 2 + 2, ( l + r ) / 2, r );
			return ( func( vl, vr ) ); }
	}
private:
	T N; F func; vector<T> v;
};

template<typename T = ll> T solveLIS( const vector<T> &v ) {
	vector<T> dp( v.size(), numeric_limits<T>::max() );
	rep( i, v.size() ) {
		*lower_bound( ALL( dp ), v[i] ) = v[i];
	}
	return ( distance( dp.begin(), lower_bound( ALL( dp ), numeric_limits<T>::max() ) ) );
}

template<typename T = ll> T power( T a, T b, T m = MOD ) {
	T res = 1;
	while ( b > 0 ) { if ( b & 1 ) res = res * a % m;
		a = a * a % m; b >>= 1; }
	return ( res );
}

/*
constexpr ll COMBSIZE = 500010;
ll fact[COMBSIZE];
ll inv[COMBSIZE];
ll inv_fact[COMBSIZE];

template<typename T> void initComb( T n, T m = MOD )
{
	fact[0] = fact[1] = inv_fact[0] = inv_fact[1] = 1;
	inv[1] = 1;
	for ( int i = 2; i < n; i++ ) {
		fact[i] = ( fact[i - 1] * i ) % m;
		inv[i] = m - inv[m % i] * ( m / i ) % m;
		inv_fact[i] = inv_fact[i - 1] * inv[i] % m;
	}
}

template<typename T> T comb( T n, T r, T m = MOD )
{
	if ( n < r ) return ( 0 );
	if ( n < 0 || r < 0 ) return ( 0 );
	return ( fact[n] * ( inv_fact[r] * inv_fact[n - r] % m ) % m );
}
*/

void replace( string &s, string t, string r ) {
	string::size_type p = 0;
	while ( ( p = s.find( t, p ) ) != string::npos ) {
		s.replace( p, t.length(), r );
		p += r.length();
	}
}


int main()
{
	int N; cin >> N;
	int B1, B2, B3; cin >> B1 >> B2 >> B3;
	vector<vector<int>> l( N, vector<int>( N ) );
	vector<vector<int>> r( N, vector<int>( N ) );
	rep( i, N ) rep( j, N ) cin >> l[i][j];
	rep( i, N ) rep( j, N ) cin >> r[i][j];

	random_device gen;
	mt19937 eng( gen() );

#if 0
	rep( i, N )
	{
		rep( j, N )
		{
#if 0
			// 1. �Ƃ肠���������_���ɏo���Ă݂�
			auto res = ( eng() % ( r[i][j] - l[i][j] + 1 ) ) + l[i][j];
#endif
#if 0
			// 2. 30�}�X�Œ�Ȃ̂ŁAB3�𖞂����悤�ɍ���
			// �r����B1��B2���������\�����������Ƃ𗘗p������
			// �\�Ȍ���l�Ŗ��߂�ƁAB3���ŏ���30�ł�900�_�ŁA
			// B1, B2���������₷���ėǂ��̂ł́H
			// �ꉞ�A�Ō�̕��̃}�X�͑傫�߂̒l�����Ė��ߍ��킹�邗
			int res = l[i][j];
			if ( i >= 27 ) res = r[i][j];
			if ( j >= 27 ) res = r[i][j];
#endif
#if 0
			// 3. l�������߂ȃ}�X��l���Al���傫�߂ȃ}�X��(l + r) / 2���̗p���Ă݂�
			// l���������l������ꍇ�́A�ł��邾���������l�̕����ǂ��i����������̂Łj
			// l���������ł��Ȃ��Ȃ�A�ނ�����߂ĕ␳�pr������������ǂ��̂ł́H
			// ����ƁA�[�̕��̃}�X�ł̔��������s�v�ɂȂ��āA���L���Ɏg����C������
			int res;
			if ( l[i][j] <= 4 ) res = l[i][j];
			else res = ( l[i][j] + r[i][j] ) / 2;
#endif
#if 0
			// 4. 臒l��������
			int res;
			if ( l[i][j] <= 6 ) res = l[i][j];
			else res = ( l[i][j] + r[i][j] ) / 2;
#endif
#if 0
			// 5. �S��l�ɂ��Ă݂�
			int res = l[i][j];
#endif
#if 0
			// 6. �K�x��r��������
			int res = l[i][j];
			if ( ( i % 5 == 0 ) && ( j % 5 == 0 ) ) res = r[i][j];
#endif
#if 0
			// 7. ������ʂ����炷
			int res = l[i][j];
			if ( ( i == 0 ) || ( i == 29 ) ) if ( j % 5 == 0 ) res = r[i][j];
			if ( ( j == 0 ) || ( j == 29 ) ) if ( i % 5 == 0 ) res = r[i][j];
#endif
#if 0
			// 8. ������l��r��菬��������
			int res = l[i][j];
			if ( ( i == 0 ) || ( i == 29 ) ) if ( j % 5 == 0 ) res = ( l[i][j] + r[i][j] ) / 2;
			if ( ( j == 0 ) || ( j == 29 ) ) if ( i % 5 == 0 ) res = ( l[i][j] + r[i][j] ) / 2;
#endif
			cout << res << " ";
		}
		cout << endl;
	}
#endif

	// 9. ���Ⴍ�Ƃ�@���g���āAB1�𖞂����L���ȋ�Ԃ����߂�i�������̂݁j
	// 10. �c�������l����i��������j
	// �L���Ɏg���Ȃ������ȂƂ����r�����āA���P����Ȃ����H�����Ă݂�
	vector<vector<int>> ans( N, vector<int>( N ) );
	vector<vector<bool>> flg( N, vector<bool>( N, false ) );
	rep( i, N ) rep( j, N ) ans[i][j] = l[i][j];

	rep( i, N )
	{
		int sum = 0;
		int right = 0;
		rep( left, N )
		{
			while ( right < N && sum + ans[i][right] <= B1 )
			{
				sum += ans[i][right];
				++right;
			}
			if ( sum == B1 )
			{
				for ( int k = left; k < right; ++k )
				{
					flg[i][k] = true;
				}
			}

			if ( right == left ) ++right;
			else sum -= ans[i][left];
		}
	}

	rep( i, N )
	{
		int sum = 0;
		int right = 0;
		rep( left, N )
		{
			while ( right < N && sum + ans[right][i] <= B1 )
			{
				sum += ans[right][i];
				++right;
			}
			if ( sum == B1 )
			{
				for ( int k = left; k < right; ++k )
				{
					flg[k][i] = true;
				}
			}

			if ( right == left ) ++right;
			else sum -= ans[left][i];
		}
	}

	rep( i, N )
	{
		rep( j, N )
		{
			if ( flg[i][j] == false )
			{
				// �v�Z�ɕs�v�����ȃ}�X��l���傫�Ȓl�����Ă݂�
				ans[i][j] = ( l[i][j] + r[i][j] ) / 2;
			}

			cout << ans[i][j] << " ";
		}
		cout << endl;
	}

	return ( 0 );
}

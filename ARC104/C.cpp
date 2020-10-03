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


template<class Abel> struct UnionFind {
    vector<int> par;
    vector<int> rank;
    vector<Abel> diff_weight;

    UnionFind(int n = 1, Abel SUM_UNITY = 0) {
        init(n, SUM_UNITY);
    }

    void init(int n = 1, Abel SUM_UNITY = 0) {
        par.resize(n); rank.resize(n); diff_weight.resize(n);
        for (int i = 0; i < n; ++i) par[i] = i, rank[i] = 0, diff_weight[i] = SUM_UNITY;
    }

    int root(int x) {
        if (par[x] == x) {
            return x;
        }
        else {
            int r = root(par[x]);
            diff_weight[x] += diff_weight[par[x]];
            return par[x] = r;
        }
    }

    Abel weight(int x) {
        root(x);
        return diff_weight[x];
    }

    bool issame(int x, int y) {
        return root(x) == root(y);
    }

    bool merge(int x, int y, Abel w) {
        w += weight(x); w -= weight(y);
        x = root(x); y = root(y);
        if (x == y) return false;
        if (rank[x] < rank[y]) swap(x, y), w = -w;
        if (rank[x] == rank[y]) ++rank[x];
        par[y] = x;
        diff_weight[y] = w;
        return true;
    }

    Abel diff(int x, int y) {
        return weight(y) - weight(x);
    }
};


int main()
{
	ll n; cin >> n;
	vector<ll> a( n ), b( n );
	rep( i, n ) cin >> a[i] >> b[i];

	auto fail = []() {
		cout << "No" << endl;
		exit( 0 );
	};

	map<Pll, ll> m;
	UnionFind<ll> uf( 2 * n );
	rep( i, n )
	{
		ll aa = a[i], bb = b[i];
		if ( aa == -1 && bb == -1 ) continue;
		if ( aa >= bb )
			fail();
		if ( aa == -1 )
		{
			--bb;
			for ( ll c = 0; c < bb; ++c )
			{
				if ( uf.issame( c, bb ) )
				{
					ll diff = uf.diff( c, bb );
					if ( diff != bb - c - 1 && m[mp( c, bb )] < 0 )
						fail();
				}
				else
				{
					uf.merge( c, bb, bb - c - 1 );
					m[mp( c, bb )]++;
				}
			}
		}
		else if ( bb == -1 )
		{
			--aa;
			for ( ll c = aa + 1; c < 2 * n; ++c )
			{
				if ( uf.issame( aa, c ) )
				{
					ll diff = uf.diff( aa, c );
					if ( diff != c - aa - 1 && m[mp( aa, c )] < 0 )
						fail();
				}
				else
				{
					uf.merge( aa, c, c - aa - 1 );
					m[mp( aa, c )]++;
				}
			}
		}
		else
		{
			--aa; --bb;
			uf.merge( aa, bb, bb - aa - 1 );
			m[mp( aa, bb )] = -1e18;
		}
	}

	cout << "Yes" << endl;

	return ( 0 );
}

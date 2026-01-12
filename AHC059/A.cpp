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
#include <chrono>

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

class XorShift128 {
private:
  uint32_t x, y, z, w;

public:
  using result_type = uint32_t;

  XorShift128( uint64_t seed ) {
    x = 123456789;
    y = 756542406;
    z = 857392532;
    w = seed == 0 ? 615263943 : static_cast<uint32_t>( seed );
  }

  XorShift128() {
    uint64_t seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    x = 123456789;
    y = 756542406;
    z = 857392532;
    w = static_cast<uint32_t>( seed );
  }

  static constexpr result_type min(){ return 0; }
  static constexpr result_type max(){ return UINT32_MAX; }

  result_type operator()(){ return next(); }

  uint32_t next() {
    uint32_t t = x ^ ( x << 11 );
    x = y;
    y = z;
    z = w;
    w = ( w ^ ( w >> 19 ) ) ^ ( t ^ ( t >> 8 ) );
    return w;
  }

  double next_double() {
    return static_cast<double>( next() ) / ( static_cast<double>( UINT32_MAX ) + 1.0 );
  }

  int next_int(int min, int max) {
    return min + ( next() % ( max - min + 1 ) );
  }
};

constexpr double TIME_LIMIT = 1.9;
XorShift128 rnd;

ll n;
map<Pll, Pll> mcard, mpos;
struct State {
	State( ll size ) {
		rep( i, size * size / 2 ) {
			cards.eb( mp( i, 0 ) );
			cards.eb( mp( i, 1 ) );
		}
	}

	void swap_state( ll i, ll j ) {
		swap( cards[i], cards[j] );
	}

	vector<Pll> cards;
};

template<typename T> T calc_score( State &state ) {
	Pll pos( 0, 0 );
	vector<ll> card;

	ll movenum = 0;
	ll point = 0;

	arep( it, state.cards ) {
		ll nx = abs( pos.F - it.F );
		ll ny = abs( pos.S - it.S );
		movenum += nx + ny;
		if ( movenum >= 2 * n * n * n ) break;
		if ( movenum < 2 * n * n * n ) {
			card.pb( mcard[it].F );
			++movenum;
			if ( card.size() >= 2 ) {
				if ( card.back() == mcard[it].F ) {
					card.pop_back();
					card.pop_back();
					++point;
				}
			}
		}
		pos = it;
	}

	ll result = 0;
	if ( card.size() == 0 ) {
		result = n * n + 2 * n * n * n - movenum;
	} else {
		result = n * n - card.size();
	}

	return ( result );
}

void modify( State &state ) {
	ll bfr = rnd.next_int( 0, 199 );
	ll aft = rnd.next_int( 0, 199 );

	ll bfr_idx[2], aft_idx[2];
	ll bidx = 0, aidx = 0;
	rep( i, state.cards.size() ) {
		if ( state.cards[i].F == bfr ) {
			bfr_idx[bidx++] = i;
		}
		if ( state.cards[i].F == aft ) {
			aft_idx[aidx++] = i;
		}
	}

	state.swap_state( bfr_idx[0], aft_idx[0] );
	state.swap_state( bfr_idx[1], aft_idx[1] );
}

void output_result( State &state ) {
	Pll pos( 0, 0 );
	ll movenum = 0;
	constexpr ll TRIAL_MAX = 2 * 20 * 20 * 20;
	map<Pll, ll> mget;

	ll i = 0;
	if ( state.cards[0] == mcard[pos] ) {
		cout << "Z" << endl;
		++movenum; ++i;
	}

	for ( ; i < state.cards.size() && movenum < TRIAL_MAX; ++i ) {
		auto cpos = mpos[state.cards[i]];
		ll nx = cpos.F;
		ll ny = cpos.S;
		for ( ll j = 0;
			  j < abs( nx - pos.F ) && movenum < TRIAL_MAX;
			  ++j, ++movenum ) {
			if ( nx >= pos.F )
				cout << "D" << endl;
			else
				cout << "U" << endl;
		}
		for ( ll j = 0;
			  j < abs( ny - pos.S ) && movenum < TRIAL_MAX;
			  ++j, ++movenum ) {
			if ( ny >= pos.S )
				cout << "R" << endl;
			else
				cout << "L" << endl;
		}
		if ( movenum < TRIAL_MAX ) {
			if ( mget[cpos]++ == 0 ) {
				cout << "Z" << endl;
				++movenum;
			}
		} else {
			break;
		}
		pos = cpos;
	}
}

void solve_sa() {
	cin >> n;
	map<ll, ll> ma;
	rep( i, n ) {
		rep( j, n ) {
			ll a; cin >> a;
			if ( ma[a]++ > 0 ) {
				mcard[mp( i, j )] = mp( a, 1 );
				mpos[mp( a, 1 )] = mp( i, j );
			} else {
				mcard[mp( i, j )] = mp( a, 0 );
				mpos[mp( a, 0 )] = mp( i, j );
			}
		}
	}

	State state( n );

	double start_temp = 50.0, end_temp = 10.0;
	auto start_time = chrono::steady_clock::now();

	ll cnt = 1;
	while ( true ) {
		auto now_time = chrono::steady_clock::now();
		double elapse = chrono::duration<double>( now_time - start_time ).count();
		if ( elapse > TIME_LIMIT ) break;

		State new_state = state;
		modify( new_state );
		ll new_score = calc_score<ll>( new_state );
		ll pre_score = calc_score<ll>( state );

		double temp = start_temp + ( end_temp - start_temp ) * elapse / TIME_LIMIT;
		double prob = exp( ( new_score - pre_score ) / temp );

		if ( prob > rnd.next_double() ) {
			state = new_state;
		}
	}

	output_result( state );
}

int main()
{
	solve_sa();

	return ( 0 );
}

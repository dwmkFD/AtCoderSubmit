#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using ll = long long;
using llp = std::pair<ll, ll>;

int main()
{
	int N, K;
	std::cin >> N >> K;

	std::vector<llp> v( N );
	for ( int i = 0; i < N; i++ )
	{
		ll t, d;
		std::cin >> t >> d;
		v.emplace_back( std::make_pair( t, d ) );
	}

	// 基礎ポイントの降順にソート
	std::sort( v.begin(), v.end(), []( llp a, llp b ) {
			return ( a.second > b.second );
		} );

	std::map<ll, ll> m;
	ll pt = 0;
	for ( int i = 0; i < K; i++ )
	{
		pt += v[i].second;	//	大きい順にとりあえず詰める
		m[v[i].first]++;	//	出てきた種類をカウントしておく
	}

	ll ptmax = pt + m.size() * m.size();	//	暫定最高値
	ll prev = ptmax;	//	前回の値
	ll pp = m.size();	//	種類をメモ
	ll big = K;	// 基礎ポイントが高く、かつまだ詰めていない種類のネタを探す
	ll sml = K - 1; // 基礎ポイントが低く、かつ詰めてしまったものを探す

	// 最大K種類入れられるので、続きを探す
	for ( int i = 1; pp + i <= K; i++ )
	{
		// すでに入れてしまった中で、重複して入れたものを探す（削っても種類が減らないもの）
		while ( ( sml >= 0 ) && ( m[v[sml].first] <= 1 ) ) --sml;

		if ( sml < 0 )
		{
			// 削れるものがなにもないので、終了
			break;
		}

		ll ppp = pp + i;
		ll tmp = prev - v[sml].second + 2 * ppp - 1; // 1種類増えるので再計算
		m[v[sml].first]--; // 個数が一つ減る
		--sml;	//	さらに前を探す

		// まだ入れていないものを探す
		while ( ( big < N ) && ( m[v[big].first] > 0 ) ) ++big;

		if ( big >= N )
		{
			// これ以上のものがないので終了
			break;
		}

		tmp += v[big].second;	// 再計算
		m[v[big].first]++;		//	新規追加
		++big;

		if ( tmp > ptmax )
		{
			ptmax = tmp;
		}
		prev = tmp;
	}

	std::cout << ptmax << std::endl;

	return ( 0 );
}

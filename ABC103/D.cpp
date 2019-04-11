#include <iostream>
#include <vector>
#include <algorithm>

using myPair = std::pair<long, long>;

int main()
{
	long N, M;
	std::cin >> N >> M;

	std::vector<myPair> v;

	for ( int i = 0; i < M; i++ )
	{
		long tmpA, tmpB;
		std::cin >> tmpA >> tmpB;
		v.emplace_back( std::make_pair( tmpA, tmpB ) );
	}

	// vを、Biの値で昇順ソートする
	std::sort( v.begin(), v.end(), []( myPair a, myPair b ) {
			return( a.second < b.second );
		} );

	/*
	 * これで要望Mは、島Aiから行きたくない最西のBiがわかるように並んでいる（はず）
	 * この時、|Ai - Bi|が1になっている箇所の橋iは必ず切断する必要がある
	 * すると、Aiから、Ci（Ci > Bi）には絶対に辿り着けなくなるので、
	 * 西がBi未満であり、東がBi以上の島となっているMiは全て叶えられているので、除外して良い
	 * これを、全要素が除外されるまで繰り返せば、要望Mが全て叶えられる
	 *
	 * |Ai - Bi|が2以上であっても、Ai = Bi-1として、i番目の橋を切断すれば、
	 * その要望Miは叶えられたことになるので、切断した橋の番号bについて
	 * ・Mi(Ai, Bi)が叶えられていなければ、Bi-1とBiの間にあるb番目の橋を切断
	 * ・Mi(Ai, Bj)が叶えられていれば（＝i+1<=b<jのどこかの橋が切断されている）何もしない
	 * Biは昇順ソートされているので、以降、直前のbのみを覚えておき、Ai<bのみを調べれば良い
	 * bが更新される場合、それより手前の島Aiには、すでに（それ以前の要望Mによって）到達できなくなっているはずである
	 */
	long counter = 0;			//	橋を切断した本数
	long b = 0;					//	直前に切断した橋の番号

	for ( auto &&it : v )
	{
		if ( it.first > b )
		{
			// 橋がつながっている
			b = it.second - 1;		//	橋を切断して
			counter++;				//	その本数をカウントする
		}
	}

	std::cout << counter << std::endl;

	return ( 0 );
}

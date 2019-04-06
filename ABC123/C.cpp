#include <iostream>
#include <vector>
#include <algorithm>

using MyPair = std::pair<int, long long>;

int main()
{
	long long N, A, B, C, D, E;
	std::cin >> N >> A >> B >> C >> D >> E;

	// 経過時間
	long long totalTime = 0;

	// ボトルネックになってる箇所を調べるために、昇順ソートする
	std::vector<MyPair> v = { {0, A}, {1, B}, {2, C}, {3, D}, {4, E} };
	std::sort( v.begin(), v.end(), []( MyPair a, MyPair b ) {
			return ( a.second  < b.second );
			} );

	// ボトルネック箇所なので、最低必要な時間がこれ
	totalTime = N / v[0].second + ( N % v[0].second != 0 );

	// ボトルネックの箇所までかかる時間を足す
	totalTime += v[0].first; // 都市Nまでの移動時間をそのまま足せばOK

	// ボトルネックの箇所以降の時間を足す
	totalTime += ( 4 - v[0].first );

	std::cout << totalTime << std::endl;

	return ( 0 );
}

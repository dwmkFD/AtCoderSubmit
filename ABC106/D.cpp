#include <iostream>
#include <vector>

int main()
{
	long N, M, Q;
	std::cin >> N >> M >> Q;

	std::vector<std::pair<long, long> > vM;
	for ( long i = 0; i < M; i++ )
	{
		long tmp1, tmp2;
		std::cin >> tmp1 >> tmp2;
		vM.emplace_back( std::make_pair( tmp1, tmp2 ) );
	}

	std::vector<std::pair<long, long> > vQ;
	for ( long i = 0; i < Q; i++ )
	{
		long tmp1, tmp2;
		std::cin >> tmp1 >> tmp2;
		vQ.emplace_back( std::make_pair( tmp1, tmp2 ) );
	}

	// 累積和を計算する
	long num[500][500] = { 0 };
	long sum[501][501] = { 0 };

	for ( auto &&it : vM )
	{
		// 区間(p, q)を走る本数をカウント
		num[it.first - 1][it.second - 1]++;
	}

	for ( long i = 1; i <= N; i++ )
	{
		for ( long j = 1; j <= N; j++ )
		{
			sum[i][j] = num[i - 1][j - 1] + sum[i][j - 1];
		}
	}

	// 問題Qiが含む区間(pi, qi)の合計を求める
	for ( auto &&it : vQ )
	{
		long counter = 0;
		for ( long i = it.first; i <= it.second; i++ )
		{
			counter += sum[i][it.second];
		}
		std::cout << counter << std::endl;
	}

	return ( 0 );
}

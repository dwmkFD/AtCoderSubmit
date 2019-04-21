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

	// �ݐϘa���v�Z����
	long num[500][500] = { 0 };
	long sum[501][501] = { 0 };

	for ( auto &&it : vM )
	{
		// ���(p, q)�𑖂�{�����J�E���g
		num[it.first - 1][it.second - 1]++;
	}

	for ( long i = 1; i <= N; i++ )
	{
		for ( long j = 1; j <= N; j++ )
		{
			sum[i][j] = num[i - 1][j - 1] + sum[i][j - 1];
		}
	}

	// ���Qi���܂ދ��(pi, qi)�̍��v�����߂�
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

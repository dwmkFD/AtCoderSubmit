#include <iostream>
#include <vector>
#include <map>

auto factorize( int n )
{
	std::vector< std::pair<int, int> > res;

	for ( int i = 2; i <= n; i++ )
	{
		if ( ( n % i ) == 0 )
		{
			int cnt = 0;
			while ( ( n % i ) == 0 )
			{
				n /= i;
				cnt++;
			}

			res.emplace_back( std::make_pair( i, cnt ) );
		}
	}

	return ( res );
}

auto comb( int n, int r )
{
	std::vector<std::vector<long long> > v( n + 1, std::vector<long long>( n + 1, 0 ) );
	for ( int i = 0; i < v.size(); i++ )
	{
		v[i][0] = 1;
		v[i][i] = 1;
	}

	for ( int j = 1; j < v.size(); j++ )
	{
		for ( int k = 1; k < j; k++ )
		{
			v[j][k] = v[j - 1][k - 1] + v[j - 1][k];
		}
	}

	return ( v[n][r] );
}

int main()
{
	int N;
	std::cin >> N;

	std::vector<int> v;
	std::map<int, int> m;

	for ( int i = 2; i <= N; i++ )
	{
		auto tmp = factorize( i );

		for ( auto &&it : tmp )
		{
			m[it.first] += it.second;
		}
	}

	// �񐔂�75�����߂ɂ́A
	// N!�̑f����x, y, z...��p^n, q^m, r^l...�̎��A
	// ����An = n, m, l, ...�ƒ�`����ƁA
	// (n + 1�ȉ�) * (m + 1�ȉ�) * (l + 1�ȉ�) ... = 75
	// �ƂȂ�g�ݍ��킹��S�ċ��߂��OK
	// 75 = 3 * 5^2 �Ȃ̂ŁA�񐔂� 1, 3, 5, 15, 25, 75��6����
	//
	// 74 �ȏ�̂��̂�������I��
	// 24 �ȏ�̂��̂���A2�ȏ�̂��̂���I��
	// 14 �ȏ�̂��̂���A4�ȏ�̂��̂���I��
	// 4�ȏ�̂��̂�2�A2�ȏ�̂��̂���I��
	//
	// �ȏ�̑g�ݍ��킹���A���߂�S�g�ݍ��킹�ɂȂ�
	int counter = 0;
	int A[] = { 3, 5, 15, 25, 75, 9999999 };
	std::map<int, std::vector<int> > mm;
	for ( int i = 4; i >= 0; --i )
	{
		for ( auto &&it : m )
		{
			if ( it.second >= ( A[i] - 1 ) )
			{
				mm[A[i]].emplace_back( it.first );
			}
		}
	}

#if 0
	std::cout << N << "!" << std::endl;
	for ( auto &&it : m )
	{
		std::cout << it.first << "^" << it.second << std::endl;
	}
	for ( auto &&it : mm )
	{
		std::cout << it.first << ":" << it.second.size() << std::endl;
	}
#endif

	// 75 * 1
	counter += mm[75].size();

	// 25 * 3
	counter += ( mm[25].size() ) * ( mm[3].size() - 1 );

	// 15 * 5
	counter += ( mm[15].size() ) * ( mm[5].size() - 1 );

	// 5 * 5 * 3
	counter += comb( mm[5].size(), 2 ) * ( mm[3].size() - 2 );

	std::cout << counter << std::endl;

	return ( 0 );
}

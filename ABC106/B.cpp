#include <iostream>
#include <vector>

int main()
{
	int N;
	std::cin >> N;

	long counter;
	std::vector<int> v;

	v.emplace_back( 105 ); // 105以下で条件を満たすのは105だけ

	// Nは最大200なので、ゴリ押し（全探索）
	for ( int i = 107; i <= N; i += 2 )	//	107から探す
	{
		counter = 0;
		for ( int j = 1; j <= N; j += 2 )	//	奇数でしか割れない
		{
			if ( i % j == 0 )
			{
				counter++;
			}
		}
		if ( counter == 8 )
		{
			v.emplace_back( i );
		}
	}

	if ( N < 105 )
	{
		std::cout << "0" << std::endl;
	}
	else
	{
		std::cout << v.size() << std::endl;
	}

	return ( 0 );
}

#include <iostream>
#include <vector>

int main()
{
	int N;
	std::cin >> N;

	long counter;
	std::vector<int> v;

	v.emplace_back( 105 ); // 105�ȉ��ŏ����𖞂����̂�105����

	// N�͍ő�200�Ȃ̂ŁA�S�������i�S�T���j
	for ( int i = 107; i <= N; i += 2 )	//	107����T��
	{
		counter = 0;
		for ( int j = 1; j <= N; j += 2 )	//	��ł�������Ȃ�
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

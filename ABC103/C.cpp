#include <iostream>
#include <vector>

int main()
{
	int N;
	std::cin >> N;

	std::vector<int> v( N );

	for ( int i = 0; i < N; i++ )
	{
		std::cin >> v[i];
	}

	// ����X�ɂ��āA�]��̍ő�l�́AX-1�ł���
	long total = 0;
	for ( auto &&it : v )
	{
		total += it - 1;	//	�܂�A�ő�l��S�����v����Ηǂ�
	}

	std::cout << total << std::endl;

	return ( 0 );
}

#include <iostream>

int main()
{
	unsigned int n, k;
	std::cin >> n >> k;

	if ( n == k )
	{
		// N��K�����������1��ŏI���
		std::cout << "1" << std::endl;
	}
	else
	{
		if ( ( n - 1 ) % ( k - 1 ) )
		{
			// �]�肪�o��Ȃ�؂�グ��
			std::cout << ( ( n - 1 ) / ( k - 1 ) ) + 1 << std::endl;
		}
		else
		{
			std::cout << ( n - 1 ) / ( k - 1 ) << std::endl;
		}
	}

	return ( 0 );
}

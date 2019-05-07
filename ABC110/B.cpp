#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int N, M, X, Y;
	std::cin >> N >> M >> X >> Y;

	std::vector<int> x( N ), y( M );
	for ( int i = 0; i < N; i++ )
	{
		std::cin >> x[i];
	}

	for ( int i = 0; i < M; i++ )
	{
		std::cin >> y[i];
	}

	bool isWar = false;
	std::sort( x.begin(), x.end() );
	std::sort( y.begin(), y.end() );

	if ( x[N - 1] >= y[0] )
	{
		// xn�̈�ԑ傫�����ym�̈�ԏ���������傫��������_��
		isWar = true;
	}

	for ( int i = x[N - 1] + 1; i <= y[0]; i++ )
	{
		if ( ( X >= i ) || ( i > Y ) )
		{
			// X < Z <= Y �𖞂����Ȃ�
			// �����O�̏������AZ�͈̔͂�x[N-1] to y[0]�ɂ���
			isWar = true;
		}
	}

	if ( isWar )
	{
		std::cout << "War" << std::endl;
	}
	else
	{
		std::cout << "No War" << std::endl;
	}

	return ( 0 );
}


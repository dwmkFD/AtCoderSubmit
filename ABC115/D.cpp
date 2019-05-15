#include <iostream>

using ull = unsigned long long;

ull pow2( ull n )
{
	ull base = 1;
	for ( int i = 0; i < n; i++ )
	{
		base *= 2;
	}

	return ( base );
}

int main()
{
	int N;
	ull X;
	std::cin >> N >> X;

	// ���x��N�o�[�K�[�̉�����N�w�̓o���ł���
	// P
	// BPPPB
	// BBPPPBPBPPPBB
	// BBBPPPBPBPPPBBPBBPPPBPBPPPBBB
	// ���x��N�o�[�K�[�̉����璆���̃p�e�B�܂ł̑w�Ɋ܂܂��p�e�B�̐��́A
	// 2^N���ł���i������1�����܂ށj
	// ���x��N�o�[�K�[�̑w�̑�����Ln = (2^N+1 - 1)+(2^N+1 - 2) = 2^N+2 - 3���ł���

	ull p = pow2( N + 2 ); // N�͍ő�50�Ȃ̂ŁAull�^�Ŏ��܂�
	ull counter = 0;

	while ( ( X > 0 ) && ( N >= 0 ) )
	{
#ifdef DEBUG_PRINT
		std::cout << "Lv : " << N << std::endl;
		std::cout << "all: " << p - 3 << std::endl;
		std::cout << "X  : " << X << std::endl;
		std::cout << "mid: " << ( p - 3 ) / 2 << std::endl;
#endif

		if ( X < ( p - 3 ) / 2 + 1 )
		{
			// �����������w�܂ł̎�
			// �������Ȃ�
		}
		else
		{
			// ����������w�̎�
			counter += pow2( N );	//	�����������w�Ɋ܂܂��p�e�B�͑S���H�ׂ�

			// ��w�̎��́A�H�ׂ鑤�Ƀo�����܂܂�Ă���̂Ŏ�菜���Ȃ����A
			// ���w������H�׏I���Ă���̂ŁAX�͂��̕����炷
			X -= ( p - 3 ) / 2 + 1;
			++X;	//	�������Ă���
		}
#ifdef DEBUG_PRINT
		std::cout << "eat: " << counter << std::endl;
#endif

		--N; // ���x����1�i������
		--X; // ���x���A�b�v���ɗ��[�Ƀo�����ǉ�����Ă���̂ŁA�������菜��
		p = pow2( N + 2 ); // �Čv�Z
	}

	std::cout << counter << std::endl;

	return ( 0 );
}

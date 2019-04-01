#include <iostream>

int main()
{
	unsigned int a, b;
	std::cin >> a >> b;

	int cake[16] = { 0 };

	// �ǂ��炪������H�̃}�[�N
	int getCake = 1;

	while ( ( a > 0 ) && ( b > 0 ) )
	{
		int prevA = a;
		int prevB = b;
		for ( int i = 0; i < 16; i++ )
		{
			int prev = cake[(i + 15) % 16];
			int next = cake[(i +  1) % 16];

			// ���[���ʂ�H
			if ( ( ( prev != getCake ) && ( next != getCake ) )
				 && ( cake[i] == 0 )	//	�N������ĂȂ�
				)
			{
				if ( getCake == 1 )
				{
					if ( a > 0 )
					{
						a--;
						cake[i] = getCake;
					}
				}
				else
				{
					if ( b > 0 )
					{
						b--;
						cake[i] = getCake;
					}
				}
			}
			else
			{
				// �_���Ȃ�X�L�b�v
			}
			getCake *= -1;
		}

		if ( ( prevA == a ) || ( prevB == b ) )
		{
			// ���[�v�O�ƒl���ς���ĂȂ����������Ȃ��̂Œ��߂�
			break;
		}
	}

	// �S����ꂽ�H
	if ( ( a == 0 ) && ( b == 0 ) )
	{
		std::cout << "Yay!" << std::endl;
	}
	else
	{
		std::cout << ":(" << std::endl;
	}

	return ( 0 );
}

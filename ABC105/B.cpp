#include <iostream>

int main()
{
	long N;
	std::cin >> N;

	// N��100�ȉ��Ȃ̂ŁA��������ł��Ԃɍ����̂ł́c�H
	for ( int x = 0;; x++ )
	{
		for ( int y = 0;; y++ )
		{
			long z = 4 *x + 7 * y;
			if ( z == N )
			{
				std::cout << "Yes" << std::endl;
				goto END;
			}
			else if ( z > N )
			{
				// ���z�I�[�o�[�Ȃ̂ŏI��
				break;
			}
		}

		if ( 4 * x > N )
		{
			// �����܂�x�𑝂₷�܂łɁA�����𖞂���y�����݂��Ȃ������̂ŁA�_��
			break;
		}
	}

	std::cout << "No" << std::endl;
END:

	return ( 0 );
}

#include <iostream>
#include <string>

int main()
{
	std::string S;
	std::cin >> S;

	if ( S.at( 0 ) == 'A' )
	{
		int counter = 0;
		int index = 0;
		for ( int i = 2; i <= S.length() - 2; i++ )
		{
			if ( S.at( i ) == 'C' )
			{
				counter++;
				index = i;	//	C���o�Ă����ʒu���o���Ă���
			}
		}

		if ( counter == 1 )
		{
			// �擪��C���o�Ă����ʒu�ȊO���p���������ǂ������`�F�b�N
			for ( int i = 1; i < S.length(); i++ )
			{
				if ( i != index )
				{
					char tmp = S.at( i );

					if ( tmp >= 'a' && tmp <= 'z' )
					{
						// OK
					}
					else
					{
						// �p�������ȊO���܂�ł���̂�NG
						std::cout << "WA" << std::endl;
						return ( 0 );
					}
				}
			}

			// for������肫������OK�Ȃ̂ŁAAC���o��
			std::cout << "AC" << std::endl;
		}
		else
		{
			// C��2��ȏ�������͈���܂܂Ȃ��̂Ń_��
			std::cout << "WA" << std::endl;
		}
	}
	else
	{
		// �擪��A�łȂ���΃_��
		std::cout << "WA" << std::endl;
	}

	return ( 0 );
}

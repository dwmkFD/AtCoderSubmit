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
				index = i;	//	Cが出てきた位置を覚えておく
			}
		}

		if ( counter == 1 )
		{
			// 先頭とCが出てきた位置以外が英小文字かどうかをチェック
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
						// 英小文字以外を含んでいるのでNG
						std::cout << "WA" << std::endl;
						return ( 0 );
					}
				}
			}

			// for文を回りきったらOKなので、ACを出力
			std::cout << "AC" << std::endl;
		}
		else
		{
			// Cを2回以上もしくは一つも含まないのでダメ
			std::cout << "WA" << std::endl;
		}
	}
	else
	{
		// 先頭はAでなければダメ
		std::cout << "WA" << std::endl;
	}

	return ( 0 );
}

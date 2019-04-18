#include <iostream>
#include <string>

int main()
{
	std::string S;
	long long K;

	std::cin >> S >> K;

	// 1以外の文字は、N^5000兆文字増える
	// -> Sを左から見ていって、初めて出てきた1以外の文字が、K番目の文字
	char ans;
	int i;
	for ( i = 0; i < S.length(); i++ )
	{
		if ( S[i] != '1' )
		{
			ans = S[i];
			break;
		}
	}

	// ただし、Kがiより小さい場合は1になる
	if ( K <= i )
	{
		std::cout << "1" << std::endl;
	}
	else
	{
		std::cout << ans << std::endl;
	}

	return ( 0 );
}

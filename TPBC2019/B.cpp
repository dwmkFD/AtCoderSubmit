#include <iostream>
#include <string>

int main()
{
	std::string S;
	int N, K;
	std::cin >> N >> S >> K;

	char c = S[K - 1];

	for ( int i = 0; i < S.length(); i++ )
	{
		if ( S[i] != c )
		{
			S[i] = '*';
		}
	}

	std::cout << S << std::endl;

	return ( 0 );
}

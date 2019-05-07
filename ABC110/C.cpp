#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
	std::string S, T;
	std::cin >> S >> T;

	std::vector<int> sv( 26 ), tv( 26 );

	for ( int i = 0; i < S.length(); i++ )
	{
		// S, Tのアルファベットの出現頻度を数える
		sv[S[i] - 'a']++;
		tv[T[i] - 'a']++;
	}

	std::sort( sv.begin(), sv.end() );
	std::sort( tv.begin(), tv.end() );

	bool isYes = true;
	for ( int i = 0; i < sv.size(); i++ )
	{
		if ( sv[i] != tv[i] )
		{
			isYes = false;
			break;
		}
	}

	std::cout << ( isYes ? "Yes" : "No" ) << std::endl;

	return ( 0 );
}

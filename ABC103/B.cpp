#include <iostream>
#include <string>

int main()
{
	std::string s, t;
	std::cin >> s >> t;

	bool bSame = false;

	for ( int i = 0; i < s.length(); i++ )
	{
		if ( s == t )
		{
			bSame = true;
			break;
		}

		s.insert( s.begin(), s.back() );	//	ÅŒã‚Ì•¶Žš‚ðæ“ª‚ÉŽ‚Á‚Ä‚«‚Ä
		s.erase( s.length() - 1 );			//	ÅŒã‚Ì•¶Žš‚ðíœ‚·‚é
	}

	if ( bSame )
	{
		std::cout << "Yes" << std::endl;
	}
	else
	{
		std::cout << "No" << std::endl;
	}

	return ( 0 );
}

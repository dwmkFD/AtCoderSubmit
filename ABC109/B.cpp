#include <iostream>
#include <string>
#include <map>

int main()
{
	int N;
	std::cin >> N;

	bool rule = true;
	std::map<std::string, int> m;
	char cBack = 0;

	std::string tmp;
	std::cin >> tmp;
	m[tmp]++;
	cBack = tmp.back();

	for ( int i = 1; i < N; i++ )
	{
		std::cin >> tmp;

		if ( ( m[tmp]++ != 0 ) || ( tmp[0] != cBack ) )
		{
			rule = false;
			break;
		}
		else
		{
			cBack = tmp.back();
		}
	}

	if ( rule )
	{
		std::cout << "Yes" << std::endl;
	}
	else
	{
		std::cout << "No" << std::endl;
	}

	return ( 0 );
}

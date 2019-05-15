#include <iostream>
#include <map>

int f( int n )
{
	if ( n % 2 )
	{
		return ( 3 * n + 1 );
	}
	else
	{
		return ( n / 2 );
	}
}

int main()
{
	int s;
	std::cin >> s;

	std::map<int, int> m;
	m[s]++;

	int tmp = s;
	long counter = 1;
	while ( 1 )
	{
		tmp = f( tmp );
		if ( m[tmp] != 0 )
		{
			std::cout << counter + 1 << std::endl;
			break;
		}
		else
		{
			m[tmp]++;
			counter++;
		}
	}

	return ( 0 );
}

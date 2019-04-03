#include <iostream>

int main()
{
	unsigned int n, k;
	std::cin >> n >> k;

	if ( n == k )
	{
		// N‚ÆK‚ª“™‚µ‚¯‚ê‚Î1‰ñ‚ÅI‚í‚è
		std::cout << "1" << std::endl;
	}
	else
	{
		if ( ( n - 1 ) % ( k - 1 ) )
		{
			// —]‚è‚ªo‚é‚È‚çØ‚èã‚°‚é
			std::cout << ( ( n - 1 ) / ( k - 1 ) ) + 1 << std::endl;
		}
		else
		{
			std::cout << ( n - 1 ) / ( k - 1 ) << std::endl;
		}
	}

	return ( 0 );
}

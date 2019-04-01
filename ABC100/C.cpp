#include <iostream>
#include <vector>

bool check_value( std::vector<unsigned long long> &v )
{
	for ( auto &&it : v )
	{
		if ( ( it & 1 ) == 0 )
		{
			// ˆê‚Â‚Å‚à‹ô”‚ªŒ©‚Â‚©‚ê‚ÎOK
			it >>= 1;	//	æ‚É2‚ÅŠ„‚Á‚Ä‚¨‚­
			return ( true );
		}
	}

	// ‘S•”Šï”
	return ( false );
}

int main()
{
	unsigned int n;
	std::vector<unsigned long long> v;

	std::cin >> n;
	for ( int i = 0; i < n; i++ )
	{
		unsigned long long tmp;
		std::cin >> tmp;
		v.emplace_back( tmp );
	}

	unsigned long long counter = 0;
	while ( check_value( v ) )
	{
		counter++;
	}

	std::cout << counter << std::endl;

	return ( 0 );
}

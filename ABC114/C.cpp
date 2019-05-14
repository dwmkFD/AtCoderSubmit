#include <iostream>
#include <vector>
#include <string>

long long N;

bool chk( std::string input )
{
	int cnt = 0;
	char c[] = { '3', '5', '7' };

	for ( int i = 0; i < 3; i++ )
	{
		cnt += ( input.find( c[i] ) != std::string::npos );
	}

	return ( cnt >= 3 );
}

int solv( std::string input )
{
	if ( std::stoll( input ) > N )
	{
		return ( 0 );
	}
	else
	{
		int ret = ( chk( input ) == true );
		for ( auto &&it : {'3', '5', '7' } )
		{
			ret += solv( input + it );
		}
		return ( ret );
	}
}

int main()
{
	std::cin >> N;

	std::cout << solv( "0" ) << std::endl;

	return ( 0 );
}

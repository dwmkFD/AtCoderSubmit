#include <iostream>
#include <vector>
#include <tuple>

long myPOW2( long p )
{
	long result = 1;

	for ( long i = 0; i < p; i++ )
	{
		result *= 2;
	}

	return ( result );
}

int main()
{
	long L;
	std::cin >> L;

	int r = 0;
	long tmpL;
	while( myPOW2( r ) <= L ) { ++r; }

	long N = r;
	std::vector<std::tuple<long, long, long> > v;

	for ( int i = 1; i < N; ++i )
	{
		// ’¸“_i‚©‚çi+1‚Ö’·‚³0‚Ì•Ó‚Æ’·‚³2^i‚Ì•Ó‚ð’£‚é
		v.emplace_back( std::make_tuple( i, i + 1, 0 ) );
		v.emplace_back( std::make_tuple( i, i + 1, myPOW2( i - 1 ) ) );
	}

	for ( int t = N - 1; t >= 1; --t )
	{
		if ( L - myPOW2( t - 1 ) >= myPOW2( r - 1 ) )
		{
			v.emplace_back( t, N, L - myPOW2( t - 1 ) );
			L -= myPOW2( t - 1 );
		}
	}

	std::cout << N << " " << v.size() << std::endl;
	for ( auto &&it : v )
	{
		std::cout << std::get<0>( it ) << " "
				  << std::get<1>( it ) << " "
				  << std::get<2>( it ) << std::endl;
	}

	return ( 0 );
}

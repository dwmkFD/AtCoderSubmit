#include <iostream>
#include <vector>

bool check_value( std::vector<unsigned long long> &v )
{
	for ( auto &&it : v )
	{
		if ( ( it & 1 ) == 0 )
		{
			// 一つでも偶数が見つかればOK
			it >>= 1;	//	先に2で割っておく
			return ( true );
		}
	}

	// 全部奇数
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

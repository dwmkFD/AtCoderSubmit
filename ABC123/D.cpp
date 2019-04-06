#include <iostream>
#include <vector>

int main()
{
	unsigned long long X, Y, Z, K;
	std::cin >> X >> Y >> Z >> K;

	std::vector<unsigned long long> A;
	std::vector<unsigned long long> B;
	std::vector<unsigned long long> C;

	for ( int i = 0; i < X; i++ )
	{
		unsigned long long tmp;
		std::cin >> tmp;
		A.emplace_back( tmp );
	}

	for ( int i = 0; i < Y; i++ )
	{
		unsigned long long tmp;
		std::cin >> tmp;
		B.emplace_back( tmp );
	}

	for ( int i = 0; i < Z; i++ )
	{
		unsigned long long tmp;
		std::cin >> tmp;
		C.emplace_back( tmp );
	}



	return ( 0 );
}

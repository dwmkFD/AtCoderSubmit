#include <iostream>

int main()
{
	int A, B;
	std::cin >> A >> B;

	if ( ( A & 1 ) && ( B & 1 ) )
	{
		std::cout << "Yes" << std::endl;
	}
	else
	{
		std::cout << "No" << std::endl;
	}

	return ( 0 );
}

#include <iostream>

int main()
{
	int N;
	std::cin >> N;

	if ( N == 1 )
	{
		std::cout << "Hello World" << std::endl;
	}
	else
	{
		int A, B;
		std::cin >> A >> B;

		std::cout << A + B << std::endl;
	}

	return ( 0 );
}

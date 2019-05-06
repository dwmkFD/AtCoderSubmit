#include <iostream>

int main()
{
	int A, B, T;
	double T05 = 0;
	std::cin >> A >> B >> T;
	int A_base = A;
	T05 = T + 0.5;

	int counter = 0;
	while ( A <= T05 )
	{
		counter += B;
		A += A_base;
	}

	std::cout << counter << std::endl;

	return ( 0 );
}

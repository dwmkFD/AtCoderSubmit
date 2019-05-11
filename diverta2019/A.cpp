#include <iostream>

int main()
{
	int N, K;
	std::cin >> N >> K;

	unsigned long long counter = 0;

	for ( int i = 0; i < N - K + 1; i++ )
	{
		counter++;
	}

	std::cout << counter << std::endl;

	return ( 0 );
}

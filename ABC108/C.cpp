#include <iostream>

int main()
{
	long N, K;
	std::cin >> N >> K;

	long counter1 = 0, counter2 = 0;

	for ( long i = 1; i <= N; i++ )
	{
		if ( ( i % K ) == 0 )
		{
			++counter1;
		}
		else if ( ( ( K & 1 ) == 0 )
				  && ( ( i % K ) == ( K / 2 ) )
			)
		{
			++counter2;
		}
	}

	long result;
	result = counter1 * counter1 * counter1;
	result += counter2 * counter2 * counter2;

	std::cout << result << std::endl;

	return ( 0 );
}

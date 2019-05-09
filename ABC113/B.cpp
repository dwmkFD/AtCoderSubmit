#include <iostream>
#include <vector>

double abs_( double x )
{
	return ( x > 0 ? x : -x );
}

int main()
{
	int N, T, A;
	std::cin >> N >> T >> A;

	std::vector<double> v( N );
	for ( int i = 0; i < N; i++ )
	{
		std::cin >> v[i];
		v[i] = T - v[i] * 0.006;
	}

	double j = 0;
	for ( int i = 1; i < N; i++ )
	{
		if ( abs_( v[i] - A ) < abs_( v[j] - A ) )
		{
			j = i;
		}
	}

	std::cout << j + 1 << std::endl;

	return ( 0 );
}

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	unsigned long long N;
	cin >> N;

	unsigned long long sum = 0;
	for ( unsigned long long i = 2; i < N; i++ )
	{
		for ( unsigned long long j = 2; j < max( N / j, N % j ); j++ )
		{

		}
	}

	return ( 0 );
}

#include <iostream>

int main()
{
	int R, G, B, N;
	std::cin >> R >> G >> B >> N;

	unsigned long long counter = 0;

	for ( int r = 0; r <= 3000; r++ )
	{
		int rN = r * R;
		for ( int g = 0; g <= 3000 - r; g++ )
		{
			int gN = g * G;

			if ( rN + gN <= N )
			{
				if ( ( ( N - ( rN + gN ) ) % B ) == 0 )
				{
					counter++;
				}
			}
			else
			{
				break;
			}
		}
	}

	std::cout << counter << std::endl;

	return ( 0 );
}

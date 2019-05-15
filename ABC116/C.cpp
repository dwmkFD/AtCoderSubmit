#include <iostream>
#include <vector>

// ‹æŠÔ(l, r)‚ÌÅ¬’l‚ğ‹‚ß‚é
int solv( std::vector<int> &in, int l, int r )
{
	int result = 101;
	int idx = 0;
	if ( l >= r )
	{
		return ( 0 );
	}

	for ( int i = l; i < r; i++ )
	{
		if ( in[i] < result )
		{
			result = in[i];
			idx = i;
		}
	}
	for ( int i = l; i < r; i++ )
	{
		in[i] -= result;
	}

	return ( result + solv( in, l, idx ) + solv( in, idx + 1, r ) );
}

int main()
{
	int N;
	std::cin >> N;

	std::vector<int> v( N );
	for ( int i = 0; i < N; i++ )
	{
		std::cin >> v[i];
	}

	std::cout << solv( v, 0, N ) << std::endl;

	return ( 0 );
}

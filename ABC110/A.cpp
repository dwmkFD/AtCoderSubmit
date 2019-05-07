#include <iostream>

int main()
{
	int A, B, C;
	std::cin >> A >> B >> C;

	int ans;
	if ( A > B )
	{
		if ( A > C )
		{
			ans = A * 10 + B + C;
		}
		else
		{
			ans = C * 10 + B + A;
		}
	}
	else
	{
		if ( C > B )
		{
			ans = C * 10 + B + A;
		}
		else
		{
			ans = B * 10 + A + C;
		}
	}

	std::cout << ans << std::endl;

	return ( 0 );
}

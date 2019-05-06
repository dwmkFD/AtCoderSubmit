#include <iostream>

inline int myABS( int v )
{
	return ( v > 0 ? v : -v );
}

int main()
{
	int x1, x2, y1, y2;
	int x3, x4, y3, y4;
	std::cin >> x1 >> y1 >> x2 >> y2;

	if ( x1 >= x2 )
	{
		if ( y1 >= y2 )
		{
			x3 = x2 + myABS( y1 - y2 );
			y3 = y2 - myABS( x1 - x2 );

			x4 = x3 + myABS( y2 - y3 );
			y4 = y3 + myABS( x2 - x3 );
		}
		else
		{
			x3 = x2 - myABS( y1 - y2 );
			y3 = y2 - myABS( x1 - x2 );

			x4 = x3 + myABS( y2 - y3 );
			y4 = y3 - myABS( x2 - x3 );
		}
	}
	else
	{
		if ( y1 >= y2 )
		{
			x3 = x2 + myABS( y1 - y2 );
			y3 = y2 + myABS( x1 - x2 );

			x4 = x3 - myABS( y2 - y3 );
			y4 = y3 + myABS( x2 - x3 );
		}
		else
		{
			x3 = x2 - myABS( y1 - y2 );
			y3 = y2 + myABS( x1 - x2 );

			x4 = x3 - myABS( y2 - y3 );
			y4 = y3 - myABS( x2 - x3 );
		}
	}

	std::cout << x3 << " " << y3 << " " << x4 << " " << y4 << std::endl;

	return ( 0 );
}

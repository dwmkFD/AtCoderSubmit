#include <iostream>

int MyABS( int x, int y )
{
	return ( x < y ? y - x : x - y );
}

int main()
{
	int a, b, c, d, e, k;
	std::cin >> a >> b >> c >> d >> e >> k;

	int ab, ac, ad, ae;
	int bc, bd, be;
	int cd, ce;
	int de;

	ab = MyABS( a, b );
	ac = MyABS( a, c );
	ad = MyABS( a, d );
	ae = MyABS( a, e );
	bc = MyABS( b, c );
	bd = MyABS( b, d );
	be = MyABS( b, e );
	cd = MyABS( c, d );
	ce = MyABS( c, e );
	de = MyABS( d, e );

	bool bConnect = true;
	if ( ab > k )
	{
		bConnect = false;
	}

	if ( ac > k )
	{
		bConnect = false;
	}

	if ( ad > k )
	{
		bConnect = false;
	}

	if ( ae > k )
	{
		bConnect = false;
	}

	if ( bc > k )
	{
		bConnect = false;
	}

	if ( bd > k )
	{
		bConnect = false;
	}

	if ( be > k )
	{
		bConnect = false;
	}

	if ( cd > k )
	{
		bConnect = false;
	}

	if ( ce > k )
	{
		bConnect = false;
	}

	if ( de > k )
	{
		bConnect = false;
	}

	if ( bConnect )
	{
		std::cout << "Yay!" << std::endl;
	}
	else
	{
		std::cout << ":(" << std::endl;
	}

	return ( 0 );
}

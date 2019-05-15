#include <iostream>

int main()
{
	int D;
	std::cin >> D;

	switch ( D )
	{
	case 25:
		std::cout << "Christmas" << std::endl;
		break;

	case 24:
		std::cout << "Christmas Eve" << std::endl;
		break;

	case 23:
		std::cout << "Christmas Eve Eve" << std::endl;
		break;

	case 22:
		std::cout << "Christmas Eve Eve Eve" << std::endl;
		break;
	default:
		break;
	}

	return ( 0 );
}

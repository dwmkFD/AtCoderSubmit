#include <iostream>
#include <vector>

int main()
{
	int H, W;
	std::cin >> H >> W;

	char A[100][100] = { 0 };
	for ( int i = 0; i < H; i++ )
	{
		char tmpbuf[100];
		std::cin >> tmpbuf;
		for ( int j = 0; j < W; j++ )
		{
			A[i][j] = tmpbuf[j];
		}
	}

	bool bErase;
	do {
		bErase = false;

		for ( int i = 0; i < H; i++ )
		{
			int j;
			for ( j = 0; j < W; j++ )
			{
				if ( A[i][j] == '#' )
				{
					break;
				}
			}

			if ( j == W )
			{
				for ( int k = i; k < H - 1; k++ )
				{
					for ( int l = 0; l < W; l++ )
					{
						// ˆês‹l‚ß‚é
						A[k][l] = A[k + 1][l];
					}
				}
				for ( int l = 0; l < W; l++ )
				{
					A[H - 1][l] = 0;	//	ÅŒã‚Ìs‚ðÁ‚·
				}
				--H;	//	ˆêsŒ¸‚ç‚·

				bErase = true;
			}
		}
	} while ( bErase );

	do {
		bErase = false;

		for ( int i = 0; i < W; i++ )
		{
			int j;
			for ( j = 0; j < H; j++ )
			{
				if ( A[j][i] == '#' )
				{
					break;
				}
			}

			if ( j == H )
			{
				for ( int k = 0; k < H; k++ )
				{
					for ( int l = i; l < W - 1; l++ )
					{
						// ˆê—ñ‹l‚ß‚é
						A[k][l] = A[k][l + 1];
					}
				}
				for ( int k = 0; k < H; k++ )
				{
					A[k][W - 1] = 0;	//	ÅŒã‚Ì—ñ‚ðÁ‚·
				}
				--W;	//	ˆê—ñŒ¸‚ç‚·

				bErase = true;
			}
		}
	} while ( bErase );

	for ( int i = 0; i < 100; i++ )
	{
		for ( int j = 0; j < 100; j++ )
		{
			if ( A[i][j] != 0 )
			{
				std::cout << A[i][j];
			}
		}
		if ( A[i][0] != 0 )
		{
			std::cout << std::endl;
		}
	}

	return ( 0 );
}

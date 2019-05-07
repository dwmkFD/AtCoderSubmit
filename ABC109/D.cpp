#include <iostream>
#include <vector>

int main()
{
	int H, W;
	std::cin >> H >> W;

	std::vector< std::vector<int> > v( H, std::vector<int>( W ) );
	for ( int i = 0; i < H; ++i )
	{
		for ( int j = 0; j < W; ++j )
		{
			std::cin >> v[i][j];
		}
	}

	int counter = 0;
	std::vector< std::pair< std::pair<int, int>, std::pair<int, int> > > vv;

	for ( int i = 0; i < H; ++i )
	{
		if ( i & 1 )
		{
			// Šï”‚È‚çW-1‚©‚ç
			for ( int j = W - 1; j > 0; --j )
			{
				if ( v[i][j] & 1 )
				{
					v[i][j - 1]++;
					v[i][j]--;
					vv.emplace_back( std::make_pair( i, j ), std::make_pair( i, j - 1 ) );
					counter++;
				}
			}
			if ( ( v[i][0] & 1 ) && ( i != H - 1 ) )
			{
				v[i + 1][0]++;
				v[i][0]--;
				vv.emplace_back( std::make_pair( i, 0 ), std::make_pair( i + 1, 0 ) );
				counter++;
			}
		}
		else
		{
			// ‹ô”‚È‚ç0‚©‚ç
			for ( int j = 0; j < W - 1; ++j )
			{
				if ( v[i][j] & 1 )
				{
					v[i][j + 1]++;
					v[i][j]--;
					vv.emplace_back( std::make_pair( i, j ), std::make_pair( i, j + 1 ) );
					counter++;
				}
			}
			if ( ( v[i][W - 1] & 1 ) && ( i != H - 1 ) )
			{
				v[i + 1][W - 1]++;
				v[i][W - 1]--;
				vv.emplace_back( std::make_pair( i, W - 1 ), std::make_pair( i + 1, W - 1 ) );
				counter++;
			}
		}
	}

	std::cout << counter << std::endl;
	for ( auto &&it : vv )
	{
		std::cout << it.first.first + 1 << " " << it.first.second + 1 << " "
				  << it.second.first + 1 << " " << it.second.second + 1 << std::endl;
	}

	return ( 0 );
}

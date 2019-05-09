#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using myTuple = std::tuple<int, int, int>;

inline int abs_( int x )
{
	return ( x > 0 ? x : -x );
}

inline int max_( int x, int y )
{
	return ( x > y ? x : y );
}

int main()
{
	int N;
	std::cin >> N;

	std::vector< std::tuple<int, int, int> > v;
	for ( int i = 0; i < N; i++ )
	{
		int x, y, h;
		std::cin >> x >> y >> h;
		v.emplace_back( std::make_tuple( x, y, h ) );
	}

	int Cx, Cy, Ch;

	if ( N == 1 )
	{
		// 座標が1つしか与えられなかった場合は、それを中心座標とする（それ以外情報が無いので）
		Cx = std::get<0>( v[0] );
		Cy = std::get<1>( v[0] );
		Ch = std::get<2>( v[0] );
	}
	else
	{
		for ( int i = 0; i <= 100; i++ )
		{
			for ( int j = 0; j <= 100; j++ )
			{
				bool okflg = true;
				for ( int k = 0; k < N; k++ )
				{
					if ( std::get<2>( v[k] ) <= 0 )
					{
						// 高さが0の点は無視
						continue;
					}

					int tmpH = std::get<2>( v[k] ) + abs_( i - std::get<0>( v[k] ) ) + abs_( j - std::get<1>( v[k] ) );

					for ( int l = 0; l < N; l++ )
					{
						if ( max_( tmpH - abs_( std::get<0>( v[l] ) - i ) - abs_( std::get<1>( v[l] ) - j ), 0 ) != std::get<2>( v[l] ) )
						{
							okflg = false;
							break;
						}
					}

					if ( okflg )
					{
						Cx = i;
						Cy = j;
						Ch = tmpH;
						goto end;
					}
					else
					{
						break;
					}
				}
			}
		}
	}
end:
	std::cout << Cx << " " << Cy << " " << Ch << std::endl;

	return ( 0 );
}

#include <iostream>

int main()
{
	long N;
	std::cin >> N;

	// Nは100以下なので、総当たりでも間に合うのでは…？
	for ( int x = 0;; x++ )
	{
		for ( int y = 0;; y++ )
		{
			long z = 4 *x + 7 * y;
			if ( z == N )
			{
				std::cout << "Yes" << std::endl;
				goto END;
			}
			else if ( z > N )
			{
				// 金額オーバーなので終了
				break;
			}
		}

		if ( 4 * x > N )
		{
			// ここまでxを増やすまでに、条件を満たすyが存在しなかったので、ダメ
			break;
		}
	}

	std::cout << "No" << std::endl;
END:

	return ( 0 );
}

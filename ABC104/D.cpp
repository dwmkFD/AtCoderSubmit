#include <iostream>
#include <string>

int main()
{
	std::string S;
	std::cin >> S;

	long long dp[100001][4] = { 0 };

	for ( int i = S.length(); i >= 0; i-- )
	{
		for ( int j = 3; j >= 0; j-- )
		{
			if ( i >= S.length() )	//	全部見終えた
			{
				if ( j >= 3 )
				{
					// 最後までチェックが終わったので、正常終了
					dp[i][j] = 1;
				}
				else
				{
					// ABCの順になっている部分文字列が見つからず
					dp[i][j] = 0;
				}
			}
			else
			{
				// ABCを探している最中
				// ?が見つかれば3通り、そうでなければ1通りあり、
				// ?またはABCのj番目の文字が見つかった場合は1通り増える
				dp[i][j] = dp[i + 1][j] * ( S.at( i ) == '?' ? 3ll : 1ll );

				if ( ( j < 3 ) && ( ( S.at( i ) == '?' ) || ( S.at( i ) == "ABC"[j] ) ) )
				{
					dp[i][j] += dp[i + 1][j + 1];
				}

				dp[i][j] %= 1000000007;
			}
		}
	}

	// 結果出力
	std::cout << dp[0][0] << std::endl;

	return ( 0 );
}

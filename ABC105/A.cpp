#include <iostream>

int main()
{
	long N, K;
	std::cin >> N >> K;
	long ans;

	if ( K != 0 )
	{
		// 何人に何枚配っても、できるだけ均等に配るなら、差分は絶対に1枚になる
		ans = ( ( N % K ) != 0 );
	}
	else
	{
		// 0人に配る（＝配らない）から、0で良いのかな…？
		ans = 0;
	}

	std::cout << ans << std::endl;

	return ( 0 );
}

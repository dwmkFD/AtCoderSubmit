#include <iostream>

int main()
{
	long N, K;
	std::cin >> N >> K;
	long ans;

	if ( K != 0 )
	{
		// ���l�ɉ����z���Ă��A�ł��邾���ϓ��ɔz��Ȃ�A�����͐�΂�1���ɂȂ�
		ans = ( ( N % K ) != 0 );
	}
	else
	{
		// 0�l�ɔz��i���z��Ȃ��j����A0�ŗǂ��̂��ȁc�H
		ans = 0;
	}

	std::cout << ans << std::endl;

	return ( 0 );
}

#include <iostream>
#include <string>

int main()
{
	std::string S;
	long long K;

	std::cin >> S >> K;

	// 1�ȊO�̕����́AN^5000������������
	// -> S�������猩�Ă����āA���߂ďo�Ă���1�ȊO�̕������AK�Ԗڂ̕���
	char ans;
	int i;
	for ( i = 0; i < S.length(); i++ )
	{
		if ( S[i] != '1' )
		{
			ans = S[i];
			break;
		}
	}

	// �������AK��i��菬�����ꍇ��1�ɂȂ�
	if ( K <= i )
	{
		std::cout << "1" << std::endl;
	}
	else
	{
		std::cout << ans << std::endl;
	}

	return ( 0 );
}

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
			if ( i >= S.length() )	//	�S�����I����
			{
				if ( j >= 3 )
				{
					// �Ō�܂Ń`�F�b�N���I������̂ŁA����I��
					dp[i][j] = 1;
				}
				else
				{
					// ABC�̏��ɂȂ��Ă��镔�������񂪌����炸
					dp[i][j] = 0;
				}
			}
			else
			{
				// ABC��T���Ă���Œ�
				// ?���������3�ʂ�A�����łȂ����1�ʂ肠��A
				// ?�܂���ABC��j�Ԗڂ̕��������������ꍇ��1�ʂ葝����
				dp[i][j] = dp[i + 1][j] * ( S.at( i ) == '?' ? 3ll : 1ll );

				if ( ( j < 3 ) && ( ( S.at( i ) == '?' ) || ( S.at( i ) == "ABC"[j] ) ) )
				{
					dp[i][j] += dp[i + 1][j + 1];
				}

				dp[i][j] %= 1000000007;
			}
		}
	}

	// ���ʏo��
	std::cout << dp[0][0] << std::endl;

	return ( 0 );
}

#include <iostream>
#include <vector>

using myPair = std::pair<long long, long long>;

long long myABS( long long x, long long y )
{
	return ( x < y ? y - x : x - y );
}

long long myMIN( long long x, long long y )
{
	return ( x < y ? x : y );
}

long long myMAX( long long x, long long y )
{
	return ( x < y ? y : x );
}

int main()
{
	int N;
	std::cin >> N;

	std::vector<long long> v( N );

	for ( int i = 0; i < N; i++ )
	{
		std::cin >> v[i];
	}

	// �ݐϘa���Ɍv�Z����
	std::vector<long long> sum( N + 1 );
	sum[0] = 0;
	for ( int i = 0; i < N; i++ )
	{
		sum[i + 1] = sum[i] + v[i];
	}

	// ( P, Q, R, S )���Ǘ����� -> ( (P, Q), (R, S) )
	std::vector<std::pair<myPair, myPair> > vP;
	// �܂������iQ��R�𕪂���ʒu�j�����߂�
	// -> �Œ�ł�������2�v�f�A�E����2�v�f�K�v
	for ( int i = 2; i < N - 2; i++ )
	{
		// i�Ԗڂ̗v�f�������̎d�؂�̎���(P, Q)�����߂�
		int left = 0, mid = left + 1, right = i;
		long long result = 0xffffffff;
		std::pair<long long, long long> tmpPairL, tmpPairR;

		while ( mid < right )
		{
			long long tmpP = sum[mid] - sum[left];
			long long tmpQ = sum[right] - sum[mid];
			long long d = myABS( tmpP, tmpQ );

			// ��������ԏ����������œK�Ȏd�؂�ʒu
			if ( d < result )
			{
				result = d;
				tmpPairL.first = tmpP;
				tmpPairL.second = tmpQ;
			}

			mid++;	//	����2�v�f�̒����̎d�؂���E�Ɉړ�����
		}

		// i�Ԗڂ̗v�f�������̎d�؂�̎���(R, S)�����߂�
		left = i, mid = i + 1, right = N;
		result = 0xffffffff;

		while ( mid < right )
		{
			long long tmpR = sum[mid] - sum[left];
			long long tmpS = sum[right] - sum[mid];
			long long d = myABS( tmpR, tmpS );

			// ��������ԏ����������œK�Ȏd�؂�ʒu
			if ( d < result )
			{
				result = d;
				tmpPairR.first = tmpR;
				tmpPairR.second = tmpS;
			}

			mid++;	//	�E��2�v�f�̒����̎d�؂���E�Ɉړ�����
		}

		// �����ƉE���̍œK��mid�̈ʒu�����܂���P/Q/R/S�����߂�ꂽ�̂ŁA
		// vector�ɓ˂�����
		vP.emplace_back( std::make_pair( tmpPairL, tmpPairR ) );
	}

	// �œK��P/Q/R/S�̌����v�Z���I�����̂ŁA�œK�����o�͂���
	long long output = 0xffffffff;
	for ( auto &&it : vP )
	{
		long long tmpP = it.first.first;
		long long tmpQ = it.first.second;
		long long tmpR = it.second.first;
		long long tmpS = it.second.second;

		long long tmpMIN = myMIN( myMIN( tmpP, tmpQ ), myMIN( tmpR, tmpS ) );
		long long tmpMAX = myMAX( myMAX( tmpP, tmpQ ), myMAX( tmpR, tmpS ) );
		long long tmpABS = myABS( tmpMIN, tmpMAX );

		if ( tmpABS < output )
		{
			output = tmpABS;
		}
	}

	std::cout << output << std::endl;

	return ( 0 );
}

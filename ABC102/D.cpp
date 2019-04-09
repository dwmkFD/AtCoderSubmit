#include <iostream>
#include <vector>
#include <tuple>

using myTuple = std::tuple<long long, long long, long long>;

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
	std::vector<myTuple> vT;

	// �܂������iQ��R�𕪂���ʒu�j�����߂�
	// -> �Œ�ł�������2�v�f�A�E����2�v�f�K�v
	int midL, rightL, bestL = 1;
	int leftR, midR, bestR = 3;
	long long result;

	for ( int i = 2; i <= N - 2; i++ )
	{
		// i�Ԗڂ̗v�f�������̎d�؂�̎���(P, Q)�����߂�
		result = 0xfffffffff;
		midL = bestL;
		rightL = i;

		while ( midL < rightL )
		{
			long long tmpP = sum[midL] - sum[0];
			long long tmpQ = sum[rightL] - sum[midL];
			long long d = myABS( tmpQ, tmpP );

			// ��������ԏ����������œK�Ȏd�؂�ʒu
			if ( d <= result )
			{
				// result���X�V
				result = d;

				// �œK�Ȏd�؂�ʒu���X�V����
				bestL = midL;
			}

			midL++;	//	����2�v�f�̒����̎d�؂���E�Ɉړ�����
		}

		// i�Ԗڂ̗v�f�������̎d�؂�̎���(R, S)�����߂�
		leftR = i, midR = bestR;
		result = 0xfffffffff;

		while ( midR < N )
		{
			long long tmpR = sum[midR] - sum[leftR];
			long long tmpS = sum[N] - sum[midR];
			long long d = myABS( tmpS, tmpR );

			// ��������ԏ����������œK�Ȏd�؂�ʒu
			if ( d <= result )
			{
				// result���X�V
				result = d;

				// �œK�Ȏd�؂�ʒu���X�V����
				bestR = midR;
			}

			midR++;	//	�E��2�v�f�̒����̎d�؂���E�Ɉړ�����
		}

		// �����ƉE���̍œK��mid�̈ʒu�����܂���P/Q/R/S�����߂�ꂽ�̂ŁA
		// vector�ɓ˂����ށi���d�؂�ʒu�A�����d�؂�ʒu�A�E�d�؂�ʒu�j
		vT.emplace_back( std::make_tuple( bestL, i, bestR ) );
	}

	// �œK��P/Q/R/S�̌����v�Z���I�����̂ŁA�œK�����o�͂���
	long long output = 0xfffffffff;
	for ( auto &&it : vT )
	{
		long long tmpLeft = std::get<0>( it );
		long long tmpCenter = std::get<1>( it );
		long long tmpRight = std::get<2>( it );

		long long tmpP = sum[tmpLeft];
		long long tmpQ = sum[tmpCenter] - sum[tmpLeft];
		long long tmpR = sum[tmpRight] - sum[tmpCenter];
		long long tmpS = sum[N] - sum[tmpRight];

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

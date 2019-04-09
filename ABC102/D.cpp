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

	// 累積和を先に計算する
	std::vector<long long> sum( N + 1 );
	sum[0] = 0;
	for ( int i = 0; i < N; i++ )
	{
		sum[i + 1] = sum[i] + v[i];
	}

	// ( P, Q, R, S )を管理する -> ( (P, Q), (R, S) )
	std::vector<std::pair<myPair, myPair> > vP;
	// まず中央（QとRを分ける位置）を決める
	// -> 最低でも左側に2要素、右側に2要素必要
	for ( int i = 2; i < N - 2; i++ )
	{
		// i番目の要素が中央の仕切りの時の(P, Q)を求める
		int left = 0, mid = left + 1, right = i;
		long long result = 0xffffffff;
		std::pair<long long, long long> tmpPairL, tmpPairR;

		while ( mid < right )
		{
			long long tmpP = sum[mid] - sum[left];
			long long tmpQ = sum[right] - sum[mid];
			long long d = myABS( tmpP, tmpQ );

			// 差分が一番小さい時が最適な仕切り位置
			if ( d < result )
			{
				result = d;
				tmpPairL.first = tmpP;
				tmpPairL.second = tmpQ;
			}

			mid++;	//	左側2要素の中央の仕切りを右に移動する
		}

		// i番目の要素が中央の仕切りの時の(R, S)を求める
		left = i, mid = i + 1, right = N;
		result = 0xffffffff;

		while ( mid < right )
		{
			long long tmpR = sum[mid] - sum[left];
			long long tmpS = sum[right] - sum[mid];
			long long d = myABS( tmpR, tmpS );

			// 差分が一番小さい時が最適な仕切り位置
			if ( d < result )
			{
				result = d;
				tmpPairR.first = tmpR;
				tmpPairR.second = tmpS;
			}

			mid++;	//	右側2要素の中央の仕切りを右に移動する
		}

		// 左側と右側の最適なmidの位置が決まってP/Q/R/Sが求められたので、
		// vectorに突っ込む
		vP.emplace_back( std::make_pair( tmpPairL, tmpPairR ) );
	}

	// 最適なP/Q/R/Sの候補を計算し終えたので、最適解を出力する
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

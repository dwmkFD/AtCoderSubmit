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

	// 累積和を先に計算する
	std::vector<long long> sum( N + 1 );
	sum[0] = 0;
	for ( int i = 0; i < N; i++ )
	{
		sum[i + 1] = sum[i] + v[i];
	}

	// ( P, Q, R, S )を管理する -> ( (P, Q), (R, S) )
	std::vector<myTuple> vT;

	// まず中央（QとRを分ける位置）を決める
	// -> 最低でも左側に2要素、右側に2要素必要
	int midL, rightL, bestL = 1;
	int leftR, midR, bestR = 3;
	long long result;

	for ( int i = 2; i <= N - 2; i++ )
	{
		// i番目の要素が中央の仕切りの時の(P, Q)を求める
		result = 0xfffffffff;
		midL = bestL;
		rightL = i;

		while ( midL < rightL )
		{
			long long tmpP = sum[midL] - sum[0];
			long long tmpQ = sum[rightL] - sum[midL];
			long long d = myABS( tmpQ, tmpP );

			// 差分が一番小さい時が最適な仕切り位置
			if ( d <= result )
			{
				// resultを更新
				result = d;

				// 最適な仕切り位置を更新する
				bestL = midL;
			}

			midL++;	//	左側2要素の中央の仕切りを右に移動する
		}

		// i番目の要素が中央の仕切りの時の(R, S)を求める
		leftR = i, midR = bestR;
		result = 0xfffffffff;

		while ( midR < N )
		{
			long long tmpR = sum[midR] - sum[leftR];
			long long tmpS = sum[N] - sum[midR];
			long long d = myABS( tmpS, tmpR );

			// 差分が一番小さい時が最適な仕切り位置
			if ( d <= result )
			{
				// resultを更新
				result = d;

				// 最適な仕切り位置を更新する
				bestR = midR;
			}

			midR++;	//	右側2要素の中央の仕切りを右に移動する
		}

		// 左側と右側の最適なmidの位置が決まってP/Q/R/Sが求められたので、
		// vectorに突っ込む（左仕切り位置、中央仕切り位置、右仕切り位置）
		vT.emplace_back( std::make_tuple( bestL, i, bestR ) );
	}

	// 最適なP/Q/R/Sの候補を計算し終えたので、最適解を出力する
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

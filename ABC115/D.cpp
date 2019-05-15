#include <iostream>

using ull = unsigned long long;

ull pow2( ull n )
{
	ull base = 1;
	for ( int i = 0; i < n; i++ )
	{
		base *= 2;
	}

	return ( base );
}

int main()
{
	int N;
	ull X;
	std::cin >> N >> X;

	// レベルNバーガーの下からN層はバンである
	// P
	// BPPPB
	// BBPPPBPBPPPBB
	// BBBPPPBPBPPPBBPBBPPPBPBPPPBBB
	// レベルNバーガーの下から中央のパティまでの層に含まれるパティの数は、
	// 2^N枚である（中央の1枚を含む）
	// レベルNバーガーの層の総数はLn = (2^N+1 - 1)+(2^N+1 - 2) = 2^N+2 - 3枚である

	ull p = pow2( N + 2 ); // Nは最大50なので、ull型で収まる
	ull counter = 0;

	while ( ( X > 0 ) && ( N >= 0 ) )
	{
#ifdef DEBUG_PRINT
		std::cout << "Lv : " << N << std::endl;
		std::cout << "all: " << p - 3 << std::endl;
		std::cout << "X  : " << X << std::endl;
		std::cout << "mid: " << ( p - 3 ) / 2 << std::endl;
#endif

		if ( X < ( p - 3 ) / 2 + 1 )
		{
			// 中央よりも下層までの時
			// 何もしない
		}
		else
		{
			// 中央よりも上層の時
			counter += pow2( N );	//	中央よりも下層に含まれるパティは全部食べる

			// 上層の時は、食べる側にバンが含まれているので取り除かないが、
			// 下層半分を食べ終えているので、Xはその分減らす
			X -= ( p - 3 ) / 2 + 1;
			++X;	//	調整しておく
		}
#ifdef DEBUG_PRINT
		std::cout << "eat: " << counter << std::endl;
#endif

		--N; // レベルを1段下げる
		--X; // レベルアップ時に両端にバンが追加されているので、それを取り除く
		p = pow2( N + 2 ); // 再計算
	}

	std::cout << counter << std::endl;

	return ( 0 );
}

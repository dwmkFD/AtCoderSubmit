#include <iostream>
#include <vector>
#include <map>

int main()
{
	long long N, M;
	std::cin >> N >> M;

	std::vector<long long> A( N );
	for ( long i = 0; i < N; i++ )
	{
		std::cin >> A[i];
	}

	// 累積和を計算する
	std::vector<long long> B( N + 1 );
	B[0] = 0;
	for ( long i = 1; i <= N; i++ )
	{
		B[i] = A[i - 1] + B[i - 1];
	}

	// 各Bi(i>0)をMで割った余りが0 to M-1である個数をカウントする
	// --> 余りが等しければ、Br - Bl は Mの倍数になる
	//  exp) Mx + 1 と My + 1はそれぞれMで割ると余りが1になるため、
	//      (Mx + 1) - (My + 1) = M(x - y) と変形でき、これはMの倍数である
	long long ans = 0;
	std::map<long long, long long> counter;
	for ( long i = 0; i <= N; i++ )
	{
		ans += counter[B[i] % M];
		counter[B[i] % M]++;	//	カウントアップ（次に余りが一致するBiが見つかれば、組み合わせはその分増える）
	}

	std::cout << ans << std::endl;

	return ( 0 );
}

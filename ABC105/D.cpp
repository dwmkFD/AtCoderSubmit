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

	// �ݐϘa���v�Z����
	std::vector<long long> B( N + 1 );
	B[0] = 0;
	for ( long i = 1; i <= N; i++ )
	{
		B[i] = A[i - 1] + B[i - 1];
	}

	// �eBi(i>0)��M�Ŋ������]�肪0 to M-1�ł�������J�E���g����
	// --> �]�肪��������΁ABr - Bl �� M�̔{���ɂȂ�
	//  exp) Mx + 1 �� My + 1�͂��ꂼ��M�Ŋ���Ɨ]�肪1�ɂȂ邽�߁A
	//      (Mx + 1) - (My + 1) = M(x - y) �ƕό`�ł��A�����M�̔{���ł���
	long long ans = 0;
	std::map<long long, long long> counter;
	for ( long i = 0; i <= N; i++ )
	{
		ans += counter[B[i] % M];
		counter[B[i] % M]++;	//	�J�E���g�A�b�v�i���ɗ]�肪��v����Bi��������΁A�g�ݍ��킹�͂��̕�������j
	}

	std::cout << ans << std::endl;

	return ( 0 );
}

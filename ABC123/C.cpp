#include <iostream>
#include <vector>
#include <algorithm>

using MyPair = std::pair<int, long long>;

int main()
{
	long long N, A, B, C, D, E;
	std::cin >> N >> A >> B >> C >> D >> E;

	// �o�ߎ���
	long long totalTime = 0;

	// �{�g���l�b�N�ɂȂ��Ă�ӏ��𒲂ׂ邽�߂ɁA�����\�[�g����
	std::vector<MyPair> v = { {0, A}, {1, B}, {2, C}, {3, D}, {4, E} };
	std::sort( v.begin(), v.end(), []( MyPair a, MyPair b ) {
			return ( a.second  < b.second );
			} );

	// �{�g���l�b�N�ӏ��Ȃ̂ŁA�Œ�K�v�Ȏ��Ԃ�����
	totalTime = N / v[0].second + ( N % v[0].second != 0 );

	// �{�g���l�b�N�̉ӏ��܂ł����鎞�Ԃ𑫂�
	totalTime += v[0].first; // �s�sN�܂ł̈ړ����Ԃ����̂܂ܑ�����OK

	// �{�g���l�b�N�̉ӏ��ȍ~�̎��Ԃ𑫂�
	totalTime += ( 4 - v[0].first );

	std::cout << totalTime << std::endl;

	return ( 0 );
}

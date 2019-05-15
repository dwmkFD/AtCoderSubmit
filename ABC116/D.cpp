#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using ll = long long;
using llp = std::pair<ll, ll>;

int main()
{
	int N, K;
	std::cin >> N >> K;

	std::vector<llp> v( N );
	for ( int i = 0; i < N; i++ )
	{
		ll t, d;
		std::cin >> t >> d;
		v.emplace_back( std::make_pair( t, d ) );
	}

	// ��b�|�C���g�̍~���Ƀ\�[�g
	std::sort( v.begin(), v.end(), []( llp a, llp b ) {
			return ( a.second > b.second );
		} );

	std::map<ll, ll> m;
	ll pt = 0;
	for ( int i = 0; i < K; i++ )
	{
		pt += v[i].second;	//	�傫�����ɂƂ肠�����l�߂�
		m[v[i].first]++;	//	�o�Ă�����ނ��J�E���g���Ă���
	}

	ll ptmax = pt + m.size() * m.size();	//	�b��ō��l
	ll prev = ptmax;	//	�O��̒l
	ll pp = m.size();	//	��ނ�����
	ll big = K;	// ��b�|�C���g�������A���܂��l�߂Ă��Ȃ���ނ̃l�^��T��
	ll sml = K - 1; // ��b�|�C���g���Ⴍ�A���l�߂Ă��܂������̂�T��

	// �ő�K��ޓ������̂ŁA������T��
	for ( int i = 1; pp + i <= K; i++ )
	{
		// ���łɓ���Ă��܂������ŁA�d�����ē��ꂽ���̂�T���i����Ă���ނ�����Ȃ����́j
		while ( ( sml >= 0 ) && ( m[v[sml].first] <= 1 ) ) --sml;

		if ( sml < 0 )
		{
			// ������̂��Ȃɂ��Ȃ��̂ŁA�I��
			break;
		}

		ll ppp = pp + i;
		ll tmp = prev - v[sml].second + 2 * ppp - 1; // 1��ޑ�����̂ōČv�Z
		m[v[sml].first]--; // ���������
		--sml;	//	����ɑO��T��

		// �܂�����Ă��Ȃ����̂�T��
		while ( ( big < N ) && ( m[v[big].first] > 0 ) ) ++big;

		if ( big >= N )
		{
			// ����ȏ�̂��̂��Ȃ��̂ŏI��
			break;
		}

		tmp += v[big].second;	// �Čv�Z
		m[v[big].first]++;		//	�V�K�ǉ�
		++big;

		if ( tmp > ptmax )
		{
			ptmax = tmp;
		}
		prev = tmp;
	}

	std::cout << ptmax << std::endl;

	return ( 0 );
}

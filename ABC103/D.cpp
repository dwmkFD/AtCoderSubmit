#include <iostream>
#include <vector>
#include <algorithm>

using myPair = std::pair<long, long>;

int main()
{
	long N, M;
	std::cin >> N >> M;

	std::vector<myPair> v;

	for ( int i = 0; i < M; i++ )
	{
		long tmpA, tmpB;
		std::cin >> tmpA >> tmpB;
		v.emplace_back( std::make_pair( tmpA, tmpB ) );
	}

	// v���ABi�̒l�ŏ����\�[�g����
	std::sort( v.begin(), v.end(), []( myPair a, myPair b ) {
			return( a.second < b.second );
		} );

	/*
	 * ����ŗv�]M�́A��Ai����s�������Ȃ��Ő���Bi���킩��悤�ɕ���ł���i�͂��j
	 * ���̎��A|Ai - Bi|��1�ɂȂ��Ă���ӏ��̋�i�͕K���ؒf����K�v������
	 * ����ƁAAi����ACi�iCi > Bi�j�ɂ͐�΂ɒH�蒅���Ȃ��Ȃ�̂ŁA
	 * ����Bi�����ł���A����Bi�ȏ�̓��ƂȂ��Ă���Mi�͑S�Ċ������Ă���̂ŁA���O���ėǂ�
	 * ������A�S�v�f�����O�����܂ŌJ��Ԃ��΁A�v�]M���S�Ċ�������
	 *
	 * |Ai - Bi|��2�ȏ�ł����Ă��AAi = Bi-1�Ƃ��āAi�Ԗڂ̋���ؒf����΁A
	 * ���̗v�]Mi�͊�����ꂽ���ƂɂȂ�̂ŁA�ؒf�������̔ԍ�b�ɂ���
	 * �EMi(Ai, Bi)���������Ă��Ȃ���΁ABi-1��Bi�̊Ԃɂ���b�Ԗڂ̋���ؒf
	 * �EMi(Ai, Bj)���������Ă���΁i��i+1<=b<j�̂ǂ����̋����ؒf����Ă���j�������Ȃ�
	 * Bi�͏����\�[�g����Ă���̂ŁA�ȍ~�A���O��b�݂̂��o���Ă����AAi<b�݂̂𒲂ׂ�Ηǂ�
	 * b���X�V�����ꍇ�A�������O�̓�Ai�ɂ́A���łɁi����ȑO�̗v�]M�ɂ���āj���B�ł��Ȃ��Ȃ��Ă���͂��ł���
	 */
	long counter = 0;			//	����ؒf�����{��
	long b = 0;					//	���O�ɐؒf�������̔ԍ�

	for ( auto &&it : v )
	{
		if ( it.first > b )
		{
			// �����Ȃ����Ă���
			b = it.second - 1;		//	����ؒf����
			counter++;				//	���̖{�����J�E���g����
		}
	}

	std::cout << counter << std::endl;

	return ( 0 );
}

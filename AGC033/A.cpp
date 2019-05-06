#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

int main()
{
  ios_base::sync_with_stdio( false );

  int H, W;
  cin >> H >> W;

  vector<bitset<1001> > v;
  for ( int i = 0; i < H; i++ )
  {
    bitset<1001> tmp;
    for ( int j = 0; j < W; j++ )
    {
      char tmpc;
      cin >> tmpc;
      tmp[j] = tmpc == '#' ? 1 : 0;
    }
  v.emplace_back( tmp );
  }

   long counter = 0;
   bool loopflg;
  vector<bitset<1001> > vtmp( H );
  const bitset<1001> mask( (1 << W ) - 1);
  do {
     loopflg = false;
    /* �O��̍s���������� */
    if ( H >= 2 )
    {
     vtmp[0] = v[0] | v[1]; // 1�s��
    for ( int i = 1; i < H - 1; i++ )
    {
       vtmp[i] = v[i - 1] | v[i] | v[i + 1];
    }
    vtmp[H - 1] = v[H - 1] | v[H - 2]; // �ŏI�s
    }

   /* ���E�̗���������� */
   for ( int i = 0; i < H; i++ )
   {
       // ���E��1�r�b�g�V�t�g����OR����OK
       vtmp[i] = vtmp[i] | v[i] << 1;
       vtmp[i] = vtmp[i] | v[i] >> 1;

       // �]�v��ON�ɂȂ��Ă��܂�����ʃr�b�g�͐؂�̂Ă�
       vtmp[i] &= mask;

       if  ( vtmp[i].count() < W )
       {
           loopflg = true; // �S�r�b�g��ON�łȂ���΁A�܂��ϊ����Ȃ��ƃ_��
       }
   }

     counter++; // �ϊ������̂ŁA�J�E���g
     v = vtmp; // v���X�V����
  } while ( loopflg );

   cout << counter << endl;

  return ( 0 );
}

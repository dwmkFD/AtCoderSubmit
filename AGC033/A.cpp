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
    /* 前後の行を書き換え */
    if ( H >= 2 )
    {
     vtmp[0] = v[0] | v[1]; // 1行目
    for ( int i = 1; i < H - 1; i++ )
    {
       vtmp[i] = v[i - 1] | v[i] | v[i + 1];
    }
    vtmp[H - 1] = v[H - 1] | v[H - 2]; // 最終行
    }

   /* 左右の列を書き換え */
   for ( int i = 0; i < H; i++ )
   {
       // 左右に1ビットシフトしてOR取ればOK
       vtmp[i] = vtmp[i] | v[i] << 1;
       vtmp[i] = vtmp[i] | v[i] >> 1;

       // 余計にONになってしまった上位ビットは切り捨てる
       vtmp[i] &= mask;

       if  ( vtmp[i].count() < W )
       {
           loopflg = true; // 全ビットがONでなければ、まだ変換しないとダメ
       }
   }

     counter++; // 変換したので、カウント
     v = vtmp; // vを更新する
  } while ( loopflg );

   cout << counter << endl;

  return ( 0 );
}

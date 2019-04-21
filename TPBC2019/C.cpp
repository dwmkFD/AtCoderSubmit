#include <iostream>
#include <string>
#include <vector>

int main()
{
	int N;
	std::string S;
	std::cin >> N >> S;

	std::vector<int> v( N );
	bool color = false;	//	白から始まるとしておく
	int pos = 0;

	for ( int i = 0; i < S.length(); i++ )
	{
		if ( S[i] == '#' )
		{
			if ( color == false )	//	白なら色を変える
			{
				// 色を黒にしてインデックスを進める
				color = true;
				++pos;
			}
			v[pos]++;
		}
		else
		{
			if ( color == true )	//	黒なら色を変える
			{
				// 色を白にしてインデックスを進める
				color = false;
				++pos;
			}
			v[pos]++;
		}
	}

	int TransNum = 0;
	int TransWhite = 0;

	for ( int i = 2; i <= pos; i += 2 )	//	v[2n]は必ず白の個数（n>=0）であり、v[0]は変換不要なので無視して良い
	{
		if ( ( v[i] < v[i - 1] ) && ( v[i] < v[i - 1] - TransWhite * 2 ) )
		{
			// 白の左側の黒の個数が自身より多いなら、自分を変換するべき
			// 今までに変換した白を加味しても多いならOK（ダメなら、そもそも最初に変換したのは間違った色だった）
			TransNum += v[i];
			v[i + 1] += ( v[i] + v[i - 1] );	//	自分を黒にしたので、次の白にとっての左側の黒の個数が変わる
			TransWhite += v[i];	//	白の変換量を保存する
		}
		else
		{
			// そうでないなら、左側の黒の方を変換するべき
			TransNum += v[i - 1];

			// 変換対象が黒なら、前回変換した範囲を対象に含んでいる可能性がある
			TransNum -= TransWhite * 2;	//	余分に加算したので、引く
			TransWhite = 0;	//	左側は全部白になったはずなので、リセット
		}
	}

	std::cout << TransNum << std::endl;

	return ( 0 );
}

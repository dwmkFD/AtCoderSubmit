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
	int memoIdx = -1;

	for ( int i = 2; i <= pos; i += 2 )	//	v[2n]は必ず白の個数（n>=0）であり、v[0]は変換不要なので無視して良い
	{
		if ( v[i] < v[i - 1] )
		{
			// 白の左側の黒の個数が自身より多いなら、自分を変換するべき
			TransNum += v[i];
			v[i + 1] += ( v[i] + v[i - 1] );	//	自分を黒にしたので、次の白にとっての左側の黒の個数が変わる
			memoIdx = i;
		}
		else
		{
			// そうでないなら、左側の黒の方を変換するべき
			TransNum += v[i - 1];
			if ( memoIdx == i - 2 )
			{
				// 前回変換した範囲を対象に選んだ場合
				TransNum -= ( v[i - 2] * 2 );	//	余分に加算したので、引く
			}
		}
	}

	std::cout << TransNum << std::endl;

	return ( 0 );
}

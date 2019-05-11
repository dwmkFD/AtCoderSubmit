#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	int N;
	cin >> N;

	unsigned long long counter = 0;
	unsigned long long Acnt = 0, Bcnt = 0, ABcnt = 0;
	vector<string> v( N );
	for ( int i = 0; i < N; i++ )
	{
		cin >> v[i];

		bool Afind = false;
		string::size_type index, beforeIndex = 0;
		while ( ( index = v[i].find( "AB", beforeIndex ) ) != string::npos )
		{
			counter++;
			beforeIndex = index + 1;
		}

		if ( v[i].back() == 'A' )
		{
			Afind = true;
			++Acnt;
		}
		if ( v[i][0] == 'B' )
		{
			++Bcnt;
			if ( Afind )
			{
				ABcnt++;
			}
		}
	}

	// oŒ»•p“x‚ª­‚È‚¢•û‚É‡‚í‚¹‚é
	if ( Acnt > Bcnt )
	{
		counter += Bcnt;
	}
	else if ( Bcnt > Acnt )
	{
		counter += Acnt;
	}
	else
	{
		if ( Acnt == ABcnt )
		{
			if ( Acnt == 0 )
			{
				// Œó•â‚È‚µ
			}
			else
			{
				counter += ( ABcnt - 1 );
			}
		}
		else
		{
			counter += Acnt;
		}
	}


	cout << counter << endl;

	return ( 0 );
}

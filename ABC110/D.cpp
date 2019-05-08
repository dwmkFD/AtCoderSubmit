#include <iostream>
#include <vector>

constexpr unsigned long MOD = 1000000007;

// 素因数分解する
auto factorize( unsigned long long x )
{
	std::vector<std::pair<unsigned long, unsigned long> > result;

	for ( int i = 2; i * i <= x; i++ )
	{
		if ( x % i != 0 )
		{
			continue;
		}

		int counter = 0;
		while ( x % i == 0 )
		{
			// i^pを約数に持つので、割り切れる回数をカウント
			counter++;
			x /= i;
		}
		result.emplace_back( std::make_pair( i, counter ) );
	}

	if ( x != 1 )
	{
		// どのiでも割り切れなかったので、x自身を追加（xが素数のとき）
		result.emplace_back( std::make_pair( x, 1 ) );
	}

	return ( result );
}

// nCrを計算する
#define FACTMAX ( 200000 )
unsigned long long fact[FACTMAX];
unsigned long long finv[FACTMAX];
unsigned long long inv[FACTMAX];

void combinationInit()
{
	fact[0] = fact[1] = 1;
	for ( unsigned long long i = 2; i < FACTMAX; i++ )
	{
		fact[i] = ( fact[i - 1] * i ) % MOD;
	}
	inv[1] = 1;
	for ( unsigned long long i = 2; i < FACTMAX; i++ )
	{
		inv[i] = ( MOD - MOD / i ) * inv[MOD % i] % MOD;
	}
	finv[0] = finv[1] = 1;
	for ( int i = 2; i < FACTMAX; i++ )
	{
		finv[i] = finv[i - 1] * inv[i] % MOD;
	}
}

unsigned long long combination( unsigned long long n, unsigned long long r )
{
	return ( ( fact[n] * ( finv[r] * finv[n - r] % MOD ) % MOD ) );
}

int main()
{
	unsigned long N, M;
	std::cin >> N >> M;

	// M = a1^b1 * a2^b2 * a3^b3 ... であり、
	// a1もまた a^c1 * a^c2 * a^c3 ... なので、
	// c1 + c2 + c3 ... = b1, 以下同様にbnまで求めるのと同じ

	// Mを素因数分解する
	auto f = factorize( M );

	// f.size()が数列bの要素数nであり、f[i].secondがbiの値である
	combinationInit();
	unsigned long long result = 1;
	for ( auto &&it : f )
	{
		result *= combination( it.second + N - 1, it.second );
		result %= MOD;
	}

	std::cout << result << std::endl;

	return ( 0 );
}

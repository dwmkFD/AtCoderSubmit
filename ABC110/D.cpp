#include <iostream>
#include <vector>

constexpr unsigned long MOD = 1000000007;

// �f������������
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
			// i^p��񐔂Ɏ��̂ŁA����؂��񐔂��J�E���g
			counter++;
			x /= i;
		}
		result.emplace_back( std::make_pair( i, counter ) );
	}

	if ( x != 1 )
	{
		// �ǂ�i�ł�����؂�Ȃ������̂ŁAx���g��ǉ��ix���f���̂Ƃ��j
		result.emplace_back( std::make_pair( x, 1 ) );
	}

	return ( result );
}

// nCr���v�Z����
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

	// M = a1^b1 * a2^b2 * a3^b3 ... �ł���A
	// a1���܂� a^c1 * a^c2 * a^c3 ... �Ȃ̂ŁA
	// c1 + c2 + c3 ... = b1, �ȉ����l��bn�܂ŋ��߂�̂Ɠ���

	// M��f������������
	auto f = factorize( M );

	// f.size()������b�̗v�f��n�ł���Af[i].second��bi�̒l�ł���
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

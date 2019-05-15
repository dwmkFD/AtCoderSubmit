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

	// Šî‘bƒ|ƒCƒ“ƒg‚Ì~‡‚Éƒ\[ƒg
	std::sort( v.begin(), v.end(), []( llp a, llp b ) {
			return ( a.second > b.second );
		} );

	std::map<ll, ll> m;
	ll pt = 0;
	for ( int i = 0; i < K; i++ )
	{
		pt += v[i].second;	//	‘å‚«‚¢‡‚É‚Æ‚è‚ ‚¦‚¸‹l‚ß‚é
		m[v[i].first]++;	//	o‚Ä‚«‚½Ží—Þ‚ðƒJƒEƒ“ƒg‚µ‚Ä‚¨‚­
	}

	ll ptmax = pt + m.size() * m.size();	//	Žb’èÅ‚’l
	ll prev = ptmax;	//	‘O‰ñ‚Ì’l
	ll pp = m.size();	//	Ží—Þ‚ðƒƒ‚
	ll big = K;	// Šî‘bƒ|ƒCƒ“ƒg‚ª‚‚­A‚©‚Â‚Ü‚¾‹l‚ß‚Ä‚¢‚È‚¢Ží—Þ‚Ìƒlƒ^‚ð’T‚·
	ll sml = K - 1; // Šî‘bƒ|ƒCƒ“ƒg‚ª’á‚­A‚©‚Â‹l‚ß‚Ä‚µ‚Ü‚Á‚½‚à‚Ì‚ð’T‚·

	// Å‘åKŽí—Þ“ü‚ê‚ç‚ê‚é‚Ì‚ÅA‘±‚«‚ð’T‚·
	for ( int i = 1; pp + i <= K; i++ )
	{
		// ‚·‚Å‚É“ü‚ê‚Ä‚µ‚Ü‚Á‚½’†‚ÅAd•¡‚µ‚Ä“ü‚ê‚½‚à‚Ì‚ð’T‚·ií‚Á‚Ä‚àŽí—Þ‚ªŒ¸‚ç‚È‚¢‚à‚Ìj
		while ( ( sml >= 0 ) && ( m[v[sml].first] <= 1 ) ) --sml;

		if ( sml < 0 )
		{
			// í‚ê‚é‚à‚Ì‚ª‚È‚É‚à‚È‚¢‚Ì‚ÅAI—¹
			break;
		}

		ll ppp = pp + i;
		ll tmp = prev - v[sml].second + 2 * ppp - 1; // 1Ží—Þ‘‚¦‚é‚Ì‚ÅÄŒvŽZ
		m[v[sml].first]--; // ŒÂ”‚ªˆê‚ÂŒ¸‚é
		--sml;	//	‚³‚ç‚É‘O‚ð’T‚·

		// ‚Ü‚¾“ü‚ê‚Ä‚¢‚È‚¢‚à‚Ì‚ð’T‚·
		while ( ( big < N ) && ( m[v[big].first] > 0 ) ) ++big;

		if ( big >= N )
		{
			// ‚±‚êˆÈã‚Ì‚à‚Ì‚ª‚È‚¢‚Ì‚ÅI—¹
			break;
		}

		tmp += v[big].second;	// ÄŒvŽZ
		m[v[big].first]++;		//	V‹K’Ç‰Á
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

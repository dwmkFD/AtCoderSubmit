template<typename T = long long> struct mex {
public:
	mex() {
		constexpr long long inf = 1e18;
		s.emplace( -inf, -inf );
		s.emplace( inf, inf );
	}

	bool contains( T x ) const {
		auto it = prev( s.lower_bound( make_pair( x + 1, x + 1 ) ) );
		auto [low, upp] = *it;
		return ( low <= x && x <= upp );
	}

	bool insert( T x ) {
		auto nxtit = s.lower_bound( make_pair( x + 1, x + 1 ) );
		auto it = prev( nxtit );
		auto [low, upp] = *it;
		auto [nxtlow, nxtupp] = *nxtit;
		if ( low <= x && x <= upp ) return ( false );
		if ( upp == x - 1 ) {
			if ( nxtlow == x + 1 ) {
				s.erase( it );
				s.erase( nxtit );
				s.emplace( low, nxtupp );
			} else {
				s.erase( it );
				s.emplace( low, x );
			}
		} else {
			if ( nxtlow == x + 1 ) {
				s.erase( nxtit );
				s.emplace( x, nxtupp );
			} else {
				s.emplace( x, x );
			}
		}

		return ( true );
	}

	T get( T x = 0 ) const {
		auto [low, upp] = *prev( s.lower_bound( make_pair( x + 1, x + 1 ) ) );
		if ( low <= x && x <= upp )
			return ( upp + 1 );
		else
			return ( x );
	}

private:
	set<pair<T, T>> s;
};

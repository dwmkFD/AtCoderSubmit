template<typename Monoid, typename T = ll> struct SegTree {
	using Func = function<Monoid( Monoid, Monoid )>;
	const Func func;
	const Monoid UNITY;
	T SIZE_R;
	vector<Monoid> data;

	SegTree( T n, const Func f, const Monoid &unity ) :
		func( f ), UNITY( unity ) {
			init( n );
		}

	void init( T n ) {
		SIZE_R = 1;
		while ( SIZE_R < n ) SIZE_R *= 2;
		data.assign( SIZE_R * 2, UNITY );
	}

	void set( T idx, const Monoid &val ) { data[idx + SIZE_R] = val; }
	void build() {
		for ( T k = SIZE_R - 1; k > 0; --k )
			data[k] = func( data[k * 2], data[k * 2 + 1] );
	}

	void update( T idx, const Monoid &val ) {
		T k = idx + SIZE_R;
		data[k] = val;
		while ( k >>= 1 ) data[k] = func( data[k * 2], data[k * 2 + 1] );
	}

	Monoid get( T a, T b ) {
		Monoid vleft = UNITY, vright = UNITY;
		for ( T left = a + SIZE_R, right = b + SIZE_R;
			  left < right;
			  left >>= 1, right >>= 1 ) {
			if ( left & 1 ) vleft = func( vleft, data[left++] );
			if ( right & 1 ) vright = func( data[--right], vright );
		}

		return ( func( vleft, vright ) );
	}

	inline Monoid operator[]( ll idx ) { return ( data[idx + SIZE_R] ); }
};

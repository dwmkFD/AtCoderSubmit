template<typename T = ll> struct UnionFind {
	vector<T> par;

	UnionFind( T n ) : par( n, -1 ) {}

	void init( T n ) { par.assign( n, -1 ); }
	T find( T x ) {
		if ( par[x] < 0 ) return ( x );
		else return ( par[x] = find( par[x] ) );
	}
	bool isSame( T x, T y ) {
		return ( find( x ) == find( y ) );
	}
	bool unite( T x, T y ) {
		x = find( x ); y = find( y );
		if ( x == y ) return ( false );
		if ( par[x] > par[y] ) swap( x, y );
		par[x] += par[y];
		par[y] = x;
		return ( true );
	}
	T size( T x ) { return ( -par[find( x )] ); }
};

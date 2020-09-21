template<typename T> struct LCA {
	vector<T> par[64];
	vector<T> depth;
	T len;

	void dfs( T v, T p, T d, const vector<vector<T>> &e ) {
		depth[v] = d;
		par[0][v] = p;
		arep( it, e[v] )
		{
			if ( it != p ) dfs( it, v, d + 1, e );
		}
	}

	void init( T n, const vector<vector<T>> &e, T r = 0 ) {
		len = 1;
		while ( ( 1LL << len ) < n ) ++len;
		rep( i, len ) par[i].resize( n );
		depth.assign( n, - 1 );

		dfs( r, -1, 0, e );

		rep( k, len - 1 )
		{
			rep( v, n )
			{
				if ( depth[v] == -1 ) continue;
				if ( par[k][v] < 0 ) par[k + 1][v] = -1;
				par[k + 1][v] = par[k][par[k][v]];
			}
		}
	}

	T getlca( T u, T v ) {
		if ( depth[u] > depth[v] ) swap( u, v );
		rep( k, len ) if ( ( ( depth[v] - depth[u] ) >> k ) & 1 ) v = par[k][v];

		if ( u == v ) return ( u );
		rrep( k, len )
		{
			if ( par[k][u] != par[k][v] )
			{
				u = par[k][u];
				v = par[k][v];
			}
		}
		return ( par[0][u] );
	}

	T getdist( T u, T v ) {
		T l = getlca( u, v );
		return( depth[u] + depth[v] - depth[l] * 2 );
	}
};

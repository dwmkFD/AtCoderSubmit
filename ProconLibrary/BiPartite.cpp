template<typename T> struct BiPartiteGraph {
	using P = pair<T, T>;
	BiPartiteGraph( T n ) {
		g.assign( n, vector<T>( n, 0 ) );
		init( n );
	}
	BiPartiteGraph( const vector<vector<T>> &val, T n ) {
		g = val;
		init( n );
	};

	void init( T n ) {
		size = n;
		dir.assign( n, 0 );
	}

	bool dfs( T v, T vdir, P &num ) {
		bool res = true;
		dir[v] = vdir;
		if ( vdir == 1 ) ++num.F;
		else if ( vdir == -1 ) ++num.S;
		arep( it, g[v] )
		{
			if ( dir[it] == 0 )
			{
				if ( dfs( it, -vdir, num ) == false )
					res = false;
			}
			else if ( dir[it] != -vdir ) res = false;
		}

		return ( res );
	}

	bool check() {
		bool res = true;
		rep( v, size )
		{
			if ( dir[v] != 0 ) continue;
			P num = { 0, 0 };
			if ( dfs( v, 1, num ) == false )
				res = false;
			nums.pb( num );
		}

		return ( res );
	}

	T size;
	vector<vector<T>> g;
	vector<T> dir;
	vector<P> nums;
};

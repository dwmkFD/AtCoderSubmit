template<typename T = ll> struct CumulativeSum2D {
	CumulativeSum2D( T h, T w ) :
		data( h, vector<T>( w, 0 ) ),
		sum( h + 1, vector<T>( w + 1, 0 ) ),
		H( h ), W( w ) {}

	void set( ll i, ll j, T val ) {
		data[i][j] = val;
	}

	void add( ll i, ll j, T val ) {
		data[i][j] += val;
	}

	void build() {
		rep( i, H )
			rep( j, W )
				sum[i + 1][j + 1] = sum[i][j + 1] + sum[i + 1][j] - sum[i][j] + data[i][j];
	}

	T get( ll xs, ll xe, ll ys, ll ye ) {
		return ( sum[xe][ye] - sum[xs][ye] - sum[xe][ys] + sum[xs][ys] );
	}

	vector<vector<T>> data, sum;
	T H, W;
};

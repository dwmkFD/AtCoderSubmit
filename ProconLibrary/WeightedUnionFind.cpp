template<typename T, typename Abel> struct WeightedUnionFind {
    vector<T> par;
    vector<T> rank;
    vector<Abel> diff_weight;

    WeightedUnionFind( T n = 1, Abel SUM_UNITY = 0 ) {
        init( n, SUM_UNITY );
    }

    void init( T n = 1, Abel SUM_UNITY = 0 ) {
        par.resize( n ); rank.resize( n ); diff_weight.resize( n );
        for ( T i = 0; i < n; ++i ) par[i] = i, rank[i] = 0, diff_weight[i] = SUM_UNITY;
    }

    int find( T x ) {
        if ( par[x] == x ) return ( x );
        else {
            T r = find( par[x] );
            diff_weight[x] += diff_weight[par[x]];
            return ( par[x] = r );
        }
    }

    Abel weight( T x ) {
        find( x );
        return ( diff_weight[x] );
    }

    bool isSame( T x, T y ) {
        return ( find( x ) == find( y ) );
    }

    bool unite( T x, T y, Abel w ) {
        w += weight( x ); w -= weight( y );
        x = find( x ); y = find( y );
        if ( x == y ) return ( false );
        if ( rank[x] < rank[y] ) swap( x, y ), w = -w;
        if ( rank[x] == rank[y] ) ++rank[x];
        par[y] = x;
        diff_weight[y] = w;
        return ( true );
    }

    Abel diff( T x, T y ) {
        return ( weight( y ) - weight( x ) );
    }
};

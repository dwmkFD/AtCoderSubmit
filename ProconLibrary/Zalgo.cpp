template<typename T = int> vector<T> Zalgo( const string &S ) {
	T N = (T)S.size();
	vector<T> res(N);
	res[0] = N;
	T i = 1, j = 0;
	while ( i < N ) {
		while (i+j < N && S[j] == S[i+j]) ++j;
		res[i] = j;
		if ( j == 0 ) { ++i; continue; }
		int k = 1;
		while ( i + k < N && k + res[k] < j ) res[i + k] = res[k], ++k;
		i += k, j -= k;
	}
	return ( res );
}

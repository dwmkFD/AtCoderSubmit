template<typename T = ll> T solveLIS( const vector<T> &v ) {
	vector<T> dp( v.size(), numeric_limits<T>::max() );
	rep( i, v.size() ) {
		*lower_bound( ALL( dp ), v[i] ) = v[i];
	}
	return ( distance( dp.begin(), lower_bound( ALL( dp ), numeric_limits<T>::max() ) ) );
}

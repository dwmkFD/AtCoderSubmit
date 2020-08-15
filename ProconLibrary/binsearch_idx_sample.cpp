
template<typename T> auto binsearch_idx( vector<T> &v, T val ) {
	ll left = -1, right = v.size();
	while ( abs( right - left ) > 1 )
	{
		ll mid = ( left + right ) / 2;
		if ( val > v[mid] )
			left = mid;
		else
			right = mid;
	}

	return ( mp( v[right] == val, right ) );
}

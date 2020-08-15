void replace( string &s, string t, string r ) {
	string::size_type p = 0;
	while ( ( p = s.find( t, p ) ) != string::npos ) {
		s.replace( p, t.length(), r );
		p += r.length();
	}
}

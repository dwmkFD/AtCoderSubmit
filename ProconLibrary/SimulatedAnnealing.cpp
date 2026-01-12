constexpr double TIME_LIMIT = 1.8;
constexpr ll INF = RAND_MAX;

struct State {
};

void init( State &state ) {
}

void modify( Stage &state ) {
}

template<typename T> T calc_score( State &state ) {
}

void solve_sa() {
	State state;
	init( state );
	double start_temp = 50.0, end_temp = 10.0;
	auto start_time = chrono::steady_clock::now();

	while ( true ) {
		auto now_time = chrono::steady_clock::now();
		double elapse = chrono::duration<double>( now_time - start_time ).count();
		if ( elapse > TIME_LIMIT ) break;

		State new_state = state;
		modify( new_state );
		ll new_score = calc_score<ll>( new_state );
		ll pre_score = calc_score<ll>( state );

		double temp = start_temp + ( end_temp - start_temp ) * elapse / TIME_LIMIT;
		double prob = exp( ( new_score - pre_score ) / temp );

		if ( prob > rand() / (double)INF ) {
			state = new_state;
		}
	}
}



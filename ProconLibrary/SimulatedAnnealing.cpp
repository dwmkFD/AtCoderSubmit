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
	double start_temp, end_temp;
	double start_time;

	while ( true ) {
		double now_time;
		if ( now_time - start_time > TIME_LIMIT ) break;

		State new_state = state;
		modify( new_state );
		ll new_score = calc_score<ll>( new_state );
		ll pre_score = calc_score<ll>( state );

		double temp = start_temp + ( end_temp - start_temp ) * ( now_time - start_time ) / TIME_LIMIT;
		double prob = exp( ( new_score - pre_score ) / temp );

		if ( prob > rand() / (double)INF ) {
			state = new_state;
		}
	}
}



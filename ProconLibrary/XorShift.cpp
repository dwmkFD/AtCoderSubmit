class XorShift128 {
private:
  uint32_t x, y, z, w;

public:
  using result_type = uint32_t;

  XorShift128( uint64_t seed ) {
    x = 123456789;
    y = 756542406;
    z = 857392532;
    w = seed == 0 ? 615263943 : static_cast<uint32_t>( seed );
  }

  XorShift128() {
    uint64_t seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    x = 123456789;
    y = 756542406;
    z = 857392532;
    w = static_cast<uint32_t>( seed );
  }

  static constexpr result_type min(){ return 0; }
  static constexpr result_type max(){ return UINT32_MAX; }

  result_type operator()(){ return next(); }

  uint32_t next() {
    uint32_t t = x ^ ( x << 11 );
    x = y;
    y = z;
    z = w;
    w = ( w ^ ( w >> 19 ) ) ^ ( t ^ ( t >> 8 ) );
    return w;
  }

  double next_double() {
    return static_cast<double>( next() ) / ( static_cast<double>( UINT32_MAX ) + 1.0 );
  }

  int next_int(int min, int max) {
    return min + ( next() % ( max - min + 1 ) );
  }
};

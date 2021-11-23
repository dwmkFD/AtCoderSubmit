template<typename T = uint64_t> constexpr T NOTFOUND = 0xffffffffffffffffLLU;

template<typename T = uint64_t> struct SuccinctBitVector {
public:
    explicit SuccinctBitVector(const T n) : size(n) {
        const T s = (n + blockBitNum - 1) / blockBitNum + 1;   // ceil(n, blockSize)
        this->B.assign(s, 0);
        this->L.assign(n / LEVEL_L + 1, 0);
        this->S.assign(n / LEVEL_S + 1, 0);
    }

    // B[pos] = bit
    void setBit(const T bit, const T pos){
        const T blockPos = pos / blockBitNum;
        const T offset = pos % blockBitNum;
        if (bit == 1) { B.at(blockPos) |= (1LLU << offset); }
        else          { B.at(blockPos) &= (~(1LLU << offset)); }
    }

    // B[pos]
    T access(const T pos) {
        const T blockPos = pos / blockBitNum;
        const T offset   = pos % blockBitNum;
        return ((B.at(blockPos) >> offset) & 1);
    }

    void build() {
        T num = 0;
        for (T i = 0; i <= size; i++){
            if (i % LEVEL_L == 0) {
                L.at(i / LEVEL_L) = num;
            }
            if (i % LEVEL_S == 0) {
                S.at(i / LEVEL_S) = num - L.at(i / LEVEL_L);
            }
            if (i != size and i % blockBitNum == 0) {
                num += popcnt(this->B.at(i / blockBitNum));
            }
        }
        this-> numOne = num;
    }

    // B[0, pos)のbitの数
    T rank(const T bit, const T pos) {
        if (bit) {
            return L[pos / LEVEL_L] + S[pos / LEVEL_S] + popCount(B[pos / blockBitNum] & ((1 << (pos % blockBitNum)) - 1));
        }
        else {
            return pos - rank(1, pos);
        }
    }

    // rank番目のbitの位置 + 1(rankは1-origin)
    T select(const T bit, const T rank) {
        if (bit == 0 and rank > this->size - this-> numOne) { return NOTFOUND<T>; }
        if (bit == 1 and rank > this-> numOne)              { return NOTFOUND<T>; }

        // 大ブロックL内を検索
        T large_idx = 0;
        {
            T left = 0;
            T right = L.size();
            while (right - left > 1) {
                T mid = (left + right) / 2;
                T r = L.at(mid);
                r = (bit) ? r : mid * LEVEL_L - L.at(mid);

                if (r < rank) {
                    left = mid;
                    large_idx = mid;
                } else {
                    right = mid;
                }
            }
        }

        // 小ブロックS内を検索
        T small_idx = (large_idx * LEVEL_L) / LEVEL_S;
        {
            T left = (large_idx * LEVEL_L) / LEVEL_S;
            T right = std::min(((large_idx  + 1) * LEVEL_L) / LEVEL_S, (T)S.size());
            while (right - left > 1) {
                T mid = (left + right) / 2;
                T r = L.at(large_idx) + S.at(mid);
                r = (bit) ? r :mid * LEVEL_S - r;

                if (r < rank) {
                    left = mid;
                    small_idx = mid;
                } else {
                    right = mid;
                }
            }
        }

        // Bをブロック単位で順番に探索
        T rank_pos = 0;
        {
            const T begin_block_idx = (small_idx * LEVEL_S) / blockBitNum;
            T total_bit = L.at(large_idx) + S.at(small_idx);
            if (bit == 0) {
                total_bit = small_idx * LEVEL_S - total_bit;
            }
            for (T i = 0;; ++i) {
                T b = popCount(B.at(begin_block_idx + i));
                if (bit == 0) {
                    b = blockBitNum - b;
                }
                if (total_bit + b >= rank) {
                    T block = (bit) ? B.at(begin_block_idx + i) : ~B.at(begin_block_idx + i);
                    rank_pos = (begin_block_idx + i) * blockBitNum + selectInBlock(block, rank - total_bit);
                    break;
                }
                total_bit += b;
            }
        }

        return rank_pos + 1;
    }

    T getNumOne() const {
        return numOne;
    }

    void debug() {
        std::cout << "LEVEL_L(" << L.size() << ")" << std::endl;
        for (T i = 0 ; i < L.size(); ++i) {
            std::cout << L.at(i) << ", ";
        }
        std::cout << std::endl;
        std::cout << "LEVEL_S(" << S.size() << ")" << std::endl;
        for (T i = 0 ; i < S.size(); ++i) {
            std::cout << S.at(i) << ", ";
        }
        std::cout << std::endl;
    }

private:
	// popcnt は __builtin_popcountll を使用する
	T selectInBlock( T x, T rank ) {
		T x1 = x - ( ( x & 0xAAAAAAAAAAAAAAAALLU ) >> 1 );
		T x2 = ( x1 & 0x3333333333333333LLU ) + ( ( x1 >> 2 ) & 0x3333333333333333LLU );
		T x3 = ( x2 + ( x2 >> 4 ) ) & 0x0F0F0F0F0F0F0F0FLLU;

		T pos = 0;
		for ( ;; pos += 8 ) {
			T rank_next = ( x3 >> pos ) & 0xFFLLU;
			if ( rank <= rank_next ) break;
			rank -= rank_next;
		}

		T v2 = ( x2 >> pos ) & 0xFLLU;
		if ( rank > v2 ) {
			rank -= v2;
			pos += 4;
		}

		T v1 = ( x1 >> pos ) & 0x3LLU;
		if ( rank > v1 ) {
			rank -= v1;
			pos += 2;
		}

		T v0  = ( x >> pos ) & 0x1LLU;
		if ( v0 < rank ) {
			rank -= v0;
			pos += 1;
		}

		return pos;
	}

	const T size;	// ビットベクトルのサイズ
	static const T blockBitNum = 16;
	static const T LEVEL_L = 512;
	static const T LEVEL_S = 16;

	vector<T> L;	// 大ブロック
	vector<T> S; // 小ブロック
	vector<T> B; // ビットベクトル

	T numOne = 0;	// 1bitの数
};

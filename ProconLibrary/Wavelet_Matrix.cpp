// SuccinctBitVector���K�v

template<typename T = uint64_t> struct WaveletMatrix {
public:
    WaveletMatrix (const std::vector<T> &array) {
        size = array.size();
        maximum_element =  *max_element(array.begin(), array.end()) + 1;
        bit_size = get_num_of_bit(maximum_element);
        if (bit_size == 0) {
            bit_size = 1;
        }

        for (T i = 0; i < bit_size; ++i) {
            SuccinctBitVector<T> sv(size);
            bit_arrays.push_back(sv);
        }
        this->begin_one.resize(bit_size);
        this->cumulative_sum.resize(bit_size + 1, std::vector<T>(size + 1, 0));

        for (T j = 0; j < array.size(); ++j) {
            this->cumulative_sum.at(0).at(j + 1) = this->cumulative_sum.at(0).at(j) + array[j];
        }

        std::vector<T> v(array);
        for (T i = 0; i < bit_size; ++i) {

            std::vector<T> temp;
            // 0��temp�ɂ���Ă�
            for (T j = 0; j < v.size(); ++j) {
                T c = v.at(j);
                T bit = (c >> (bit_size - i - 1)) & 1;  //�@�ォ��i�Ԗڂ�bit
                if (bit == 0) {
                    temp.push_back(c);
                    bit_arrays.at(i).setBit(0, j);
                }
            }

            this->begin_one.at(i) = temp.size();

            // 1��temp�ɂ���Ă�
            for (T j = 0; j < v.size(); ++j) {
                T c = v.at(j);
                T bit = (c >> (bit_size - i - 1)) & 1;  //�@�ォ��i�Ԗڂ�bit
                if (bit == 1) {
                    temp.push_back(c);
                    bit_arrays.at(i).setBit(1, j);
                }
            }

            for (T j = 0; j < temp.size(); ++j) {
                this->cumulative_sum.at(i + 1).at(j + 1) = this->cumulative_sum.at(i + 1).at(j) + temp.at(j);
            }

            bit_arrays.at(i).build();
            v = temp;
        }

        // �\�[�g���ꂽ�z����ł̊e�����̈ʒu���擾
        for (int i = v.size() - 1; i >= 0; --i) {
            this->begin_alphabet[v.at(i)] = i;
        }
    }

    // v[pos]
    T access(T pos) {
        if (pos >= this->size) { return NOTFOUND<T>; }

        T c = 0;
        for (T i = 0; i < bit_arrays.size(); ++i) {
            T bit = bit_arrays.at(i).access(pos);   // ���Ƃ̐��l��i�Ԗڂ�bit
            c = (c <<= 1) | bit;
            pos = bit_arrays.at(i).rank(bit, pos);
            if (bit) {
                pos += this->begin_one.at(i);
            }
        }
        return c;
    }

    // i�Ԗڂ�c�̈ʒu + 1��Ԃ��Brank��1-origin
    T select(T c, T rank) {
        if (c >= maximum_element) {
            return NOTFOUND<T>;
        }
        if (this->begin_alphabet.find(c) == this->begin_alphabet.end()) {
            return NOTFOUND<T>;
        }

        T index = this->begin_alphabet.at(c) + rank;
        for (T i = 0; i < bit_arrays.size(); ++i){
            T bit = ((c >> i) & 1);      // ������i�Ԗڂ�bit
            if (bit == 1) {
                index -= this->begin_one.at(bit_size - i - 1);
            }
            index = this->bit_arrays.at(bit_size - i - 1).select(bit, index);
        }
        return index;
    }

    // v[begin_pos, end_pos)�ōő�l��index��Ԃ�
    T maxRange(T begin_pos, T end_pos) {
        return quantileRange(begin_pos, end_pos, end_pos - begin_pos - 1);
    }

    // v[begin_pos, end_pos)�ōŏ��l��index��Ԃ�
    T minRange(T begin_pos, T end_pos) {
        return quantileRange(begin_pos, end_pos, 0);
    }

    // v[begin_pos, end_pos)��k�Ԗڂɏ��������l��index��Ԃ�(k��0-origin)
    // �܂菬�������ɕ��ׂ�k�Ԗڂ̒l
    T quantileRange(T begin_pos, T end_pos, T k) {
        if ((end_pos > size || begin_pos >= end_pos) || (k >= end_pos - begin_pos)) {
            return NOTFOUND<T>;
        }

        T val = 0;
        for (T i = 0; i < bit_size; ++i) {
            const T num_of_zero_begin = bit_arrays.at(i).rank(0, begin_pos);
            const T num_of_zero_end = bit_arrays.at(i).rank(0, end_pos);
            const T num_of_zero = num_of_zero_end - num_of_zero_begin;     // begin����end�܂łɂ���0�̐�
            const T bit = (k < num_of_zero) ? 0 : 1;                       // k�Ԗڂ̒l�̏ォ��i�Ԗڂ�bit��0��1��

            if (bit) {
                k -= num_of_zero;
                begin_pos = this->begin_one.at(i) + begin_pos - num_of_zero_begin;
                end_pos = this->begin_one.at(i) + end_pos - num_of_zero_end;
            }
            else {
                begin_pos = num_of_zero_begin;
                end_pos = num_of_zero_begin + num_of_zero;
            }

            val = ((val << 1) | bit);
        }

        T left = 0;
        for (T i = 0; i < bit_size; ++i) {
            const T bit = (val >> (bit_size - i - 1)) & 1;  // �ォ��i�Ԗڂ�bit
            left = bit_arrays.at(i).rank(bit, left);               // c��i�Ԗڂ�bit�Ɠ������l�̐�
            if (bit) {
                left += this->begin_one.at(i);
            }
        }

        const T rank = begin_pos + k - left + 1;
        return select(val, rank) - 1;
    }

    // v[0, pos)��c�̐�
    T rank(T c, T pos) {
        assert(pos < size);
        if (c >= maximum_element) {
            return 0;
        }
        if (this->begin_alphabet.find(c) == this->begin_alphabet.end()) {
            return 0;
        }

        for (T i = 0; i < bit_size; ++i) {
            T bit = (c >> (bit_size - i - 1)) & 1;  // �ォ��i�Ԗڂ�bit
            pos = bit_arrays.at(i).rank(bit, pos);         // c��i�Ԗڂ�bit�Ɠ������l�̐�
            if (bit) {
                pos += this->begin_one.at(i);
            }
        }

        T begin_pos = this->begin_alphabet.at(c);
        return pos - begin_pos;
    }

    // v[begin_pos, end_pos)��[min, max)�ɓ���l�̌�
    T rangeFreq(T begin_pos, T end_pos, T min_c, T max_c) {
        if ((end_pos > size || begin_pos >= end_pos) || (min_c >= max_c) || min_c >= maximum_element) {
            return 0;
        }

        const auto maxi_t = rankAll(max_c, begin_pos, end_pos);
        const auto mini_t = rankAll(min_c, begin_pos, end_pos);
        return std::get<1>(maxi_t) - std::get<1>(mini_t);
    }

    // v[0, pos)��c��菬���������̐�
    T rankLessThan(T c, T begin, T end) {
        auto t = rankAll(c, begin, end);
        return std::get<1>(t);
    }

    // v[0, pos)��c���傫�������̐�
    T rankMoreThan(T c, T begin, T end) {
        auto t = rankAll(c, begin, end);
        return std::get<2>(t);
    }

    // v[begin, end)��(c�Ɠ����l�̐��Ac��菬�����l�̐��Ac���傫���l�̐�)�����߂�
    std::tuple<T, T, T> rankAll(const T c, T begin, T end) {
        assert(end <= size);
        const T num = end - begin;

        if (begin >= end) {
            return std::make_tuple(0, 0, 0);
        }
        if (c >= maximum_element || end == 0) {
            return std::make_tuple(0, num, 0);
        }

        T rank_less_than = 0, rank_more_than = 0;
        for (size_t i = 0; i < bit_size && begin < end; ++i) {
            const T bit = (c >> (bit_size - i - 1)) & 1;

            const T rank0_begin = this->bit_arrays.at(i).rank(0, begin);
            const T rank0_end = this->bit_arrays.at(i).rank(0, end);
            const T rank1_begin = begin - rank0_begin;
            const T rank1_end = end - rank0_end;

            if (bit) {
                rank_less_than += (rank0_end - rank0_begin);    // i�Ԗڂ�bit��0�̂��̂͏��O�����
                begin = this->begin_one.at(i) + rank1_begin;
                end = this->begin_one.at(i) + rank1_end;
            } else {
                rank_more_than += (rank1_end - rank1_begin);    // i�Ԗڂ�bit��1�̂��̂͏��O�����
                begin = rank0_begin;
                end = rank0_end;
            }
        }

        const T rank = num - rank_less_than - rank_more_than;
        return std::make_tuple(rank, rank_less_than, rank_more_than);
    }

    // T[s, e)�ŏo���񐔂���������k��(�l�C�p�x)��Ԃ�
    // �p�x�������ꍇ�͒l�����������̂��D�悳���
    std::vector<std::pair<T, T>> topk(T s, T e, T k) {
        assert(s < e);
        std::vector<std::pair<T, T>> result;

        // (�p�x�C�[���C�l)�̏��Ń\�[�g
        auto c = [](const std::tuple<T, T, T, T, T> &l, const std::tuple<T, T, T, T, T> &r) {
            // width
            if (std::get<0>(l) != std::get<0>(r)) {
                return std::get<0>(l) < std::get<0>(r);
            }
            // depth
            if (std::get<3>(l) != std::get<3>(r)) {
                return std::get<3>(l) > std::get<3>(r);
            }
            // value
            if (std::get<4>(l) != std::get<4>(r)) {
                return std::get<4>(l) > std::get<4>(r);
            }
            return true;
        };

        std::priority_queue<std::tuple<T, T, T, T, T>, std::vector<std::tuple<T, T, T, T, T>>, decltype(c)> que(c);  // width, left, right, depth, value
        que.push(std::make_tuple(e - s, s, e, 0, 0));

        while (not que.empty()) {
            auto element = que.top(); que.pop();
            T width, left, right, depth, value;
            std::tie(width, left, right, depth, value) = element;

            if (depth >= this->bit_size) {
                result.emplace_back(std::make_pair(value, right - left));
                if (result.size() >= k) {
                    break;
                }
                continue;
            }

            // 0
            const T left0 = this->bit_arrays.at(depth).rank(0, left);
            const T right0 = this->bit_arrays.at(depth).rank(0, right);
            if (left0 < right0) {
                que.push(std::make_tuple(right0 - left0, left0, right0, depth + 1, value));
            }

            // 1
            const T left1 = this->begin_one.at(depth) + this->bit_arrays.at(depth).rank(1, left);
            const T right1 = this->begin_one.at(depth) + this->bit_arrays.at(depth).rank(1, right);
            if (left1 < right1) {
                que.push(std::make_tuple(right1 - left1, left1, right1, depth + 1, value | (1 << (bit_size - depth - 1))));
            }
        }

        return result;
    };

    // T[begin_pos, end_pos)��x <= c < y�𖞂���c�̘a��Ԃ�
    T rangeSum(const T begin, const T end, const T x, const T y) {
        return rangeSum(begin, end, 0, 0, x, y);
    }

    // T[begin_pos, end_pos)��x <= c < y�𖞂����ő��c��Ԃ�
    T prevValue(const T begin_pos, const T end_pos, const T x, T y) {
        assert(end_pos <= size);
        const T num = end_pos - begin_pos;

        if (x >= y or y == 0) {
            return NOTFOUND<T>;
        }
        if (y > maximum_element) {
            y = maximum_element;
        }

        if (begin_pos >= end_pos) {
            return NOTFOUND<T>;
        }
        if (x >= maximum_element || end_pos == 0) {
            return NOTFOUND<T>;
        }

        y--; // x <= c <= y�ɂ���

        std::stack<std::tuple<T, T, T, T, bool>> s;   // (begin, end, depth, c, tight)
        s.emplace(std::make_tuple(begin_pos, end_pos, 0, 0, true));

        while (not s.empty()) {
            T b, e, depth, c;
            bool tight;
            std::tie(b, e, depth, c, tight) = s.top(); s.pop();

            if (depth == bit_size) {
                if (c >= x) {
                    return c;
                }
                continue;
            }

            const T bit = (y >> (bit_size - depth - 1)) & 1;

            const T rank0_begin = this->bit_arrays.at(depth).rank(0, b);
            const T rank0_end = this->bit_arrays.at(depth).rank(0, e);
            const T rank1_begin = b - rank0_begin;
            const T rank1_end = e - rank0_end;

            // d�Ԗڂ�bit��0�̂��̂��g��
            const T b0 = rank0_begin;
            const T e0 = rank0_end;
            if (b0 != e0) { // �͈͂��Ԃ�ĂȂ�
                const T c0 = ((c << 1) | 0);
                s.emplace(std::make_tuple(b0, e0, depth + 1, c0, tight and bit == 0));
            }

            // d�Ԗڂ�bit��1�̂��̂��g��
            const T b1 = this->begin_one.at(depth) + rank1_begin;
            const T e1 = this->begin_one.at(depth) + rank1_end;
            if (b1 != e1) {
                if (not tight or bit == 1) {
                    const auto c1 = ((c << 1) | 1);
                    s.emplace(std::make_tuple(b1, e1, depth + 1, c1, tight));
                }
            }
        }

        return NOTFOUND<T>;
    }

    // T[begin_pos, end_pos)��x <= c < y�𖞂����ŏ���c��Ԃ�
    T nextValue(const T begin_pos, const T end_pos, const T x, const T y) {
        assert(end_pos <= size);
        const T num = end_pos - begin_pos;

        if (x >= y or y == 0) {
            return NOTFOUND<T>;
        }

        if (begin_pos >= end_pos) {
            return NOTFOUND<T>;
        }
        if (x >= maximum_element || end_pos == 0) {
            return NOTFOUND<T>;
        }

        std::stack<std::tuple<T, T, T, T, bool>> s;   // (begin, end, depth, c, tight)
        s.emplace(std::make_tuple(begin_pos, end_pos, 0, 0, true));

        while (not s.empty()) {
            T b, e, depth, c;
            bool tight;
            std::tie(b, e, depth, c, tight) = s.top(); s.pop();

            if (depth == bit_size) {
                if (c < y) {
                    return c;
                }
                continue;
            }

            const T bit = (x >> (bit_size - depth - 1)) & 1;

            const T rank0_begin = this->bit_arrays.at(depth).rank(0, b);
            const T rank0_end = this->bit_arrays.at(depth).rank(0, e);
            const T rank1_begin = b - rank0_begin;
            const T rank1_end = e - rank0_end;

            // d�Ԗڂ�bit��1�̂��̂��g��
            const T b1 = this->begin_one.at(depth) + rank1_begin;
            const T e1 = this->begin_one.at(depth) + rank1_end;
            if (b1 != e1) {
                const auto c1 = ((c << 1) | 1);
                s.emplace(std::make_tuple(b1, e1, depth + 1, c1, tight and bit == 1));
            }

            // d�Ԗڂ�bit��0�̂��̂��g��
            const T b0 = rank0_begin;
            const T e0 = rank0_end;
            if (b0 != e0) {
                if (not tight or bit == 0) {
                    const T c0 = ((c << 1) | 0);
                    s.emplace(std::make_tuple(b0, e0, depth + 1, c0, tight));
                }
            }
        }

        return NOTFOUND<T>;
    }

    // T[s1, e1)��T[s2, e2)�ɋ��ʂ��ďo������v�f�����߂�
    std::vector<std::tuple<T, T, T>> intersect(T _s1, T _e1, T _s2, T _e2) {
//        assert(_s1 < _e1);
//        assert(_s2 < _e2);

        std::vector<std::tuple<T, T, T>> intersection;

        std::queue<std::tuple<T, T, T, T, T, T>> que; // s1, e1, s2, e2, depth, value
        que.push(std::make_tuple(_s1, _e1, _s2, _e2, 0, 0));
        while (not que.empty()) {
            auto e = que.front(); que.pop();
            T s1, e1, s2, e2, depth, value;
            std::tie(s1, e1, s2, e2, depth, value) = e;

            if (depth >= this->bit_size) {
                intersection.emplace_back(std::make_tuple(value, e1 - s1, e2 - s2));
                continue;
            }

            // 0
            T s1_0 = this->bit_arrays.at(depth).rank(0, s1);
            T e1_0 = this->bit_arrays.at(depth).rank(0, e1);
            T s2_0 = this->bit_arrays.at(depth).rank(0, s2);
            T e2_0 = this->bit_arrays.at(depth).rank(0, e2);

            if (s1_0 != e1_0 and s2_0 != e2_0) {
                que.push(std::make_tuple(s1_0, e1_0, s2_0, e2_0, depth + 1, value));
            }

            // 1
            T s1_1 = this->begin_one.at(depth) + this->bit_arrays.at(depth).rank(1, s1);
            T e1_1 = this->begin_one.at(depth) + this->bit_arrays.at(depth).rank(1, e1);
            T s2_1 = this->begin_one.at(depth) + this->bit_arrays.at(depth).rank(1, s2);
            T e2_1 = this->begin_one.at(depth) + this->bit_arrays.at(depth).rank(1, e2);

            if (s1_1 != e1_1 and s2_1 != e2_1) {
                que.push(std::make_tuple(s1_1, e1_1, s2_1, e2_1, depth + 1, value | (1 << bit_size - depth - 1)));
            }
        }

        return intersection;
    }

private:
    T get_num_of_bit(T x) {
        if (x == 0) return 0;
        x--;
        T bit_num = 0;
        while (x >> bit_num) {
            ++bit_num;
        }
        return bit_num;
    }

    T rangeSum(const T begin, const T end, const T depth, const T c, const T x, const T y) {
        if (begin == end) {
            return 0;
        }

        if (depth == bit_size) {
            if (x <= c and c < y) {
                return c * (end - begin);   // �l * �p�x
            }
            return 0;
        }

        const T next_c = ((T)1 << (bit_size - depth - 1)) | c;                   // �ォ��depth�Ԗڂ�bit�𗧂Ă�
        const T all_one_c = (((T)1 << (bit_size - depth - 1)) - 1) | next_c;     // depth�ȍ~��bit�����Ă�(����ȍ~�S��1��I�񂾂Ƃ��̒l)
        if(all_one_c < x or y <= c) {
            return 0;
        }

        // [begin, pos)�̂��ׂĂ̗v�f��[x, y)
        if (x <= c and all_one_c < y) {
            return this->cumulative_sum.at(depth).at(end) - this->cumulative_sum.at(depth).at(begin);
        }

        const T rank0_begin = this->bit_arrays.at(depth).rank(0, begin);
        const T rank0_end = this->bit_arrays.at(depth).rank(0, end);
        const T rank1_begin = begin - rank0_begin;
        const T rank1_end = end - rank0_end;

        return rangeSum(rank0_begin, rank0_end, depth + 1, c, x, y) +
               rangeSum(this->begin_one.at(depth) + rank1_begin, this->begin_one[depth] + rank1_end, depth + 1, next_c, x, y);
    }

    vector<SuccinctBitVector<T>> bit_arrays;
    vector<T> begin_one;                    // �ebit�ɒ��ڂ����Ƃ���1�̊J�n�ʒu
    map<T, T> begin_alphabet;        // �Ō�̃\�[�g���ꂽ�z��Ŋe�����̊J�n�ʒu
    vector<std::vector<T>> cumulative_sum;  // �ebit�ɒ��ڂ����Ƃ��̗ݐϘa

    T size;                                 // �^����ꂽ�z��̃T�C�Y
    T maximum_element;                      // ������
    T bit_size;                             // ������\���̂ɕK�v��bit��
};

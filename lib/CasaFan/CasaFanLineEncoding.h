#pragma once
#include <etl/bitset.h>

class CasaFanLineEncoding {
public:
    /**
     * Encode bits to line coding
     * @param bits
     * @param num_bits
     * @return
     */
    template<const size_t BITS>
    static etl::bitset<64> encode(etl::bitset<BITS> input_bits)
    {
        static_assert(BITS*3+1 <= 64, "No");

        etl::bitset<64> result;
        for (int bit = 0; bit < BITS; ++bit) {
            result[bit*3] = true;
            result[bit*3+1] = false;
            result[bit*3+2] = input_bits.test(bit);
        }

        result[63] = true;

        return result;
    }
};


#pragma once

#include <cstdint>

inline uint64_t* intr_divmod(uint64_t A, uint64_t B){
    uint64_t* r = new uint64_t[2];

    r[0] = A / B;
    r[1] = A % B;

    return r;
}
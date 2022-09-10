#pragma once

#include <cstdint>

// this is laid out the way that it is so that eventually intr_ functions can be abstracted to assembly level functions them compiled from there

namespace _internal{

#include "add.h"
#include "inv.h"
#include "mul.h"
#include "div.h"

#include "stack/stack.h"

inline uint64_t noStack_invert(uint64_t A){
    return intr_inv(A);
}

inline uint64_t noStack_twosCompliment(uint64_t A){
    return( intr_add( intr_inv(A), 1 ));
}

inline uint64_t noStack_multiply(uint64_t A, uint64_t B){
    return intr_mul(A, B);
}

inline uint64_t noStack_divide(uint64_t A, uint64_t B){
    return intr_divmod(A, B)[0];
}

inline uint64_t noStack_modulo(uint64_t A, uint64_t B){
    return intr_divmod(A, B)[1];
}

inline uint64_t noStack_add(uint64_t A, uint64_t B){
    return intr_add(A, B);
}

inline uint64_t noStack_subtract(uint64_t A, uint64_t B){
    return intr_add(A, noStack_twosCompliment(B));
}

}; // namespace _internal
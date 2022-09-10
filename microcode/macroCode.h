#pragma once

#include <cstdint>

// this is laid out the way that it is so that eventually intr_ functions can be abstracted to assembly level functions them compiled from there

namespace _internal{

#include "microcode/add.h"
#include "microcode/inv.h"
#include "microcode/mul.h"
#include "microcode/div.h"

#include "stack/stack.h"

uint64_t noStack_invert(uint64_t A){
    return intr_inv(A);
}

uint64_t noStack_twosCompliment(uint64_t A){
    return( intr_add( intr_inv(A), 1 ));
}

uint64_t noStack_multiply(uint64_t A, uint64_t B){
    return intr_mul(A, B);
}

uint64_t noStack_divide(uint64_t A, uint64_t B){
    return intr_divmod(A, B)[0];
}

uint64_t noStack_modulo(uint64_t A, uint64_t B){
    return intr_divmod(A, B)[1];
}

uint64_t noStack_add(uint64_t A, uint64_t B){
    return intr_add(A, B);
}

uint64_t noStack_subtract(uint64_t A, uint64_t B){
    return intr_add(A, noStack_twosCompliment(B));
}

}; // namespace _internal
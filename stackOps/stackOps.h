#pragma once

#include "stack/stack.h"

#include "microcode/macrocode.h"

#include "stackOps/arithmetic.h"

namespace SOp{

// ones compliment
void inv(Stack& s){
    s.push(_internal::noStack_invert(s.pop()));
}

// make a GCPointer
// this is just a uint64_t[] but the first element is the length of the array including itself so that length information is self-contained
// so for example making the stack state {1, 2, 5, 3, 4} into a pointer would make uint64_t[]{4, 3, 5, 2, 1} and push the pointer to the stack
// the reason for this is that then in one array we can make sure that array bounds are tracked and enforced
void makePtr(Stack& s){
    uint64_t size = s.pop();

    uint64_t* ptr = new uint64_t[size + 1];

    ptr[0] = size;

    for(uint64_t i = 1; i <= size; ++i){
        ptr[i] = s.pop();
    }

    s.push(reinterpret_cast<uint64_t>(ptr));
}

void derefPtr(Stack& s){

}

}; // namespace SOp
#pragma once

#include "stack/stack.h"

#include "microcode/macrocode.h"

#include "stackOps/arithmetic.h"

namespace SOp{

// ones compliment
void inv(Stack& s){
    s.push(_internal::noStack_invert(s.pop()));
}

// take the value of the top element of the stack, and add another value on the top of the stack with the same value, without removing the old one
void dup(Stack& s){
    // ok thats not true, we do remove the top element here
    uint64_t a = s.pop();

    // but it is immediately added on again so effectively unchanged
    s.push(a);
    s.push(a);
}

// make a GCPointer
// this is just a uint64_t[] but the first element is the length of the array including itself so that length information is self-contained
// so for example making the stack state {1, 2, 5, 3, 4} into a pointer would make uint64_t[]{4, 3, 5, 2, 1} and push the pointer to the stack,
// creating a stack state such as {0x00000FF849BA9164} 
// the reason for this is that then in one array we can contain both the length and the data
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
    uint64_t* ptr = reinterpret_cast<uint64_t*>(s.pop());

    for(uint64_t i = 0; i < ptr[0]; ++i){
        // "ptr[0] - i" ensures that values are put back onto the stack such that the stack order is preserved
        s.push(ptr[ptr[0] - i]);
    }

    delete ptr;
}

}; // namespace SOp
#pragma once

#include "microcode/macroCode.h"

namespace SOp{

void add(Stack& s){
    s.push(_internal::noStack_add(s.pop(),
                                  s.pop()
    ));
}

void sub(Stack& s){
    s.push(_internal::noStack_subtract(s.pop(),
                                       s.pop()
    ));
}

void mul(Stack& s){
    s.push(_internal::noStack_multiply(s.pop(),
                                       s.pop()
    ));
}

void div(Stack& s){
    s.push(_internal::noStack_divide(s.pop(),
                                     s.pop()
    ));
}

void mod(Stack& s){
    s.push(_internal::noStack_modulo(s.pop(),
                                     s.pop()
    ));
}

}; // namespace SOp
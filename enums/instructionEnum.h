#pragma once

#include <cstdint>

class Instructions{

// in bytecode representation these all need to be shifted left by two bits
enum AllInstrs{
    push,
    pop,
    add,
    sub,
    mul,
    div,
    mod,
    equals,
    invert,

    ifBegin,
    ifElse,
    ifEnd,

    loopBegin,
    loopEnd,

    fnCall,
    fnReturn,

    ptrMake,
    ptrDeref,
};

uint64_t format(uint64_t instruction){
    return instruction << 2;
}

};
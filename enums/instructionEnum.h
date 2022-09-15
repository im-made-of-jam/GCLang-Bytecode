#pragma once

#include <cstdint>

//! DO NOT CHANGE THIS AS OTHER FILES IN OTHER PROJECTS MAY RELY UPON THIS ORDERING

class Enum{
public:
// in bytecode representation these all need to be shifted left by two bits
enum AllInstrs{
        add = 0,
    sub = 1,
    mul = 2,
    div = 3,
    mod = 4,

    invert = 5,
    equals = 6,

    push = 7,
    dup = 8,
    drop = 9,
    swap = 10,

    move = 11, //

    size = 12, //
    active = 13, //

    ifBegin = 14,
    ifEnd = 15,

    loopBegin = 16,
    loopEnd = 17,
    loopBreak = 18,

    fnCall = 19,
    fnReturn = 20,

    external = 21,
    builtin = 22,

    ptrMake = 23,
    ptrDeref = 24,

    _dbg_cout_size = 32769,
};

enum AllStacks{
    Main,
    Second,
    Third,
    Fourth
};

inline uint64_t formatInstruction(uint64_t instruction){
    return instruction << 2;
}

inline uint64_t combineInstruction(uint64_t formattedInstruction, uint64_t stack){
    return formattedInstruction | stack;
}

};
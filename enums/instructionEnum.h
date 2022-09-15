#pragma once

#include <cstdint>

//! DO NOT CHANGE THIS AS OTHER FILES IN OTHER PROJECTS MAY RELY UPON THIS ORDERING

class Enum{
public:
// in bytecode representation these all need to be shifted left by two bits
enum AllInstrs{
    add = 0,/////
    sub,/////
    mul,/////
    div,/////
    mod,/////

    invert,/////
    equals,/////

    push,/////
    dup,/////
    drop,/////
    swap,/////

    move,//

    size,//
    active,//

    ifBegin,/////
    ifEnd,/////

    loopBegin,/////
    loopEnd,/////
    loopBreak,/////

    fnCall,/////
    fnReturn,/////

    external,/////
    builtin,/////

    ptrMake,/////
    ptrDeref,/////

    _dbg_cout_size,/////
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
#pragma once

#include <cstdint>

class Enum{
public:
// in bytecode representation these all need to be shifted left by two bits
enum AllInstrs{
    add,/////
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
#pragma once

#include <cstdint>

class Enum{

// in bytecode representation these all need to be shifted left by two bits
enum AllInstrs{
    push,
    pop,
    add,
    sub,
    mul,
    div,
    mod,

    invert,
    equals,

    dup,
    drop,
    swap,

    move,//

    ifBegin,//
    ifElse,//
    ifEnd,//

    loopBegin,//
    loopEnd,//
    loopBreak,//

    fnCall,//
    fnReturn,//

    external,//

    ptrMake,
    ptrDeref,
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
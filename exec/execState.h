#pragma once

#include "stack/stack.h"

struct ExecState{
    uint8_t activeStack = 0;

    Stack MainStack;
    Stack Second;
    Stack Third;
    Stack Fourth;

    Stack callStack;
    Stack loopStack;

    Stack allStacks[4] = {MainStack, Second, Third, Fourth};

    // If the top of the stack is truthy, execution will fall through.
    // If the top of the stack is falsey, execution will jump to the address within additional.
    // Whatever happens, additional2 is pushed to this stack so that upon completing execution of an if block, it can jump to the end of the if statement with the address fo the ifEnd.
    Stack ifStack;

    ExecState() : MainStack(),  // default to max size
                  Second(),
                  Third(),
                  Fourth(),

                  // these are a lot smaller than the memory stack because it is not expected
                  // for a program to reach some 250000 calls or loops or if-statements deep
                  callStack(4),
                  loopStack(4),
                  ifStack(4)
    {};

    // instruction pointer
    uint64_t IP = 0;
};
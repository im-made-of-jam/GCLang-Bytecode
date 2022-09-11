#pragma once

#include <cstdint>

#include "stack/stack.h"
#include "stackOps/stackOps.h"

#include "enums/instructionEnum.h"

#include "builtins.h"
#include "execState.h"

namespace Exec{

bool single(uint64_t instruction, ExecState& state, uint64_t additional = 0, uint64_t additional2 = 0){
    Stack& stack = *state.allStacks[state.activeStack];

    switch(instruction){
        case Enum::push:{
            stack.push(additional);
            break;
        }
        case Enum::dup:{
            SOp::dup(stack);
            break;
        }
        case Enum::drop:{
            SOp::drop(stack);
            break;
        }
        case Enum::swap:{
            SOp::swap(stack);
            break;
        }

        case Enum::add:{
            SOp::add(stack);
            break;
        }
        case Enum::sub:{
            SOp::sub(stack);
            break;
        }
        case Enum::mul:{
            SOp::mul(stack);
            break;
        }
        case Enum::div:{
            SOp::div(stack);
            break;
        }
        case Enum::mod:{
            SOp::mod(stack);
            break;
        }

        case Enum::invert:{
            SOp::inv(stack);
            break;
        }
        case Enum::equals:{
            SOp::equ(stack);
            break;
        }

        case Enum::ifBegin:{
            if(!stack.pop()){
                state.IP = additional;
            }
            // let execution fall through otherwise
            state.ifStack.push(additional2);

            break;
        }
        case Enum::ifEnd:{
            state.IP = state.ifStack.pop();
            break;
        }

        case Enum::loopBegin:{
            state.loopStack.push(state.IP);
            state.loopStack.push(additional);
            break;
        }
        case Enum::loopEnd:{
            [[maybe_unused]]
            uint64_t unused = state.loopStack.pop();

            state.IP = state.loopStack.pop();
            break;
        }
        case Enum::loopBreak:{
            state.IP = state.loopStack.pop();

            [[maybe_unused]]
            uint64_t unused = state.loopStack.pop();
            break;
        }

        case Enum::fnCall:{
            state.callStack.push(state.IP);
            state.IP = additional;
            break;
        }
        case Enum::fnReturn:{
            state.IP = state.callStack.pop();
            break;
        }

        case Enum::ptrMake:{
            SOp::makePtr(stack);
            break;
        }
        case Enum::ptrDeref:{
            SOp::derefPtr(stack);
            break;
        }

        case Enum::size:{
            SOp::size(stack);
            break;
        }
        case Enum::active:{
            SOp::active(state);
            break;
        }

        default:{
            return false;
        }
    }

    return true;
}

}; // namespace Exec
#pragma once

#include <cstdint>
#include <vector>

#include "stack/stack.h"
#include "stackOps/stackOps.h"

#include "enums/instructionEnum.h"

#include "builtins.h"
#include "execState.h"

namespace Exec{

bool single(uint32_t instruction, ExecState& state, uint64_t* additional, uint64_t additSize){
    Stack& stack = *state.allStacks[state.activeStack];

    switch(instruction){
        case Enum::push:{
            stack.push(additional[0]);
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
                state.IP = additional[0];
            }
            // let execution fall through otherwise
            state.ifStack.push(additional[1]);

            break;
        }
        case Enum::ifEnd:{
            state.IP = state.ifStack.pop();
            break;
        }

        case Enum::loopBegin:{
            state.loopStack.push(state.IP);
            state.loopStack.push(additional[0]);
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
            state.IP = additional[0];
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

        case Enum::builtin:{
            return(Exec::Builtins::execFromIndex(additional[0], state));
            break;
        }

        case Enum::_dbg_cout_size:{
            for(uint64_t i = 0; i < additSize; ++i){
                std::cout << additional[i] << "\n";
            }

            std::cout << std::endl;

            break;
        }

        default:{
            std::cout << "invalid instruction\n";
            return false;
            break;
        }
    }

    return true;
}

uint32_t multiple(std::vector<uint32_t>& instructionDataMix, ExecState& state){
    uint64_t* additional = new uint64_t[0];

    for(uint64_t i = 0; i < instructionDataMix.size(); ++i){
        uint32_t instruction = instructionDataMix[i];

        uint32_t size = (instruction & 0xFF000000) >> 24;

        if(size == 0){
            continue;
        }

        delete[] additional;
        additional = new uint64_t[size]{0};

        for(uint64_t j = 0; j < (size - 1); ++j){

            additional[j] = instructionDataMix[i + j + 1];
        }

        if(!single(instruction & 0x00FFFFFF, state, additional, size - 1)){
            std::cout << "invalid isntruction\n";

            return 0;
        }

        i += size - 1;
    }

    delete[] additional;

    if(instructionDataMix.size() == 0){
        return 0;
    }

    uint32_t ret = instructionDataMix.back();
    instructionDataMix.pop_back();
    return ret;
}

}; // namespace Exec
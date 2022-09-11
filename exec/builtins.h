#pragma once

#include "stack/stack.h"
#include "stackOps/stackOps.h"

#include <iostream>
#include <cstdlib>

#ifdef WIN32
    #include <conio.h>

#else // probably unix, dont really care otherwise
    #include <termios.h>

    // not perfect but this will do for now
    #define getch() getchar()
#endif

namespace Exec{
namespace Builtins{

void exit(Stack& s){
    ::exit(s.pop());
}

void puti(Stack& s){
    std::cout << s.pop();
}

void putc(Stack& s){
    std::cout << static_cast<char> (s.pop() & 0xFF);
}

void sleep(Stack& s){
    return; // do nothing, deprecate this
}

void getc(Stack& s){
    s.push(getch());
}

#warning TODO impl. output stream switching
void setStdOut(Stack& s){}

void setGCOut(Stack& s){}

void flushOut(Stack& s){}



bool execFromIndex(uint64_t index, ExecState& state){
    switch(index){
        case 0:{
            Builtins::exit(*state.allStacks[state.activeStack]);
            break;
        }
        case 1:{
            Builtins::puti(*state.allStacks[state.activeStack]);
            break;
        }
        case 2:{
            Builtins::putc(*state.allStacks[state.activeStack]);
            break;
        }
        case 3:{
            Builtins::getc(*state.allStacks[state.activeStack]);
            break;
        }
        case 5:{
            SOp::size(*state.allStacks[state.activeStack]);
            break;
        }
        case 9:{
            SOp::active(state);
            break;
        }

        default:{
            return false;
        }
    }

    return true;
}

}; // namespace Builtins
}; // namespace Exec
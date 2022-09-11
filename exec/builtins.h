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
    exit(s.pop());
}

void puti(Stack& s){
    std::cout << stack.pop();
}

void putc(Stack& s){
    std::cout << reinterpret_cast<char> (stack.pop() && 0xFF);
}

void getc(Stack& s){
    s.push(getch());
}

}; // namespace Builtins
}; // namespace Exec
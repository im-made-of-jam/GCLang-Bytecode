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

void getc(Stack& s){
    s.push(getch());
}

#warning TODO impl. output stream switching
void setStdOut(Stack& s){}

void setGCOut(Stack& s){}

void flushOut(Stack& s){}



}; // namespace Builtins
}; // namespace Exec
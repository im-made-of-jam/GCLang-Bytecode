#include <iostream>

#include "enums/instructionEnum.h"
#include "stack/stack.h"
#include "utils/loadfile.h"

#include "stackOps/stackOps.h"

int main(int argc, char* argv[]){
    Stack s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(5);

    SOp::makePtr(s);

    SOp::dup(s);

    std::cout << std::hex << s.pop() << std::endl;

    SOp::derefPtr(s);

    std::cout << s.pop() << std::endl;
    std::cout << s.pop() << std::endl;
    std::cout << s.pop() << std::endl;
    std::cout << s.pop() << std::endl;
    std::cout << s.pop() << std::endl;

    return 0;
}
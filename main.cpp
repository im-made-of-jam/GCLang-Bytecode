#include <iostream>

#include "enums/instructionEnum.h"
#include "stack/stack.h"
#include "utils/loadfile.h"

#include "stackOps/stackOps.h"

int main(int argc, char* argv[]){
    Stack s;

    s.push(1);
    s.push(1);

    SOp::sub(s);

    std::cout << s.pop() << std::endl;

    return 0;
}
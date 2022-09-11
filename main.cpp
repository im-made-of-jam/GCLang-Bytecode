#include <iostream>

#include "enums/instructionEnum.h"
#include "stack/stack.h"
#include "utils/loadfile.h"

#include "stackOps/stackOps.h"

#include "exec/exec.h"

int main(int argc, char* argv[]){
    ExecState p;

    Exec::single(Enum::push, p, 5);
    Exec::single(Enum::push, p, 5);
    Exec::single(Enum::add, p);

    Exec::single(Enum::builtin, p, 1);

    std::cout << "no segfault!\n";

    return 0;
}
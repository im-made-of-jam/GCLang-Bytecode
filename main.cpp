// this isnt the first bytecode interpreter i have written, but it is the first one written to fulfill a purpose,
//   the other one being written to execute a basic, not very useful asm language that was written specifically for it to run

#include <iostream>

#include "enums/instructionEnum.h"
#include "stack/stack.h"
#include "utils/loadfile.h"

#include "stackOps/stackOps.h"

#include "exec/exec.h"

int main(int argc, char* argv[]){
    ExecState eState;

    std::vector<uint32_t> vec = {
        Enum::push    | 0x02000000,
        5,
        Enum::push    | 0x02000000,
        5,
        Enum::add     | 0x01000000,
        Enum::builtin | 0x02000000,
        2,
        Enum::push    | 0x02000000,
        69,
        Enum::builtin | 0x02000000,
        1
    };

    Exec::multiple(vec, eState);

    return 0;
}
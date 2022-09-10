// g++ ./main.cpp -o ./main.exe -I . -std=gnu++20 -Wall

// "g++"           - compiler
// "./main.cpp"    - this file
// "-o ./main.exe" - output file
// "-I ."          - include path includes base directory so relative includes are not needed
// "-std=gnu++20"  - modern standard so std::filesystem works
// "-Wall"         - report all warnings

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
#pragma once

#include <cstdint>

constexpr uint64_t STACKBLOCK_SIZE = 65536;

struct StackBlock{
    uint64_t* raw;

    StackBlock(){
        raw = new uint64_t[STACKBLOCK_SIZE];

        for(uint64_t i = 0; i < STACKBLOCK_SIZE; ++i){
            raw[i] = 0;
        }
    }
};
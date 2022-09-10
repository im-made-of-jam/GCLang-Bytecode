#pragma once

#include "stack/stackblock.h"

#include <string>
#include <exception>

constexpr uint64_t STACKBLOCK_NUMBER = 262144;

struct SlotException : std::exception{
    SlotException() : std::exception(){};
};

class Stack{
    uint64_t blocksAssigned = 0;

    StackBlock** blocks = new StackBlock*[STACKBLOCK_NUMBER];

    // the pointer always points to the first empty value of the stack.
    uint64_t pointer = 0;

  public:
    Stack(){
        for(uint64_t i = 0; i < STACKBLOCK_NUMBER; ++i){
            blocks[i] = nullptr;
        }
    }

    void push(uint64_t value){
        // get the block number and the position within that block to push the value to
        uint64_t blockN = (pointer / STACKBLOCK_SIZE) + 1;
        uint64_t blockPos = pointer % STACKBLOCK_SIZE;

        // if we dont have enough blocks assigned, then add another block to our pool of blocks
        if(blockN > blocksAssigned){
            if(blockN >= STACKBLOCK_NUMBER){
                std::cout << "no more stack blocks to allocate\n";
                throw new SlotException();
            }

            blocks[blocksAssigned] = new StackBlock;

            blocksAssigned += 1;
        }

        // now we place the value into its position within the correct block
        blocks[blockN - 1]->raw[blockPos] = value;

        // then increment the pointer
        pointer += 1;
    }

    uint64_t pop(){
        // the first thing we do is decrement the pointer so that it points at a value rather than at nothing
        pointer -= 1;

        // we then calculate the block number and the position within said block to obtain the value from
        uint64_t blockN = pointer / STACKBLOCK_SIZE;
        uint64_t blockPos = pointer % STACKBLOCK_SIZE;

        // then we get the value
        uint64_t value = blocks[blockN]->raw[blockPos];

        // now we check to see if we can de-allocate a block
        if(blocks[blockN + 1] != nullptr){
            // if we can then we do
            delete blocks[blockN + 1];

            // and mark it as such
            blocks[blockN + 1] = nullptr;
        }

        return value;
    }
};
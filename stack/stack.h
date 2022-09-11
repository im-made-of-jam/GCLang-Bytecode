#pragma once

#include "stack/stackblock.h"

#include <string>
#include <exception>

constexpr uint64_t STACKBLOCK_NUMBER = 65536;

struct SlotException : std::exception{
    SlotException() : std::exception(){};
};

class Stack{
    // number of blocks in memory assigned to this object
    uint64_t blocksAssigned = 0;

    // the number of blocks we can have
    uint64_t maxBlocks;

    // array of blocks
    // there is a tradeoff here betweem the number of blocks we have and the size of this array that keeps track of them
    // the larger this array is, the more blocks we can have, but also the longer this array becomes
    StackBlock** blocks = new StackBlock*[STACKBLOCK_NUMBER];

  public:
    // the pointer always points to the first empty value of the stack.
    uint64_t pointer = 0;

    Stack(uint64_t numBlocks = STACKBLOCK_NUMBER){
        maxBlocks = numBlocks;

        for(uint64_t i = 0; i < maxBlocks; ++i){
            blocks[i] = nullptr;
        }
    }

    // adds a uint64_t to the top of the stack, allocating another memory block if necessary
    void push(uint64_t value){
        // get the block number and the position within that block to push the value to
        uint64_t blockN = (pointer / STACKBLOCK_SIZE) + 1;
        uint64_t blockPos = pointer % STACKBLOCK_SIZE;

        // if we dont have enough blocks assigned, then add another block to our pool of blocks
        if(blockN > blocksAssigned){
            if(blockN >= maxBlocks){
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

    // removes the top value from the stack, and returns it from the function
    // also de-allocates memory if able to do so
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
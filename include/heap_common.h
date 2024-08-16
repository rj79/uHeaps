#ifndef HEAP_COMMON_H
#define HEAP_COMMON_H

uint16_t parent(uint16_t id);
uint16_t leftChild(uint16_t id);
uint16_t rightChild(uint16_t id);

uint16_t parent(uint16_t id) 
{
    return (id - 1) / 2;
}

uint16_t leftChild(uint16_t id)
{
    return (id << 1) + 1;
}

uint16_t rightChild(uint16_t id)
{
    return (id << 1) + 2;
}

#endif
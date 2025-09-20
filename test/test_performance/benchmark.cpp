#include <Arduino.h>
#include "TElement.h"
#include "MinHeap.h"
#include "Timer.h"

MinHeap<TElement> heap(100);
uint16_t QueueSize = 10;
const uint16_t MaxQueueSize = 1000;
const uint16_t SizeIncrement = 10;

TElement Elements[MaxQueueSize];

void reset()
{
    randomSeed(0xdeadbeef);
    for (uint16_t i = 0; i < MaxQueueSize; ++i) {
        Elements[i].set(random(0, 10000));
    }
}

void setup()
{
    Serial.begin(9600);
    while (!Serial);
    delay(2000);
    Serial.println('\n');
    Serial.println("Size;Linear;Heap;");
}

unsigned long bench_heap()
{
    Timer t;
    reset();
    MinHeap<TElement>* heap = new MinHeap<TElement>(QueueSize);
    t.start();
    
    for (uint16_t i = 0; i < QueueSize; ++i) {
        heap->insert(&Elements[i]);
    }

    for (uint16_t i = 0; i < 10000; ++i) {        
        TElement* e = heap->getMin();
        e->add(random(100, 10000) * 10);
        heap->updateMin();
    }
    
    t.stop();
    delete heap;
    return t.elapsed();
}

void loop()
{
    char buffer[64];

    snprintf(buffer, sizeof(buffer), "%u;", QueueSize);
    Serial.print(buffer);
    Serial.flush();

    snprintf(buffer, sizeof(buffer), "%u;", bench_heap());
    Serial.println(buffer);
    
    if (QueueSize < MaxQueueSize) {
        QueueSize += SizeIncrement;
    }
    else {
        Serial.println("Done!");
        while (true) {};
    }
}
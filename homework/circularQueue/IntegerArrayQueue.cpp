#include "IntegerArrayQueue.h"

bool IntegerArrayQueue::enqueue(int value) {
    // Check if full
    if ((back + 2) % size == front)
        return false;

    // Move back to next position
    back = (back + 1) % size;
    
    // Enqueue the value
    array[back] = value;

    return true;
}

int IntegerArrayQueue::dequeue() {
    // Check if empty
    if ((back + 1) % size == front)
        return 0;
    
    // Get the value at the front
    int value = array[front];

    // Move front to next position
    front = (front + 1) % size;

    return value;
}
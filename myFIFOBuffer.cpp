#include "myFIFOBuffer.h"

void myFIFOBufferClass::init(uint8_t *u8_ptr, size_t size) {
    buf.buffer = u8_ptr;
    buf._size = size;
    buf._head = 0;
    buf._tail = 0;
    buf._dataCnt = 0;
}

bool myFIFOBufferClass::isEmpty() {
    return ((buf._head == buf._tail) && (buf._dataCnt == 0));
}

bool myFIFOBufferClass::isFull() {
    return (buf._dataCnt == buf._size);
}

size_t myFIFOBufferClass::available() {
    return buf._dataCnt;
}

uint8_t myFIFOBufferClass::read() {
    if (this->isEmpty()) return false;
    if (buf._dataCnt) {
        buf._dataCnt--;
        buf._tail++;
    }
    return buf.buffer[buf._tail];
}

bool myFIFOBufferClass::write(uint8_t data) {
    if (this->isFull()) return false;
    buf._head++;
    buf._dataCnt++;
    buf.buffer[buf._head] = data;
    return true;
}
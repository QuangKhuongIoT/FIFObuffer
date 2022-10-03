#include "myFIFOBuffer.h"

void myFIFOBufferClass::init(uint8_t *u8_ptr, size_t size) {
    _buf.buffer = u8_ptr;
    _buf.size = size;
    _buf.head = 0;
    _buf.tail = 0;
    _buf.dataCnt = 0;
}

bool myFIFOBufferClass::isEmpty() {
    return ((_buf.head == _buf.tail) && (_buf.dataCnt == 0));
}

bool myFIFOBufferClass::isFull() {
    return (_buf.dataCnt == _buf.size);
}

size_t myFIFOBufferClass::available() {
    return _but.dataCnt;
}

uint8_t myFIFOBufferClass::read() {
    if (this->isEmpty()) return false;
    if (_buf.dataCnt) {
        _but.dataCnt--;
        _but.tail++;
    }
    return _but.buffer[_buf.tail];
}

bool myFIFOBufferClass::write(uint8_t data) {
    if (this->isFull()) return false;
    _but.head++;
    _but.dataCnt++;
    _but.buffer[buf.head] = data;
    return true;
}
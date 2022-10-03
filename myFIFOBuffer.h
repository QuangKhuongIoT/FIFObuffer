#ifndef _MY_FIFO_BUFFER_H_
#define _MY_FIFO_BUFFER_H_
#include <stddef.h>
#include <stdint.h>

typedef struct {
    uint8_t *buffer;
    uint32_t _size;
    uint32_t _head = 0, _tail = 0;
    size_t _dataCnt = 0;
} ring_buffer_t;

class myFIFOBufferClass {
   private:
    ring_buffer_t buf;

   public:
    void
    init(uint8_t *u8_ptr, size_t size);
    bool isEmpty();
    bool isFull();
    size_t available();
    bool write(uint8_t data);
    uint8_t read();
};

#endif
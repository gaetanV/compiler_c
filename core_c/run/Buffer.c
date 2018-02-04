#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Buffer {
    FILE *fp;
    
    char ch;
    char * buffer;
    unsigned short _buffer;
    char * output;
    unsigned short import;
    unsigned short * pointer;
    unsigned short _pointer;
    unsigned short _cmp;
    unsigned short c;

};

//Memory
#define MemoryChar(buffer,ch)buffer->buffer[buffer->_buffer++]=ch;
#define MemoryMap(buffer)buffer->pointer[buffer->_pointer++]=buffer->_buffer;
#define Memory(buffer)buffer->buffer[buffer->_buffer++]=buffer->ch;

void SequenceInit(struct Buffer *buffer, char * c) {
    buffer->fp = fopen(c, "r");
    if (buffer->fp == NULL) {
        printf("File %s not found", c);
        exit(0);
    }

    fseek(buffer->fp, 0, SEEK_END);
    int size = ftell(buffer->fp);
    fseek(buffer->fp, 0, SEEK_SET);

    buffer->buffer = (char*)malloc(size * sizeof (char));
    buffer->pointer = (unsigned short*)malloc(size / 2 * sizeof (unsigned short));
    buffer->output = (char*)malloc(size * sizeof (char));
    buffer->output[0] = '\0';

    buffer->_buffer = 0;
    buffer->_pointer = 0;
    buffer->c = 0;

    return;
};



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
    unsigned short  * pointer;
    unsigned short  _pointer;
    unsigned short _cmp;
    unsigned short c;
  
};

void SequenceInit(struct Buffer * this, char * c) {
    this->fp = fopen(c, "r");
    if (this->fp == NULL) {
        printf("File %s not found", c);
        exit(0);
    }
    
    fseek(this->fp, 0, SEEK_END);
    int size = ftell(this->fp); 
    fseek(this->fp, 0, SEEK_SET);
    
    this->buffer  = malloc(size * sizeof(char));
    this->pointer = malloc(size/2 * sizeof(unsigned short ));
    this->output  = malloc(size * sizeof(char));
    this->output[0] = '\0';
 
    this->_buffer = 0;
    this->_pointer = 0;
    this->c = 0;

    return;
};



#include <stdio.h>

struct sequenceRegex {
    int c;
    char ch;
    FILE *fp;
    char output[255];
    int _output;
    char buffer[255];
    int _buffer;
    int class[255];
    int _class;
    int _cmp;

};

int SequenceInit(struct sequenceRegex * this, char * c) {
    this->fp = fopen(c, "r");
    if (this->fp == NULL) {
        printf("File %s not found", c);
        return 0;
    }
    this->c = 0;
    this->_buffer = 0;
    return 1;
};

void SequenceFlush(struct sequenceRegex * this) {
    fclose(this->fp);

    printf("%s\n", this->buffer);


    for (int i = 0; i < this->_class; i++) {
        printf(" %d \n", this->class[i]);

    }

}

int nextCharIs(struct sequenceRegex * this, char a) {

    this->ch = fgetc(this->fp);
    if (this->ch == a) {
        return 1;
    }
    return 0;
}


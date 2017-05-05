#include <stdio.h>
#include <string.h>

struct sequenceRegex {
    int c;
    char ch;
    FILE *fp;
    int import[2];
    int module[10];
    int _module;

    
    char buffer[255];
    int _buffer;
    int pointer[128];
    
    int func[20];
    int _func;
    
    int funcStatic[20];
    int _funcStatic;
    
    int _pointer;
    
    int _cmp;
    int _cmp2;
    
};

int SequenceInit(struct sequenceRegex * this, char * c) {
    this->fp = fopen(c, "r");
    if (this->fp == NULL) {
        printf("File %s not found", c);
        return 0;
    }
    this->_funcStatic = 0;
    this->_func = 0;
    this->_module = 0;
    this->_buffer = 0;
    this->_pointer = 0;
    this->c = 0;

    return 1;
};

void SequenceFlush(struct sequenceRegex * this) {
    fclose(this->fp);
}



int nextCharIs(struct sequenceRegex * this, char a) {

    this->ch = fgetc(this->fp);
    if (this->ch == a) {
        return 1;
    }
    return 0;
}


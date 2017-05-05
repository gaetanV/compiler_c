#include <stdio.h>

int RegexStaticOrFunc(struct sequenceRegex * this) {

    // REGEX ublic Start at 115

    if ((this->ch = fgetc(this->fp)) != 116) {
  
        MemoryChar(this, 115);
        return 0;
    }
    if ((this->ch = fgetc(this->fp)) != 97) {

        MemoryChar(this, 115);
        MemoryChar(this, 116);
        return 0;
    }
    if ((this->ch = fgetc(this->fp)) != 116) {

        MemoryChar(this, 115);
        MemoryChar(this, 116);
        MemoryChar(this, 97);
        return 0;
    }
    if ((this->ch = fgetc(this->fp)) != 105) {
 
        MemoryChar(this, 115);
        MemoryChar(this, 116);
        MemoryChar(this, 97);
        MemoryChar(this, 116);
        return 0;
    }
    if ((this->ch = fgetc(this->fp)) != 99) {
     
        MemoryChar(this, 115);
        MemoryChar(this, 116);
        MemoryChar(this, 97);
        MemoryChar(this, 116);
        MemoryChar(this, 105);
        return 0;
    }

    return 1;

}

int RegexStatic(struct sequenceRegex * this) {

    // REGEX STATIC Start at 115
    if (!nextCharIs(this, 116)) {
        return 0;
    }
    if (!nextCharIs(this, 97)) {
        return 0;
    }
    if (!nextCharIs(this, 116)) {
        return 0;
    }
    if (!nextCharIs(this, 105)) {
        return 0;
    }
    if (!nextCharIs(this, 99)) {
        return 0;
    }
    ///////////
    return 1;

}

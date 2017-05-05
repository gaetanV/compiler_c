#include <stdio.h>

int RegexConstructorOrFunc(struct sequenceRegex * this) {

    // REGEX CONSTRUCT Start at 99

    if ((this->ch = fgetc(this->fp)) != 111) {
      
        MemoryChar(this, 99);
        MemoryChar(this, this->ch);
        return 0;
    }

    if ((this->ch = fgetc(this->fp)) != 110) {
     
        MemoryChar(this, 99);
        MemoryChar(this, 111);
        return 0;
    }
    if ((this->ch = fgetc(this->fp)) != 115) {
 
        MemoryChar(this, 99);
        MemoryChar(this, 111);
        MemoryChar(this, 110);
        return 0;
    }

    if ((this->ch = fgetc(this->fp)) != 116) {
   
        MemoryChar(this, 99);
        MemoryChar(this, 111);
        MemoryChar(this, 110);
        MemoryChar(this, 115);
        return 0;
    }

    if ((this->ch = fgetc(this->fp)) != 114) {

        MemoryChar(this, 99);
        MemoryChar(this, 111);
        MemoryChar(this, 110);
        MemoryChar(this, 115);
        MemoryChar(this, 116);
        return 0;
    }

    if ((this->ch = fgetc(this->fp)) != 117) {

        MemoryChar(this, 99);
        MemoryChar(this, 111);
        MemoryChar(this, 110);
        MemoryChar(this, 115);
        MemoryChar(this, 116);
        MemoryChar(this, 114);
        return 0;
    }

    if ((this->ch = fgetc(this->fp)) != 99) {

        MemoryChar(this, 99);
        MemoryChar(this, 111);
        MemoryChar(this, 110);
        MemoryChar(this, 115);
        MemoryChar(this, 116);
        MemoryChar(this, 114);
        MemoryChar(this, 117);
        return 0;
    }

    if ((this->ch = fgetc(this->fp)) != 116) {

        MemoryChar(this, 99);
        MemoryChar(this, 111);
        MemoryChar(this, 110);
        MemoryChar(this, 115);
        MemoryChar(this, 116);
        MemoryChar(this, 114);
        MemoryChar(this, 117);
        MemoryChar(this, 99);
        return 0;
    }

    if ((this->ch = fgetc(this->fp)) != 111) {
   
        MemoryChar(this, 99);
        MemoryChar(this, 111);
        MemoryChar(this, 110);
        MemoryChar(this, 115);
        MemoryChar(this, 116);
        MemoryChar(this, 114);
        MemoryChar(this, 117);
        MemoryChar(this, 99);
        MemoryChar(this, 116);
        return 0;
    }

    if ((this->ch = fgetc(this->fp)) != 114) {

        MemoryChar(this, 99);
        MemoryChar(this, 111);
        MemoryChar(this, 110);
        MemoryChar(this, 115);
        MemoryChar(this, 116);
        MemoryChar(this, 114);
        MemoryChar(this, 117);
        MemoryChar(this, 99);
        MemoryChar(this, 116);
        MemoryChar(this, 111);
        return 0;
    }

    return 1;
}

int RegexConstructor(struct sequenceRegex * this) {

    // REGEX CONSTRUCT Start at 99

    if (!nextCharIs(this, 111)) {
        return 0;
    }
    if (!nextCharIs(this, 110)) {
        return 0;
    }
    if (!nextCharIs(this, 115)) {
        return 0;
    }
    if (!nextCharIs(this, 116)) {
        return 0;
    }
    if (!nextCharIs(this, 114)) {
        return 0;
    }
    if (!nextCharIs(this, 117)) {
        return 0;
    }
    if (!nextCharIs(this, 99)) {
        return 0;
    }
    if (!nextCharIs(this, 116)) {
        return 0;
    }
    if (!nextCharIs(this, 111)) {
        return 0;
    }
    if (!nextCharIs(this, 114)) {
        return 0;
    }

    return 1;

}

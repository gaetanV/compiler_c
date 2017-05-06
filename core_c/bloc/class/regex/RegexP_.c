#include <stdio.h>

int RegexRivateOrFunc(struct sequenceRegex * this) {

    // REGEX rivate Start at 114

    if ((this->ch = fgetc(this->fp)) != 105) {
        
        MemoryChar(this, 112);
        MemoryChar(this, 114);
        return 0;
    }
    if ((this->ch = fgetc(this->fp)) != 118) {
     
        MemoryChar(this, 112);
        MemoryChar(this, 114);
        MemoryChar(this, 105);
        return 0;
    }
    if ((this->ch = fgetc(this->fp)) != 97) {
     
        MemoryChar(this, 112);
        MemoryChar(this, 114);
        MemoryChar(this, 105);
        MemoryChar(this, 118);
        return 0;
    }
    if ((this->ch = fgetc(this->fp)) != 116) {

        MemoryChar(this, 112);
        MemoryChar(this, 114);
        MemoryChar(this, 105);
        MemoryChar(this, 118);
        MemoryChar(this, 97);
        return 0;
    }
    if ((this->ch = fgetc(this->fp)) != 101) {
     
        MemoryChar(this, 112);
        MemoryChar(this, 114);
        MemoryChar(this, 105);
        MemoryChar(this, 118);
        MemoryChar(this, 97);
        MemoryChar(this, 116);
        return 0;
    }

    return 1;

}

int RegexUblicOrFunc(struct sequenceRegex * this) {

    // REGEX ublic Start at 117

    if ((this->ch = fgetc(this->fp)) != 98) {
    
        MemoryChar(this, 112);
        MemoryChar(this, 117);
        return 0;
    }
    if ((this->ch = fgetc(this->fp)) != 108) {

        MemoryChar(this, 112);
        MemoryChar(this, 117);
        MemoryChar(this, 98);
        return 0;
    }
    if ((this->ch = fgetc(this->fp)) != 105) {

        MemoryChar(this, 112);
        MemoryChar(this, 117);
        MemoryChar(this, 98);
        MemoryChar(this, 108);
        return 0;
    }
    if ((this->ch = fgetc(this->fp)) != 99) {
      
        MemoryChar(this, 112);
        MemoryChar(this, 117);
        MemoryChar(this, 98);
        MemoryChar(this, 108);
        MemoryChar(this, 105);
        return 0;
    }
    return 1;
}


/*
int RegexP_(struct sequenceRegex * this, int(f) (struct sequenceRegex *)) {

    // REGEX P_ Start at 112

    switch (this->ch) {
        case 117:
            // REGEX ublic Start at 117
            if (!nextCharIs(this, 98)) {
                return 0;
            }
            if (!nextCharIs(this, 108)) {
                return 0;
            }
            if (!nextCharIs(this, 105)) {
                return 0;
            }
            if (!nextCharIs(this, 99)) {
                return 0;
            }

            printf("-- Public \n");
            return f(this);
            break;
        case 114:
            // REGEX rivate Start at 114
            if (!nextCharIs(this, 105)) {
                return 0;
            }
            if (!nextCharIs(this, 118)) {
                return 0;
            }
            if (!nextCharIs(this, 97)) {
                return 0;
            }
            if (!nextCharIs(this, 116)) {
                return 0;
            }
            if (!nextCharIs(this, 101)) {
                return 0;
            }

            printf("-- Private \n");
            return f(this);
            break;
        default:
            return 0;
    }
    return 0;
}
*/
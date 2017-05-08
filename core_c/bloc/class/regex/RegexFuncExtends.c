#include <stdio.h>

int RegexMemoryNotSpaceInlineOrFuncStart(struct sequenceRegex * this) {
  
    Memory(this);
    while (1) {
        switch (this->ch = fgetc(this->fp)) {
            case EOF:
                return 0;
            case 10:
                return 0;
            case 59:
                return 0;
            case 32:
                return 1;
            case 123:
                return 2;
            default:
                Memory(this);
                break;     
        }
    }
}


int RegexExtends(struct sequenceRegex * this) {

    // REGEX Extends Start at 101
    if (fgetc(this->fp) != 120) {
        return 0;
    }
    if (fgetc(this->fp) != 116) {
        return 0;
    }
    if (fgetc(this->fp) != 101) {
        return 0;
    }
    if (fgetc(this->fp) != 110) {
        return 0;
    }
    if (fgetc(this->fp) != 100) {
        return 0;
    }
    if (fgetc(this->fp) != 115) {
        return 0;
    }


    if (!RegexJumpSpace(this)) {
        return 0;
    }

    return RegexMemoryNotSpaceInlineOrFuncStart(this);
}

int RegexImplements(struct sequenceRegex * this) {


    // REGEX Implements Start at 105
    if (fgetc(this->fp) != 109) {
        return 0;
    }
    if (fgetc(this->fp) != 112) {
        return 0;
    }
    if (fgetc(this->fp) != 108) {
        return 0;
    }
    if (fgetc(this->fp) != 101) {
        return 0;
    }
    if (fgetc(this->fp) != 109) {
        return 0;
    }
    if (fgetc(this->fp) != 101) {
        return 0;
    }

    if (fgetc(this->fp) != 110) {
        return 0;
    }
    if (fgetc(this->fp) != 116) {
        return 0;
    }
    if (fgetc(this->fp) != 115) {
        return 0;
    }

    if (!RegexJumpSpace(this)) {
        return 0;
    }

    return RegexMemoryNotSpaceInlineOrFuncStart(this);
}


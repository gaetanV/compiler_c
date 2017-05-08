#include <stdio.h>

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


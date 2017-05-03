#include <stdio.h>

int RegexImport(struct sequenceRegex * this) {

    // REGEX IMPORT Start at 105
    if (fgetc(this->fp) != 109) {
        return 0;
    }
    if (fgetc(this->fp) != 112) {
        return 0;
    }
    if (fgetc(this->fp) != 111) {
        return 0;
    }
    if (fgetc(this->fp) != 114) {
        return 0;
    }
    if (fgetc(this->fp) != 116) {
        return 0;
    }

    if (!RegexJumpSpace(this)) {
        return 0;
    }

    if (!RegexMemoryNotSpaceInline(this)) {
        return 0;
    }


    if (!RegexJumpSpace(this)) {
        return 0;
    }
    // REGEX FROM

    if (this->ch != 102) {
        return 0;
    }
    if (fgetc(this->fp) != 114) {
        return 0;
    }
    if (fgetc(this->fp) != 111) {
        return 0;
    }
    if (fgetc(this->fp) != 109) {
        return 0;
    }

    if (!RegexJumpSpace(this)) {
        return 0;
    }

    ///////////
    Memory(this);


    while (1) {
        switch (this->ch = fgetc(this->fp)) {
            case EOF:
                return 0;
            case 10:
                return 0;
            case 32:
                if (!RegexEndOfScriptLine(this)) {
                    return 0;
                } else {
                    return 1;
                }
            case 59:
                return 1;
            default:
                Memory(this);
                break;
        }
    }

}
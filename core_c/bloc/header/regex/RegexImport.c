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

    if (!RegexNotSpaceInline(this)) {
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


    ///////////

    if (!RegexJumpSpace(this)) {
        return 0;
    }
    switch (RegexNotSpaceOrEndOfScriptLine(this)) {
        case 0:
            return 0;
            break;
        case 1:
            if (!RegexEndOfScriptLine(this)) {
                return 0;
            }
            break;
    }

    return 1;
}
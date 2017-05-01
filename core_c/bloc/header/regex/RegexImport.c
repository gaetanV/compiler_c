#include <stdio.h>

int RegexImport(struct sequenceRegex * this) {

    // REGEX IMPORT Start at 105

    if (!nextCharIs(this, 109)) {
        return 0;
    }
    if (!nextCharIs(this, 112)) {
        return 0;
    }
    if (!nextCharIs(this, 111)) {
        return 0;
    }
    if (!nextCharIs(this, 114)) {
        return 0;
    }
    if (!nextCharIs(this, 116)) {
        return 0;
    }
    ///////////


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
    if (!nextCharIs(this, 114)) {
        return 0;
    }
    if (!nextCharIs(this, 111)) {
        return 0;
    }
    if (!nextCharIs(this, 109)) {
        return 0;
    }

    ///////////

    if (!RegexJumpSpace(this)) {
        return 0;
    }
    switch (RegexNotSpaceOEndOfScriptLine(this)) {
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
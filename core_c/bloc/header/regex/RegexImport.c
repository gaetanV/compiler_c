#include <stdio.h>

int RegexImport(struct sequenceRegex * this) {

    // REGEX IMPORT Start at 105
    
    if (!nextCharIs(this,109)) {
        return 0;
    }
    if (!nextCharIs(this,112)) {
        return 0;
    }
    if (!nextCharIs(this,111)) {
        return 0;
    }
    if (!nextCharIs(this,114)) {
        return 0;
    }
    if (!nextCharIs(this,116)) {
        return 0;
    }
    ///////////

    if (!nextCharInline(this)) {
        return 0;
    }
    if (!_Regex(this, RegexSpace)) {
        return 0;
    }
    if (!_Regex(this, RegexNotSpace)) {
        return 0;
    }
    if (!nextCharInline(this)) {
        return 0;
    }
    if (!_Regex(this, RegexSpace)) {
        return 0;
    }
    // REGEX FROM
    
    if (this->ch != 102) {
        return 0;
    }
    if (!nextCharIs(this,114)) {
        return 0;
    }
    if (!nextCharIs(this,111)) {
        return 0;
    }
    if (!nextCharIs(this,109)) {
        return 0;
    }

    ///////////
    

    if (!nextCharInline(this)) {
        return 0;
    }
    if (!_Regex(this, RegexSpace)) {
        return 0;
    }
    if (!nextCharInline(this)) {
        return 0;
    }

    if (!_Regex(this, RegexNotSpaceOrEndOfLine)) {
        return 0;
    }

    if (this->ch != 59) {
        if (!_Regex(this, RegexEndOfLine)) {
            return 0;
        }
    }

    return 1;
}
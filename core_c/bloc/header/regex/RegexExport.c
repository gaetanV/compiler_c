#include <stdio.h>

int RegexExport(struct sequenceRegex * this) {
    
    // REGEX EXPORT start at 101
    if (!nextCharIs(this,120)) {
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
    
    if (!RegexJumpSpace(this)) {
        return 0;
    }


    return 1;
}

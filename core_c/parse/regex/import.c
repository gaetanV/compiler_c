#include <stdio.h>



int newImport(struct sequenceRegex * this) {

    // REGEX IMPORT Start at 105
    if (!nextCharInline(this)) {
        return 0;
    }
    if (currentChar(this) != 109) {
        return 0;
    }
    if (!nextCharInline(this)) {
        return 0;
    }
    if (currentChar(this) != 112) {
        return 0;
    }
    if (!nextCharInline(this)) {
        return 0;
    }
    if (currentChar(this) != 111) {
        return 0;
    }
    if (!nextCharInline(this)) {
        return 0;
    }
    if (currentChar(this) != 114) {
        return 0;
    }
    if (!nextCharInline(this)) {
        return 0;
    }
    if (currentChar(this) != 116) {
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

    if (currentChar(this) != 102) {
        return 0;
    }
    if (!nextCharInline(this)) {
        return 0;
    }
    if (currentChar(this) != 114) {
        return 0;
    }

    if (!nextCharInline(this)) {
        return 0;
    }
    if (currentChar(this) != 111) {
        return 0;
    }
    if (!nextCharInline(this)) {
        return 0;
    }
    if (currentChar(this) != 109) {
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

    if (currentChar(this) != 59) {
        if (!_Regex(this, RegexEndOfLine)) {
            return 0;
        }
    }
    printf("seq import complete \n");
    return 1;
}
#include <stdio.h>

int newConstructor(struct sequenceRegex * this) {
    
    // REGEX CONSTRUCT Start at 99
    if (!nextCharInline(this)) {
        return 0;
    }
    if (currentChar(this) != 111) {
        return 0;
    }
    if (!nextCharInline(this)) {
        return 0;
    }
    if (currentChar(this) != 110) {
        return 0;
    }
    if (!nextCharInline(this)) {
        return 0;
    }
    if (currentChar(this) != 115) {
        return 0;
    }
    if (!nextCharInline(this)) {
        return 0;
    }
    if (currentChar(this) != 116){
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
    if (currentChar(this) != 117) {
        return 0;
    }
    if (!nextCharInline(this)) {
        return 0;
    }
    if (currentChar(this) != 99){
        return 0;
    }
    if (!nextCharInline(this)) {
        return 0;
    }
    if (currentChar(this) != 116) {
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
    ///////////
    
    return newFuncArgs(this);
    
    
}

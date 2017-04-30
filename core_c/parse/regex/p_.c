#include <stdio.h>

int newP_(struct sequenceRegex * this) {
   
    // REGEX P_ Start at 112
    
    if (!nextCharInline(this)) {
        return 0;
    }
    switch (currentChar(this)) {
        case 117:
            // REGEX ublic Start at 117
            if (!nextCharInline(this)) {
                return 0;
            }
            if (currentChar(this) != 98) {
                return 0;
            }
            if (!nextCharInline(this)) {
                return 0;
            }
            if (currentChar(this) != 108) {
                return 0;
            }
            if (!nextCharInline(this)) {
                return 0;
            }
            if (currentChar(this) != 105) {
                return 0;
            }
            if (!nextCharInline(this)) {
                return 0;
            }
            if (currentChar(this) != 99) {
                return 0;
            }
            ///////////
            
            if (!nextCharInline(this)) {
                return 0;
            }
            printf("-- Public \n");
            return newFuncNameArgs(this);
            break;
        case 114:
            // REGEX rivate Start at 114
           
            if (!nextCharInline(this)) {
                return 0;
            }
            if (currentChar(this) != 105) {
                return 0;
            }
            if (!nextCharInline(this)) {
                return 0;
            }
            if (currentChar(this) != 118) {
                return 0;
            }
            if (!nextCharInline(this)) {
                return 0;
            }
            if (currentChar(this) != 97) {
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
            if (currentChar(this) != 101) {
                return 0;
            }
            ///////////
            
            if (!nextCharInline(this)) {
                return 0;
            }
            printf("-- Private \n");
            return newFuncNameArgs(this);
            break;
        default:
            return 0;
    }
    return 1;
}

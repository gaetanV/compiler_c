#include <stdio.h>

int RegexUblic(struct sequenceRegex * this) {
 

    // REGEX ublic Start at 117
    
    if (!nextCharIs(this, 98)) {
        return 0;
    }
    if (!nextCharIs(this, 108)) {
        return 0;
    }
    if (!nextCharIs(this, 105)) {
        return 0;
    }
    if (!nextCharIs(this, 99)) {
        return 0;
    }
    ///////////
    return 1;

}

int RegexRivate(struct sequenceRegex * this) {

    // REGEX rivate Start at 114
    if (!nextCharIs(this, 105)) {
        return 0;
    }
    if (!nextCharIs(this, 118)) {
        return 0;
    }
    if (!nextCharIs(this, 97)) {
        return 0;
    }
    if (!nextCharIs(this, 116)) {
        return 0;
    }
    if (!nextCharIs(this, 101)) {
        return 0;
    }

    ///////////
    return 1;
}



int RegexP_(struct sequenceRegex * this,int(f) (struct sequenceRegex *)) {
   
    // REGEX P_ Start at 112
    
    if (!nextCharInline(this)) {
        return 0;
    }
    switch (this->ch) {
        case 117:
            // REGEX ublic Start at 117
            if (!nextCharIs(this,98)) {
                return 0;
            }
            if (!nextCharIs(this,108)) {
                return 0;
            }
            if (!nextCharIs(this,105)) {
                return 0;
            }
            if (!nextCharIs(this,99)) {
                return 0;
            }
            ///////////
            if (!nextCharInline(this)) {
                return 0;
            }
            printf("-- Public \n");
            return f(this);
            break;
        case 114:
            // REGEX rivate Start at 114
            if (!nextCharIs(this,105)) {
                return 0;
            }
            if (!nextCharIs(this,118)) {
                return 0;
            }
            if (!nextCharIs(this,97)) {
                return 0;
            }
            if (!nextCharIs(this,116)) {
                return 0;
            }
            if (!nextCharIs(this,101)) {
                return 0;
            }

            ///////////
            
            if (!nextCharInline(this)) {
                return 0;
            }
            printf("-- Private \n");
            return f(this);
            break;
        default:
            return 0;
    }
    return 0;
}

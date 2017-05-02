#include <stdio.h>

int RegexStartFuncOrImplements(struct sequenceRegex * this) {
    while (1) {
        switch (fgetc(this->fp)) {
            case 32:
                break;
            case 23:
                break;
            case 105:
                return 1;
            case 123:
                return 3;
            default:
                return 0;
        }
    }  
}

int RegexStartFuncOrImplementsOrExtends(struct sequenceRegex * this) {
    while (1) {
        switch (fgetc(this->fp)) {
            case 32:
                break;
            case 23:
                break;
            case 105:
                return 1;
            case 101:
                return 2;
            case 123:
                return 3;
            default:
                return 0;
        }
    }
}

int RegexExtends(struct sequenceRegex * this) {

    // REGEX CONSTRUCT Start at 101

    if (!nextCharIs(this, 120)) {
        return 0;
    }
    if (!nextCharIs(this, 116)) {
        return 0;
    }
    if (!nextCharIs(this, 101)) {
        return 0;
    }
    if (!nextCharIs(this, 110)) {
        return 0;
    }
    if (!nextCharIs(this, 100)) {
        return 0;
    }
    if (!nextCharIs(this, 115)) {
        return 0;
    }
    if (!RegexJumpSpace(this)) {
        return 0;
    }

    return RegexNotSpaceInlineOrFuncStart(this);
}

int RegexImplements(struct sequenceRegex * this) {

    // REGEX CONSTRUCT Start at 105

    if (!nextCharIs(this, 109)) {
        return 0;
    }
    if (!nextCharIs(this, 112)) {
        return 0;
    }
    if (!nextCharIs(this, 108)) {
        return 0;
    }
    if (!nextCharIs(this, 101)) {
        return 0;
    }
    if (!nextCharIs(this, 109)) {
        return 0;
    }
    if (!nextCharIs(this, 101)) {
        return 0;
    }
    if (!nextCharIs(this, 110)) {
        return 0;
    }
    if (!nextCharIs(this, 116)) {
        return 0;
    }
    if (!nextCharIs(this, 115)) {
        return 0;
    }
    if (!RegexJumpSpace(this)) {
        return 0;
    }
    return RegexNotSpaceInlineOrFuncStart(this);
}

int RegexExtendsImplements(struct sequenceRegex * this){
    switch (RegexStartFuncOrImplementsOrExtends(this)) {
        case 0:
            return 0;
        case 1:
            switch (RegexImplements(this)) {
                case 0:
                    return 0;
                case 1:
                    if (!RegexFuncStart(this)) {
                        return 0;
                    }
            }
            break;
        case 2:
            switch (RegexExtends(this)) {
                case 0:
                    return 0;
                case 1:
                    switch (RegexStartFuncOrImplements(this)) {
                        case 1:
                            switch (RegexImplements(this)) {
                                case 0:
                                    return 0;
                                case 1:
                                    if (!RegexFuncStart(this)) {
                                        return 0;
                                    }   
                            }
                            break;
                        case 0:
                            return 0;
                    }
                    break;
            }
            break;
    }
    return 1;
}
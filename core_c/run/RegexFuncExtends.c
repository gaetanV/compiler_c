#include <stdio.h>

int RegexExtends(struct sequenceRegex * this) {

    // REGEX Extends Start at 101
    if (fgetc(this->fp) != 120) {
        return 0;
    }
    if (fgetc(this->fp) != 116) {
        return 0;
    }
    if (fgetc(this->fp) != 101) {
        return 0;
    }
    if (fgetc(this->fp) != 110) {
        return 0;
    }
    if (fgetc(this->fp) != 100) {
        return 0;
    }
    if (fgetc(this->fp) != 115) {
        return 0;
    }


    if (!RegexJumpSpace(this)) {
        return 0;
    }
  
    return RegexMemoryNotSpaceInlineOrFuncStart(this);
}

int RegexImplements(struct sequenceRegex * this) {


    // REGEX Implements Start at 105
    if (fgetc(this->fp) != 109) {
        return 0;
    }
    if (fgetc(this->fp) != 112) {
        return 0;
    }
    if (fgetc(this->fp) != 108) {
        return 0;
    }
    if (fgetc(this->fp) != 101) {
        return 0;
    }
    if (fgetc(this->fp) != 109) {
        return 0;
    }
    if (fgetc(this->fp) != 101) {
        return 0;
    }

    if (fgetc(this->fp) != 110) {
        return 0;
    }
    if (fgetc(this->fp) != 116) {
        return 0;
    }
    if (fgetc(this->fp) != 115) {
        return 0;
    }

    if (!RegexJumpSpace(this)) {
        return 0;
    }
 
    return RegexMemoryNotSpaceInlineOrFuncStart(this);
}

int RegexExtendsImplements(struct sequenceRegex * this) {
    while (1) {
        switch (fgetc(this->fp)) {
            case 32:
                break;
            case 23:
                break;
            case 105:
                goto implements;
            case 101:
                switch (RegexExtends(this)) {
                    case 0:
                        return 0;
                    case 1:
                        while (1) {
                            switch (fgetc(this->fp)) {
                                case 32:
                                    break;
                                case 23:
                                    break;
                                case 105:
                                    goto implements;
                                case 123:
                                    return 1;
                                default:
                                    return 0;
                            }
                        }
                }
                break;
            case 123:
                return 1;
            default:
                return 0;
        }
    }

implements:
    switch (RegexImplements(this)) {
        case 0:
            return 0;
        case 1:
            while (1) {
                 // Function start
                switch (fgetc(this->fp)) {
                    case 32:
                        break;
                    case 23:
                        break;
                    case 123:
                        return 1;
                    default:
                        return 0;
                }
            }
    }
}

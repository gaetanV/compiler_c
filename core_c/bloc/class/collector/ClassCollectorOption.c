/**
@ERROR
 */
void ErrorCollectorExtends(struct Buffer * this) {
    Error(this, "Class format extends");
}

void ErrorCollectorImplements(struct Buffer * this) {
    Error(this, "Class format implements");
}

void ErrorCollectorClass(struct Buffer * this) {
    Error(this, "Class format");
}

/**
@DEFINE
 */
// REGEX Extends Start at 101
#define _ExtendsStart(this)\
    if (fgetc(this->fp) != 120) { ErrorCollectorExtends(this); }\
    if (fgetc(this->fp) != 116) { ErrorCollectorExtends(this); }\
    if (fgetc(this->fp) != 101) { ErrorCollectorExtends(this); }\
    if (fgetc(this->fp) != 110) { ErrorCollectorExtends(this); }\
    if (fgetc(this->fp) != 100) { ErrorCollectorExtends(this); }\
    if (fgetc(this->fp) != 115) { ErrorCollectorExtends(this); }\
    RegexStrictSpaces(this);\
    Memory(this);\


 // REGEX Implements Start at 105
#define _ImplementsStart(this) \
    if (fgetc(this->fp) != 109) { ErrorCollectorImplements(this); }\
    if (fgetc(this->fp) != 112) { ErrorCollectorImplements(this); }\
    if (fgetc(this->fp) != 108) { ErrorCollectorImplements(this); }\
    if (fgetc(this->fp) != 101) { ErrorCollectorImplements(this); }\
    if (fgetc(this->fp) != 109) { ErrorCollectorImplements(this); }\
    if (fgetc(this->fp) != 101) { ErrorCollectorImplements(this); }\
    if (fgetc(this->fp) != 110) { ErrorCollectorImplements(this); }\
    if (fgetc(this->fp) != 116) { ErrorCollectorImplements(this); }\
    if (fgetc(this->fp) != 115) { ErrorCollectorImplements(this); }\
    RegexStrictSpaces(this);\
    MemoryMap(this);\

/**
@@@@@@@
*/
void CollectorExtendsImplements(struct Buffer * this, bool * hasExtends, bool * hasImplements) {

    if (this->ch == 123) {
        return;
    }
    while (1) {
        switch (fgetc(this->fp)) {
            case 32:
                break;
            case 23:
                break;
            case 105:
                *hasExtends = 0;
                goto implements;
            case 101:
                _ExtendsStart(this);
                *hasExtends = 1;
                while (1) {
                    switch (this->ch = fgetc(this->fp)) {
                        case EOF:
                            ErrorCollectorExtends(this);
                        case 10:
                            ErrorCollectorExtends(this);
                        case 59:
                            ErrorCollectorExtends(this);
                        case 32:
                            while (1) {
                                switch (fgetc(this->fp)) {
                                    case 32:
                                        break;
                                    case 23:
                                    case 105:
                                        goto implements;
                                        break;
                                    case 123:
                                        MemoryMap(this);
                                        return;
                                    default:
                                        ErrorCollectorExtends(this);
                                }
                            }
                        case 123:
                            return;
                        default:
                            Memory(this);
                            break;
                    }
                }

                break;
            case 123:
                *hasExtends = 0;
                *hasImplements = 0;
                return;
            default:
                ErrorCollectorClass(this);
        }
    }

implements:
    _ImplementsStart(this);
    *hasImplements = 1;
    while (1) {
        switch (this->ch = fgetc(this->fp)) {
            case EOF:
                ErrorCollectorImplements(this);
            case 10:
                ErrorCollectorImplements(this);
            case 59:
                ErrorCollectorImplements(this);
            case 32:
                while (1) {
                    // Function start
                    switch (fgetc(this->fp)) {
                        case 32:
                            break;
                        case 23:
                            break;
                        case 123:
                     return;
                        default:
                            ErrorCollectorImplements(this);
                    }
                }
            case 123:
                 return;
            default:
                Memory(this);
                break;
        }
    }

    

}

void CollectorExtends(struct Buffer * this, bool * hasExtends) {

    if (this->ch == 123) {
        goto endFuncFalse;
    }

    while (1) {
        switch (fgetc(this->fp)) {
            case 32:
                break;
            case 23:
                break;
            case 101:
                _ExtendsStart(this);
                while (1) {
                    switch (this->ch = fgetc(this->fp)) {
                        case EOF:
                            ErrorCollectorExtends(this);
                        case 10:
                            ErrorCollectorExtends(this);
                        case 59:
                            ErrorCollectorExtends(this);
                        case 32:
                            while (1) {
                                switch (fgetc(this->fp)) {
                                    case 32:
                                        break;
                                    case 23:
                                        break;
                                    case 123:
                                        goto extendsEnd;
                                    default:
                                        ErrorCollectorExtends(this);
                                }
                            }
                        case 123:
                            goto extendsEnd;
                        default:
                            Memory(this);
                            break;
                    }
                }
            case 123:
                goto endFuncFalse;
            default:
                ErrorCollectorClass(this);
        }
        this->ch = fgetc(this->fp);
    }
endFuncFalse:
    *hasExtends = 0;
    MemoryMap(this);
    return;

extendsEnd:
    *hasExtends = 1;
    MemoryMap(this);
    return;



}

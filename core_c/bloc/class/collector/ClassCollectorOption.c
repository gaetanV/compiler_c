
void _ExtendsStart(struct Buffer * this) {

    // REGEX Extends Start at 101
    if (fgetc(this->fp) != 120) {
        goto extendsError;
    }
    if (fgetc(this->fp) != 116) {
        goto extendsError;
    }
    if (fgetc(this->fp) != 101) {
        goto extendsError;
    }
    if (fgetc(this->fp) != 110) {
        goto extendsError;
    }
    if (fgetc(this->fp) != 100) {
        goto extendsError;
    }
    if (fgetc(this->fp) != 115) {
        goto extendsError;
    }
    RegexStrictSpaces(this);

    Memory(this);
    return;
extendsError:
    Error(this, "class format extends");
}

void _Implements(struct Buffer * this) {

    // REGEX Implements Start at 105
    if (fgetc(this->fp) != 109) {
        goto implementsError;
    }
    if (fgetc(this->fp) != 112) {
        goto implementsError;
    }
    if (fgetc(this->fp) != 108) {
        goto implementsError;
    }
    if (fgetc(this->fp) != 101) {
        goto implementsError;
    }
    if (fgetc(this->fp) != 109) {
        goto implementsError;
    }
    if (fgetc(this->fp) != 101) {
        goto implementsError;
    }

    if (fgetc(this->fp) != 110) {
        goto implementsError;
    }
    if (fgetc(this->fp) != 116) {
        goto implementsError;
    }
    if (fgetc(this->fp) != 115) {
        goto implementsError;
    }

    RegexStrictSpaces(this);

    /// NotSpaceInlineOrFuncStart
    Memory(this);
    while (1) {
        switch (this->ch = fgetc(this->fp)) {
            case EOF:
                goto implementsError;
            case 10:
                goto implementsError;
            case 59:
                goto implementsError;
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
                            goto implementsError;
                    }
                }
            case 123:
                return;
            default:
                Memory(this);
                break;
        }
    }


implementsError:
    Error(this, "class format implements");


}

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
                            goto extendsError;
                        case 10:
                            goto extendsError;
                        case 59:
                            goto extendsError;
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
                                        goto extendsEnd;
                                    default:
                                        goto extendsError;
                                }
                            }
                        case 123:
                            goto endFuncFalse;
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
                goto extendsError;
        }
    }

implements:
    _Implements(this);
    *hasImplements = 1;
    MemoryMap(this);
    return;

extendsEnd:
    MemoryMap(this);
    return;
    
endFuncFalse:
    return;
implementsError:
    Error(this, "class format implements");


extendsError:
    Error(this, "class format extends");

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
                            goto extendsError;
                        case 10:
                            goto extendsError;
                        case 59:
                            goto extendsError;
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
                                        goto extendsError;
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
                goto extendsEnd;
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

extendsError:
    Error(this, "class format extends");


}

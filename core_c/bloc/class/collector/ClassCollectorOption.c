
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


void _Implements(struct Buffer * this, struct ClassCollector * collector) {

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
                            goto implementsEnd;
                        default:
                            goto implementsError;
                    }
                }
            case 123:
                goto implementsEnd;
            default:
                Memory(this);
                break;
        }
    }


implementsError:
    Error(this, "class format implements");

implementsEnd:
    collector->module[2] = 1;
    MemoryMap(this);
    return;

}

void CollectorExtendsImplements(struct Buffer * this, struct ClassCollector * collector) {

    if (this->ch == 123) {
        collector->module[1] = 0;
        collector->module[2] = 0;
        return;
    }
    while (1) {
        switch (fgetc(this->fp)) {
            case 32:
                break;
            case 23:
                break;
            case 105:
                collector->module[1] = 0;
                goto implements;
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
                collector->module[1] = 0;
                collector->module[2] = 0;
                return;
            default:
                goto extendsError;
        }
    }

implements:
    _Implements(this, collector);
    return;

extendsEnd:
    collector->module[1] = 1;
    MemoryMap(this);
    return;
endFuncFalse:
   return;         
implementsError:
    Error(this, "class format implements");


extendsError:
    Error(this, "class format extends");



}

void CollectorExtends(struct Buffer * this, struct ClassCollector * collector) {

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
    collector->module[1] = 0;
    MemoryMap(this);
    return;

extendsEnd:
    collector->module[1] = 1;
    MemoryMap(this);
    return;

extendsError:
    Error(this, "class format extends");


}

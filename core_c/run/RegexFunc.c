#include <stdbool.h>

/**
@ERROR
 */
void ErrorFuncArgs(struct Buffer * this) {
    Error(this, "Function arguments ");
}

void ErrorFuncArgsType(struct Buffer * this) {
    Error(this, "Function arguments type");
}

void ErrorFunc(struct Buffer * this) {
    Error(this, "Function format");
}

void ErrorFuncInner(struct Buffer * this) {
    Error(this, "Function inner");
}

/**
@@@@@@@
 */
void RegexMemoryFuncInner(struct Buffer * this) {

    // Function Start
    while (1) {
        switch (fgetc(this->fp)) {
            case 32:
                break;
            case 23:
                break;
            case 123:
                this->c = 1;
                while (1) {
                    switch (this->ch = fgetc(this->fp)) {
                        case EOF:
                            ErrorFuncInner(this);
                        case 47:
                            switch (this->ch = fgetc(this->fp)) {
                                case 47:
                                    RegexForceEmptyLigne(this);
                                    break;
                                case 42:
                                    RegexCommentBloc(this);
                                    break;
                                default:
                                    MemoryChar(this, 47);
                                    Memory(this);
                                    break;
                            }
                            break;
                        case 123:
                            Memory(this);
                            this->c++;
                            break;
                        case 125:
                            this->c--;
                            if (this->c <= 0) {
                                return;
                            }
                            Memory(this);
                            break;
                        default:
                            Memory(this);
                            break;
                    }
                }
            default:
                ErrorFuncInner(this);
        }
    }
    // Function Stop


}

void RegexFuncArgsInner(struct Buffer * this) {

    this->_cmp = 0;

    while (1) {
step1:
        switch (this->ch = fgetc(this->fp)) {
            case EOF:
                ErrorFunc(this);
            case 32:
                break;
            case 41:
                goto end;
            default:
                if (this->_cmp != 0) {
                    MemoryMap(this);
                }
                this->_cmp++;
                Memory(this);
                while (1) {
                    switch (this->ch = fgetc(this->fp)) {
                        case EOF:
                            ErrorFuncArgs(this);
                        case 41:
                            goto end;
                        case 44:
                            goto step1;
                        case 32:
                            while (1) {
                                switch (this->ch = fgetc(this->fp)) {
                                    case EOF:
                                        ErrorFuncArgs(this);
                                    case 41:
                                        goto end;
                                    case 44:
                                        goto step1;
                                    default:
                                        ErrorFuncArgs(this);
                                }
                            }
                            break;
                        default:
                            Memory(this);
                            break;
                    }
                }
                break;
        }
    }
end:
    if (this->_cmp != 0) {
        MemoryMap(this);
    }
    // Args Stop
    RegexMemoryFuncInner(this);
    return;


}

void RegexFuncArgsTypeInner(struct Buffer * this, int * typePointer, bool * type) {

    this->_cmp = 0;


    while (1) {
step1:
        switch (this->ch = fgetc(this->fp)) {
            case EOF:
                ErrorFunc(this);
            case 41:
                goto endEmpty;
            case 32:
                break;
            default:
                if (this->_cmp != 0) {
                    MemoryMap(this);
                }
                this->_cmp++;
                type[* typePointer] = 0;
                * typePointer = *typePointer + 1;
                Memory(this);
                while (1) {
                    switch (this->ch = fgetc(this->fp)) {
                        case EOF:
                            ErrorFuncArgsType(this);
                        case 41:
                            goto end;
                        case 44:
                            goto step1;
                            break;
                        case 32:
                            while (1) {
                                switch (this->ch = fgetc(this->fp)) {
                                    case EOF:
                                        ErrorFuncArgsType(this);
                                    case 41:
                                        goto end;
                                    case 44:
                                        goto step1;
                                    default:
                                        type[* typePointer - 1 ] = 1;
                                        MemoryMap(this);
                                        Memory(this);
                                        while (1) {
                                            switch (this->ch = fgetc(this->fp)) {
                                                case EOF:
                                                    ErrorFuncArgsType(this);
                                                case 41:
                                                    goto end;
                                                case 44:
                                                    goto step1;
                                                    break;
                                                case 32:
                                                    while (1) {
                                                        switch (this->ch = fgetc(this->fp)) {
                                                            case 41:
                                                                goto end;
                                                            case 44:
                                                                goto step1;
                                                                break;
                                                            case 32:
                                                                break;
                                                            default:
                                                                ErrorFuncArgsType(this);
                                                        }
                                                    }
                                                    break;
                                                default:
                                                    Memory(this);
                                                    break;
                                            }
                                        }
                                        break;
                                }
                            }
                        default:
                            Memory(this);
                            break;
                    }
                }
                break;
        }
    }


end:
    MemoryMap(this);
    RegexMemoryFuncInner(this);
    return;
endEmpty:
    RegexMemoryFuncInner(this);
    return;

}

void RegexFuncArgsStrictTypeInner(struct Buffer * this) {

    this->_cmp = 0;
    while (1) {
step1:
        switch (this->ch = fgetc(this->fp)) {
            case EOF:
                ErrorFunc(this);
            case 41:
                goto end;
            case 32:
                break;
            default:
                if (this->_cmp != 0) {
                    MemoryMap(this);
                }
                this->_cmp++;
                Memory(this);
                while (1) {
                    switch (this->ch = fgetc(this->fp)) {
                        case EOF:
                            ErrorFuncArgsType(this);
                        case 41:
                            ErrorFuncArgsType(this);
                        case 44:
                            ErrorFuncArgsType(this);
                            break;
                        case 32:
                            while (1) {
                                switch (this->ch = fgetc(this->fp)) {
                                    case EOF:
                                        ErrorFuncArgsType(this);
                                    case 41:
                                        ErrorFuncArgsType(this);
                                    case 44:
                                        ErrorFuncArgsType(this);
                                    default:
                                        MemoryMap(this);
                                        Memory(this);
                                        while (1) {
                                            switch (this->ch = fgetc(this->fp)) {
                                                case EOF:
                                                    ErrorFuncArgsType(this);
                                                case 41:
                                                    MemoryMap(this);
                                                    goto end;
                                                case 44:
                                                    goto step1;
                                                    break;
                                                case 32:
                                                    while (1) {
                                                        switch (this->ch = fgetc(this->fp)) {
                                                            case 41:
                                                                MemoryMap(this);
                                                                goto end;
                                                            case 44:
                                                                goto step1;
                                                                break;
                                                            case 32:
                                                                break;
                                                            default:
                                                                ErrorFuncArgsType(this);
                                                        }
                                                    }
                                                    break;
                                                default:
                                                    Memory(this);
                                                    break;
                                            }
                                        }

                                        break;
                                }
                            }
                        default:
                            Memory(this);
                            break;
                    }
                }
                break;
        }
    }

end:
    RegexMemoryFuncInner(this);
    return;


}


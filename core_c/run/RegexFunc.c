#include <stdbool.h>

/**
@ERROR
 */
void ErrorFuncArgs(struct Buffer * buffer) {
    Error(buffer, "Function arguments ");
}

void ErrorFuncArgsType(struct Buffer * buffer) {
    Error(buffer, "Function arguments type");
}

void ErrorFunc(struct Buffer * buffer) {
    Error(buffer, "Function format");
}

void ErrorFuncInner(struct Buffer * buffer) {
    Error(buffer, "Function inner");
}

/**
@@@@@@@
 */
void RegexMemoryFuncInner(struct Buffer * buffer) {

    // Function Start
    while (1) {
        switch (fgetc(buffer->fp)) {
            case 32:
                break;
            case 23:
                break;
            case 123:
                buffer->c = 1;
                while (1) {
                    switch (buffer->ch = fgetc(buffer->fp)) {
                        case EOF:
                            ErrorFuncInner(buffer);
                        case 47:
                            switch (buffer->ch = fgetc(buffer->fp)) {
                                case 47:
                                    RegexForceEmptyLigne(buffer);
                                    break;
                                case 42:
                                    RegexCommentBloc(buffer);
                                    break;
                                default:
                                    MemoryChar(buffer, 47);
                                    Memory(buffer);
                                    break;
                            }
                            break;
                        case 123:
                            Memory(buffer);
                            buffer->c++;
                            break;
                        case 125:
                            buffer->c--;
                            if (buffer->c <= 0) {
                                return;
                            }
                            Memory(buffer);
                            break;
                        default:
                            Memory(buffer);
                            break;
                    }
                }
            default:
                ErrorFuncInner(buffer);
        }
    }
    // Function Stop


}

void RegexFuncArgsInner(struct Buffer * buffer) {

    buffer->_cmp = 0;

    while (1) {
step1:
        switch (buffer->ch = fgetc(buffer->fp)) {
            case EOF:
                ErrorFunc(buffer);
            case 32:
                break;
            case 41:
                goto end;
            default:
                if (buffer->_cmp != 0) {
                    MemoryMap(buffer);
                }
                buffer->_cmp++;
                Memory(buffer);
                while (1) {
                    switch (buffer->ch = fgetc(buffer->fp)) {
                        case EOF:
                            ErrorFuncArgs(buffer);
                        case 41:
                            goto end;
                        case 44:
                            goto step1;
                        case 32:
                            while (1) {
                                switch (buffer->ch = fgetc(buffer->fp)) {
                                    case EOF:
                                        ErrorFuncArgs(buffer);
                                    case 41:
                                        goto end;
                                    case 44:
                                        goto step1;
                                    default:
                                        ErrorFuncArgs(buffer);
                                }
                            }
                            break;
                        default:
                            Memory(buffer);
                            break;
                    }
                }
                break;
        }
    }
end:
    if (buffer->_cmp != 0) {
        MemoryMap(buffer);
    }
    // Args Stop
    RegexMemoryFuncInner(buffer);
    return;


}

void RegexFuncArgsTypeInner(struct Buffer * buffer, int * typePointer, bool * type) {

    buffer->_cmp = 0;


    while (1) {
step1:
        switch (buffer->ch = fgetc(buffer->fp)) {
            case EOF:
                ErrorFunc(buffer);
            case 41:
                goto endEmpty;
            case 32:
                break;
            default:
                if (buffer->_cmp != 0) {
                    MemoryMap(buffer);
                }
                buffer->_cmp++;
                type[* typePointer] = 0;
                * typePointer = *typePointer + 1;
                Memory(buffer);
                while (1) {
                    switch (buffer->ch = fgetc(buffer->fp)) {
                        case EOF:
                            ErrorFuncArgsType(buffer);
                        case 41:
                            goto end;
                        case 44:
                            goto step1;
                            break;
                        case 32:
                            while (1) {
                                switch (buffer->ch = fgetc(buffer->fp)) {
                                    case EOF:
                                        ErrorFuncArgsType(buffer);
                                    case 41:
                                        goto end;
                                    case 44:
                                        goto step1;
                                    default:
                                        type[* typePointer - 1 ] = 1;
                                        MemoryMap(buffer);
                                        Memory(buffer);
                                        while (1) {
                                            switch (buffer->ch = fgetc(buffer->fp)) {
                                                case EOF:
                                                    ErrorFuncArgsType(buffer);
                                                case 41:
                                                    goto end;
                                                case 44:
                                                    goto step1;
                                                    break;
                                                case 32:
                                                    while (1) {
                                                        switch (buffer->ch = fgetc(buffer->fp)) {
                                                            case 41:
                                                                goto end;
                                                            case 44:
                                                                goto step1;
                                                                break;
                                                            case 32:
                                                                break;
                                                            default:
                                                                ErrorFuncArgsType(buffer);
                                                        }
                                                    }
                                                    break;
                                                default:
                                                    Memory(buffer);
                                                    break;
                                            }
                                        }
                                        break;
                                }
                            }
                        default:
                            Memory(buffer);
                            break;
                    }
                }
                break;
        }
    }


end:
    MemoryMap(buffer);
    RegexMemoryFuncInner(buffer);
    return;
endEmpty:
    RegexMemoryFuncInner(buffer);
    return;

}

void RegexFuncArgsStrictTypeInner(struct Buffer * buffer) {

    buffer->_cmp = 0;
    while (1) {
step1:
        switch (buffer->ch = fgetc(buffer->fp)) {
            case EOF:
                ErrorFunc(buffer);
            case 41:
                goto end;
            case 32:
                break;
            default:
                if (buffer->_cmp != 0) {
                    MemoryMap(buffer);
                }
                buffer->_cmp++;
                Memory(buffer);
                while (1) {
                    switch (buffer->ch = fgetc(buffer->fp)) {
                        case EOF:
                            ErrorFuncArgsType(buffer);
                        case 41:
                            ErrorFuncArgsType(buffer);
                        case 44:
                            ErrorFuncArgsType(buffer);
                            break;
                        case 32:
                            while (1) {
                                switch (buffer->ch = fgetc(buffer->fp)) {
                                    case EOF:
                                        ErrorFuncArgsType(buffer);
                                    case 41:
                                        ErrorFuncArgsType(buffer);
                                    case 44:
                                        ErrorFuncArgsType(buffer);
                                    default:
                                        MemoryMap(buffer);
                                        Memory(buffer);
                                        while (1) {
                                            switch (buffer->ch = fgetc(buffer->fp)) {
                                                case EOF:
                                                    ErrorFuncArgsType(buffer);
                                                case 41:
                                                    MemoryMap(buffer);
                                                    goto end;
                                                case 44:
                                                    goto step1;
                                                    break;
                                                case 32:
                                                    while (1) {
                                                        switch (buffer->ch = fgetc(buffer->fp)) {
                                                            case 41:
                                                                MemoryMap(buffer);
                                                                goto end;
                                                            case 44:
                                                                goto step1;
                                                                break;
                                                            case 32:
                                                                break;
                                                            default:
                                                                ErrorFuncArgsType(buffer);
                                                        }
                                                    }
                                                    break;
                                                default:
                                                    Memory(buffer);
                                                    break;
                                            }
                                        }

                                        break;
                                }
                            }
                        default:
                            Memory(buffer);
                            break;
                    }
                }
                break;
        }
    }

end:
    RegexMemoryFuncInner(buffer);
    return;


}


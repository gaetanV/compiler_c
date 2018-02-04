/**
@ERROR
 */
void ErrorCollectorFunc(struct Buffer * buffer) {
    Error(buffer, "Class function");
}

void ErrorCollectorAttr(struct Buffer * buffer) {
    Error(buffer, "Class function attributes");
}

/**
@@@@@@@
 */
void CollectorFuncNameArgs(struct Buffer * buffer, int * funcPointer, int * funcType) {
    while (1) {
        switch (buffer->ch) {
            case EOF:
                ErrorCollectorFunc(buffer);
            case 10:
                ErrorCollectorFunc(buffer);
            case 59:
                ErrorCollectorFunc(buffer);
            case 32:
                while (1) {
                    switch (fgetc(buffer->fp)) {
                        default:
                            ErrorCollectorFunc(buffer);
                        case 32:
                            break;
                        case 40:
                            goto endFunc;
                    }
                }
                break;
            case 40:
                goto endFunc;
            default:
                Memory(buffer);
                break;
        }
        buffer->ch = fgetc(buffer->fp);
    }

endFunc:
    funcType[*funcPointer] = buffer->_pointer - 1;
    MemoryMap(buffer);
    // Parenthesize start
    RegexFuncArgsInner(buffer);
    *funcPointer = *funcPointer + 1;
    funcType[*funcPointer] = buffer->_cmp;
    *funcPointer = *funcPointer + 1;
    MemoryMap(buffer);
    return;

}

void CollectorFuncNameArgsOrAttr(struct Buffer * buffer, int * funcPointer, int * funcType, int * attrPointer, int * attrType) {
    while (1) {
        switch (buffer->ch) {
            case EOF:
                ErrorCollectorFunc(buffer);
            case 10:
                ErrorCollectorFunc(buffer);
            case 59:
                goto endFuncAttr;
            case 32:
                while (1) {
                    switch (fgetc(buffer->fp)) {
                        default:
                            goto endFuncAttr;
                        case 32:
                            break;
                        case 40:
                            goto endFunc;
                    }
                }
                break;
            case 40:
                goto endFunc;
            default:
                Memory(buffer);
                break;
        }
        buffer->ch = fgetc(buffer->fp);
    }

endFunc:
    funcType[*funcPointer] = buffer->_pointer - 1;
    MemoryMap(buffer);
    // Parenthesize start
    RegexFuncArgsInner(buffer);
    *funcPointer = *funcPointer + 1;
    funcType[* funcPointer] = buffer->_cmp;
    *funcPointer = *funcPointer + 1;
    MemoryMap(buffer);
    return;

endFuncAttr:
    attrType[*attrPointer] = buffer->_pointer - 1;
    *attrPointer = *attrPointer + 1;

    while (1) {
        switch (buffer->ch = fgetc(buffer->fp)) {
            case 32:
                break;
            case 10:
                MemoryMap(buffer);
                return;
            default:
                ErrorCollectorFunc(buffer);
        }

    }


}

void CollectorFuncNameArgsOrAttrStrictType(struct Buffer * buffer, int * funcPointer, int * funcType, int * attrPointer, int * attrType) {
    while (1) {
        switch (buffer->ch) {
            case EOF:
                ErrorCollectorFunc(buffer);
            case 10:
                ErrorCollectorFunc(buffer);
            case 59:
                ErrorCollectorFunc(buffer);
            case 58:
                goto endFuncAttr;
            case 32:
                while (1) {
                    switch (fgetc(buffer->fp)) {
                        default:
                            ErrorCollectorFunc(buffer);
                        case 58:
                            goto endFuncAttr;
                        case 32:
                            break;
                        case 40:
                            goto endFunc;
                    }
                }
                break;
            case 40:
                goto endFunc;
            default:
                Memory(buffer);
                break;
        }
        buffer->ch = fgetc(buffer->fp);
    }

endFunc:
    funcType[*funcPointer] = buffer->_pointer - 1;
    MemoryMap(buffer);
    // Parenthesize start
    RegexFuncArgsStrictTypeInner(buffer);
    *funcPointer = *funcPointer + 1;
    funcType[* funcPointer] = buffer->_cmp;
    *funcPointer = *funcPointer + 1;
    MemoryMap(buffer);
    return;

endFuncAttr:
    attrType[*attrPointer] = buffer->_pointer - 1;
    *attrPointer = *attrPointer + 1;
    MemoryMap(buffer);
    while (1) {
        switch (buffer->ch = fgetc(buffer->fp)) {
            case 32:
                while (1) {
                    switch (buffer->ch = fgetc(buffer->fp)) {
                        default:
                            Memory(buffer);
                            while (1) {
                                switch (buffer->ch = fgetc(buffer->fp)) {
                                    case 10:
                                    case 32:
                                        while (1) {
                                            switch (buffer->ch = fgetc(buffer->fp)) {
                                                case 32:
                                                    break;
                                                case 59:
                                                    MemoryMap(buffer);
                                                    return;
                                                default:
                                                    ErrorCollectorAttr(buffer);
                                            }
                                        }
                                    case 59:
                                        MemoryMap(buffer);
                                        return;
                                    default:
                                        Memory(buffer);
                                        break;
                                    case 58:
                                        ErrorCollectorAttr(buffer);
                                }
                            }
                        case 10:
                        case 59:
                            MemoryMap(buffer);
                            return;
                        case 32:
                            break;
                    }
                }
                break;
            case 10:
            case 59:
                MemoryMap(buffer);
                return;
            default:
                Memory(buffer);
                break;
            case 58:
                ErrorCollectorAttr(buffer);
        }

    }




}




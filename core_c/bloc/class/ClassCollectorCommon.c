void CollectorFuncNameArgs(struct sequenceRegex * this, int * funcPointer, int * funcType) {
    while (1) {
        switch (this->ch) {
            case EOF:
                goto endError;
            case 10:
                goto endError;
            case 59:
                goto endError;
            case 32:
                while (1) {
                    switch (fgetc(this->fp)) {
                        default:
                            goto endError;
                        case 32:
                            break;
                        case 40:
                            funcType[*funcPointer] = this->_pointer - 1;
                            MemoryMap(this);
                            // Parenthesize start
                            if (RegexFuncArgsInner(this)) {
                                goto endFunc;

                            } else {
                                goto endError;
                            }
                    }
                }
                break;
            case 40:
                funcType[*funcPointer] = this->_pointer - 1;
                MemoryMap(this);
                // Parenthesize start
                if (RegexFuncArgsInner(this)) {

                    goto endFunc;

                } else {
                    goto endError;
                }
                break;
            default:
                Memory(this);
                break;
        }
        this->ch = fgetc(this->fp);
    }

endFunc:
    *funcPointer = *funcPointer + 1;
    funcType[*funcPointer] = this->_cmp;
    *funcPointer = *funcPointer + 1;
    MemoryMap(this);
    return;

endError:
    printf("Error in class format function \n");
    exit(0);
}

void CollectorFuncNameArgsOrAttr(struct sequenceRegex * this, int * funcPointer, int * funcType, int * attrPointer, int * attrType) {
    while (1) {
        switch (this->ch) {
            case EOF:
                goto endError;
            case 10:
                goto endError;
            case 59:
                goto endFuncAttr;
            case 32:
                while (1) {
                    switch (fgetc(this->fp)) {
                        default:
                            goto endFuncAttr;
                        case 32:
                            break;
                        case 40:
                            funcType[*funcPointer] = this->_pointer - 1;
                            MemoryMap(this);
                            // Parenthesize start
                            if (RegexFuncArgsInner(this)) {
                                goto endFunc;
                            } else {
                                goto endError;
                            }
                    }
                }
                break;
            case 40:
                funcType[*funcPointer] = this->_pointer - 1;
                MemoryMap(this);
                // Parenthesize start
                if (RegexFuncArgsInner(this)) {
                    goto endFunc;
                } else {
                    goto endError;
                }

            default:
                Memory(this);
                break;
        }
        this->ch = fgetc(this->fp);
    }

endFunc:
    *funcPointer = *funcPointer + 1;
    funcType[* funcPointer] = this->_cmp;
    *funcPointer = *funcPointer + 1;
    MemoryMap(this);
    return;

endFuncAttr:
    attrType[*attrPointer] = this->_pointer - 1;
    *attrPointer = *attrPointer + 1;

    while (1) {
        switch (this->ch = fgetc(this->fp)) {
            case 32:
                break;
            case 10:
                MemoryMap(this);
                return;
            default:
                goto endError;
        }

    }

endError:
    printf("Error in class format function \n");
    exit(0);

}


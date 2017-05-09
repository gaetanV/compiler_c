void CollectorFuncNameArgs(struct Buffer * this, int * funcPointer, int * funcType) {

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
                            RegexFuncArgsInner(this);
                            goto endFunc;
                    }
                }
                break;
            case 40:

                funcType[*funcPointer] = this->_pointer - 1;
                MemoryMap(this);
                // Parenthesize start
                RegexFuncArgsInner(this);
                goto endFunc;

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
    Error(this, "class format function");

}

void CollectorFuncNameArgsOrAttr(struct Buffer * this, int * funcPointer, int * funcType, int * attrPointer, int * attrType) {
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
                            RegexFuncArgsInner(this);
                            goto endFunc;
                    }
                }
                break;
            case 40:
                funcType[*funcPointer] = this->_pointer - 1;
                MemoryMap(this);
                // Parenthesize start
                RegexFuncArgsInner(this);
                goto endFunc;

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
    Error(this, "class format function");

}

void CollectorFuncNameArgsOrAttrStrictType(struct Buffer * this, int * funcPointer, int * funcType, int * attrPointer, int * attrType) {
    while (1) {
        switch (this->ch) {
            case EOF:
                goto endError;
            case 10:
                goto endError;
            case 59:
                goto endError;
            case 58:
                goto endFuncAttr;
            case 32:
                while (1) {
                    switch (fgetc(this->fp)) {
                        default:
                            goto endError;
                        case 58:
                            goto endFuncAttr;
                        case 32:
                            break;
                        case 40:
                            funcType[*funcPointer] = this->_pointer - 1;
                            MemoryMap(this);
                            // Parenthesize start
                            RegexFuncArgsStrictTypeInner(this);
                            goto endFunc;

                    }
                }
                break;
            case 40:
                funcType[*funcPointer] = this->_pointer - 1;
                MemoryMap(this);
                // Parenthesize start
                RegexFuncArgsStrictTypeInner(this);
                goto endFunc;

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
    MemoryMap(this);
    while (1) {

        switch (this->ch = fgetc(this->fp)) {
            case 32:
                while (1) {
                    switch (this->ch = fgetc(this->fp)) {
                        default:
                            Memory(this);
                            goto endFuncAttr2;
                        case 10:
                        case 59:
                            MemoryMap(this);
                            return;
                        case 32:
                            break;
                    }
                }
                break;
            case 10:
            case 59:
                MemoryMap(this);
                return;
            default:
                Memory(this);
                break;
            case 58:
                goto endFuncAttrError;
                return;
        }

    }
endFuncAttr2:
    while (1) {
        switch (this->ch = fgetc(this->fp)) {
            case 10:
            case 32:
                goto endFuncAttr3;
            case 59:
                MemoryMap(this);
                return;
            default:
                Memory(this);
                break;
            case 58:
                goto endFuncAttrError;
                return;
        }
    }
endFuncAttr3:
    while (1) {
        switch (this->ch = fgetc(this->fp)) {
            case 32:
                break;
            case 59:
                MemoryMap(this);
                return;
            default:
                goto endFuncAttrError;
                return;
        }
    }

endError:
    Error(this, "class format function");

endFuncAttrError:
    Error(this, "class format attribute function");
}




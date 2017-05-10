/**
@ERROR
*/
void ErrorCollectorFunc(struct Buffer * this) {
    Error(this, "Class function");
}

void ErrorCollectorAttr(struct Buffer * this) {
    Error(this, "Class function attributes");
}

/**
@@@@@@@
*/
void CollectorFuncNameArgs(struct Buffer * this, int * funcPointer, int * funcType) {
    while (1) {
        switch (this->ch) {
            case EOF:
                ErrorCollectorFunc(this);
            case 10:
                ErrorCollectorFunc(this);
            case 59:
                ErrorCollectorFunc(this);
            case 32:
                while (1) {
                    switch (fgetc(this->fp)) {
                        default:
                            ErrorCollectorFunc(this);
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
                ErrorCollectorFunc(this);
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


}

void CollectorFuncNameArgsOrAttr(struct Buffer * this, int * funcPointer, int * funcType, int * attrPointer, int * attrType) {
    while (1) {
        switch (this->ch) {
            case EOF:
                ErrorCollectorFunc(this);
            case 10:
                ErrorCollectorFunc(this);
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
                ErrorCollectorFunc(this);
        }

    }


}

void CollectorFuncNameArgsOrAttrStrictType(struct Buffer * this, int * funcPointer, int * funcType, int * attrPointer, int * attrType) {
    while (1) {
        switch (this->ch) {
            case EOF:
                ErrorCollectorFunc(this);
            case 10:
                  ErrorCollectorFunc(this);
            case 59:
                ErrorCollectorFunc(this);
            case 58:
                goto endFuncAttr;
            case 32:
                while (1) {
                    switch (fgetc(this->fp)) {
                        default:
                  ErrorCollectorFunc(this);
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
                ErrorCollectorAttr(this);
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
                ErrorCollectorAttr(this);
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
                ErrorCollectorAttr(this);
                return;
        }
    }



}





void CollectorContructorArgsStrictType(struct sequenceRegex * this, struct ClassCollector * collector) {

    if (collector->module[3] != -1) {
        printf("Error Only one Constructor \n");
        exit(0);
    }
    collector->module[3] = this->_pointer - 1;

    RegexFuncArgsStrictType(this);
    MemoryMap(this);
    collector->module[4] = this->_cmp;

}

void CollectorContructorArgsType(struct sequenceRegex * this, struct ClassCollector * collector) {

    if (collector->module[3] != -1) {
        printf("Error Only one Constructor \n");
        exit(0);
    }
    collector->module[3] = this->_pointer - 1;
    collector->module[5] = collector->_type;

    RegexFuncArgsType(this, &collector->_type, collector->type);
    MemoryMap(this);
    collector->module[4] = this->_cmp;
}

void CollectorContructorArgs(struct sequenceRegex * this, struct ClassCollector * collector) {

    if (collector->module[3] != -1) {
        printf("Error Only one Constructor \n");
        exit(0);
    }
    collector->module[3] = this->_pointer - 1;

    RegexFuncArgs(this);

    MemoryMap(this);

    collector->module[4] = this->_cmp;
}

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
                            RegexFuncArgs(this);
                            goto endFunc;
                    }
                }
                break;
            case 40:
                funcType[*funcPointer] = this->_pointer - 1;
                MemoryMap(this);
                // Parenthesize start
                RegexFuncArgs(this);
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
    printf("Error in class format function \n");
    exit(0);

}

void CollectorFuncNameArgsOrAttrStrictType(struct sequenceRegex * this, int * funcPointer, int * funcType, int * attrPointer, int * attrType) {
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
    printf("Error in class format function \n");
    exit(0);
endFuncAttrError:
    printf("Error in class attribute function \n");
    exit(0);
}




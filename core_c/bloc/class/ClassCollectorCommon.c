void CollectorContructorArgsType(struct sequenceRegex * this, struct ClassCollector * collector) {

    if (collector->module[3] != -1) {
        printf("Error Only one Constructor \n");
        exit(0);
    }
    collector->module[3] = this->_pointer - 1;
    collector->module[5] = collector->_type;
    
    if (!RegexFuncArgsType(this,&collector->_type,collector->type)) {
        printf("Error in Constructor \n");
        exit(0);
    }
    MemoryMap(this);
    collector->module[4] = this->_cmp;
}



void CollectorContructorArgs(struct sequenceRegex * this, struct ClassCollector * collector) {

    if (collector->module[3] != -1) {
        printf("Error Only one Constructor \n");
        exit(0);
    }
    collector->module[3] = this->_pointer - 1;
    
    if (!RegexFuncArgs(this)) {
        printf("Error in Constructor \n");
        exit(0);
    }
    MemoryMap(this);
    collector->module[4] = this->_cmp;
}


void CollectorExtendsImplements(struct sequenceRegex * this, struct ClassCollector * collector) {
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
                switch (RegexExtends(this)) {
                    case 0:
                        goto extendsError;
                    case 1:
                        collector->module[1] = 1;
                        MemoryMap(this);
                        while (1) {
                            switch (fgetc(this->fp)) {
                                case 32:
                                    break;
                                case 23:
                                    break;
                                case 105:
                                    goto implements;
                                case 123:
                                    collector->module[2] = 0;
                                    return;
                                default:
                                    goto extendsError;
                            }
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
    switch (RegexImplements(this)) {
        case 0:
            goto implementsError;
        case 1:
            while (1) {
                // Function start
                switch (fgetc(this->fp)) {
                    case 32:
                        break;
                    case 23:
                        break;
                    case 123:
                        collector->module[2] = 1;
                        MemoryMap(this);
                        return;
                    default:
                        goto implementsError;
                }
            }
    }



implementsError:
    printf("Error in class format implements \n");
    exit(0);

extendsError:
    printf("Error in class format extends  \n");
    exit(0);


}

void CollectorExtends(struct sequenceRegex * this, struct ClassCollector * collector) {
    while (1) {
        switch (fgetc(this->fp)) {
            case 32:
                break;
            case 23:
                break;
            case 101:
                switch (RegexExtends(this)) {
                    case 0:
                        goto endError;
                    case 1:
                        while (1) {
                            switch (fgetc(this->fp)) {
                                case 32:
                                    break;
                                case 23:
                                    break;
                                case 123:
                                    goto endFuncTrue;
                                default:
                                    goto endError;
                            }
                        }
                }
                break;
            case 123:
                goto endFuncFalse;
            default:
                goto endError;
        }
    }

endFuncFalse:
    collector->module[1] = 0;
    MemoryMap(this);
    return;

endFuncTrue:
    collector->module[1] = 1;
    MemoryMap(this);
    return;

endError:
    printf("Error in class format extends \n");
    exit(0);

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


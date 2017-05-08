void CollectorExtendsImplements(struct sequenceRegex * this, struct ClassCollector * collector) {
    
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
        this->ch = fgetc(this->fp);
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

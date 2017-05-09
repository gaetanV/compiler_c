
void CollectorContructorArgsStrictType(struct Buffer * this, struct ClassCollector * collector) {

    if (collector->module[3] != -1) {
        printf("Error Only one Constructor \n");
        exit(0);
    }
    collector->module[3] = this->_pointer - 1;

    while (1) {
        switch (fgetc(this->fp)) {
            default:
                goto errorArgsType;
            case 32:
                break;
            case 40:
                // Parenthesize start
                RegexFuncArgsStrictTypeInner(this);
                MemoryMap(this);
                collector->module[4] = this->_cmp;
                return;
        }
    }

errorArgsType:
    Error(this, "Contructor arguments type");

}

void CollectorContructorArgsType(struct Buffer * this, struct ClassCollector * collector) {

    if (collector->module[3] != -1) {
        printf("Error Only one Constructor \n");
        exit(0);
    }
    collector->module[3] = this->_pointer - 1;
    collector->module[5] = collector->_type;


    while (1) {
        switch (fgetc(this->fp)) {
            default:
                goto errorArgs;
            case 32:
                break;
            case 40:
                // Parenthesize start
                if (!RegexFuncArgsTypeInner(this, &collector->_type, collector->type)) {
                    goto errorArgs;
                }
                MemoryMap(this);
                collector->module[4] = this->_cmp;
                return;
        }
    }
errorArgs:
    Error(this, "Contructor arguments type");

}

void CollectorContructorArgs(struct Buffer * this, struct ClassCollector * collector) {

    if (collector->module[3] != -1) {
        printf("Error Only one Constructor \n");
        exit(0);
    }
    collector->module[3] = this->_pointer - 1;

    while (1) {
        switch (fgetc(this->fp)) {
            default:
                goto errorArgs;
            case 32:
                break;
            case 40:
                // Parenthesize start
                RegexFuncArgsInner(this);
                MemoryMap(this);
                collector->module[4] = this->_cmp;
                return;
        }

    }

errorArgs:
    Error(this, "Contructor arguments type");

}

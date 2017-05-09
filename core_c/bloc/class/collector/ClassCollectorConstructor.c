
void CollectorContructorArgsStrictType(struct Buffer * this, bool * hasConstructor, unsigned short * constructor) {

    if (*hasConstructor == 1) {
        printf("Error Only one Constructor \n");
        exit(0);
    } else {
        *hasConstructor = 1;
    }
    constructor[0] = this->_pointer - 1;

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
                constructor[1] = this->_cmp;
                return;
        }
    }

errorArgsType:
    Error(this, "Contructor arguments type");

}

void CollectorContructorArgsType(
        struct Buffer * this,
        unsigned short * constructor,
        bool * hasConstructor,
        int * typePointer,
        bool * funcType
        ) {

    if (*hasConstructor == 1) {
        printf("Error Only one Constructor \n");
        exit(0);
    } else {
        *hasConstructor = 1;
    }

    constructor[0] = this->_pointer - 1;
    constructor[2] = *typePointer;


    while (1) {
        switch (fgetc(this->fp)) {
            default:
                goto errorArgs;
            case 32:
                break;
            case 40:
                // Parenthesize start
                if (!RegexFuncArgsTypeInner(this, typePointer, funcType)) {
                    goto errorArgs;
                }
                MemoryMap(this);
                constructor[1] = this->_cmp;
                return;
        }
    }
errorArgs:
    Error(this, "Contructor arguments type");

}

void CollectorContructorArgs(struct Buffer * this, bool * hasConstructor, unsigned short * constructor) {

    if (*hasConstructor == 1) {
        printf("Error Only one Constructor \n");
        exit(0);
    } else {
        *hasConstructor = 1;
    }
    constructor[0] = this->_pointer - 1;

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
                constructor[1] = this->_cmp;
                return;
        }

    }

errorArgs:
    Error(this, "Contructor arguments type");

}

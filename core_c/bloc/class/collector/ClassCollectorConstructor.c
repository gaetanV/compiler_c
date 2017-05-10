/**
@ERROR
 */
void ErrorCollectorConstructorOnlyOne(struct Buffer * this) {
    Error(this, "Error Only one Constructor");
}

void ErrorCollectorConstructorArgs(struct Buffer * this) {
    Error(this, "Contructor arguments type");
}

/**
@DEFINE
 */
#define _CollectorConstructorOnlyOne(this,hasConstructor) \
    if (*hasConstructor == 1) {\
        ErrorCollectorConstructorOnlyOne(this);\
    } else {\
        *hasConstructor = 1;\
    }\


/**
@@@@@@@
 */
void CollectorContructorArgsStrictType(struct Buffer * this, bool * hasConstructor, unsigned short * constructor) {

    _CollectorConstructorOnlyOne(this, hasConstructor);
    constructor[0] = this->_pointer - 1;

    while (1) {
        switch (fgetc(this->fp)) {
            default:
                ErrorCollectorConstructorArgs(this);
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
}

void CollectorContructorArgsType(
        struct Buffer * this,
        unsigned short * constructor,
        bool * hasConstructor,
        int * typePointer,
        bool * funcType
        ) {

    _CollectorConstructorOnlyOne(this, hasConstructor);

    constructor[0] = this->_pointer - 1;
    constructor[2] = *typePointer;

    while (1) {
        switch (fgetc(this->fp)) {
            default:
                ErrorCollectorConstructorArgs(this);
            case 32:
                break;
            case 40:
                // Parenthesize start
                RegexFuncArgsTypeInner(this, typePointer, funcType);
                MemoryMap(this);
                constructor[1] = this->_cmp;
                return;
        }
    }
}

void CollectorContructorArgs(struct Buffer * this, bool * hasConstructor, unsigned short * constructor) {

    _CollectorConstructorOnlyOne(this, hasConstructor);
    constructor[0] = this->_pointer - 1;

    while (1) {
        switch (fgetc(this->fp)) {
            default:
                ErrorCollectorConstructorArgs(this);
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
}

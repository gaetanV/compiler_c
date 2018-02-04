/**
@ERROR
 */
void ErrorCollectorConstructorOnlyOne(struct Buffer * buffer) {
    Error(buffer, "Error Only one Constructor");
}

void ErrorCollectorConstructorArgs(struct Buffer * buffer) {
    Error(buffer, "Contructor arguments type");
}

/**
@DEFINE
 */
#define _CollectorConstructorOnlyOne(buffer,hasConstructor) \
    if (*hasConstructor == 1) {\
        ErrorCollectorConstructorOnlyOne(buffer);\
    } else {\
        *hasConstructor = 1;\
    }\


/**
@@@@@@@
 */
void CollectorContructorArgsStrictType(struct Buffer * buffer, bool * hasConstructor, unsigned short * constructor) {

    _CollectorConstructorOnlyOne(buffer, hasConstructor);
    constructor[0] = buffer->_pointer - 1;

    while (1) {
        switch (fgetc(buffer->fp)) {
            default:
                ErrorCollectorConstructorArgs(buffer);
            case 32:
                break;
            case 40:
                // Parenthesize start
                RegexFuncArgsStrictTypeInner(buffer);
                MemoryMap(buffer);
                constructor[1] = buffer->_cmp;
                return;
        }
    }
}

void CollectorContructorArgsType(
        struct Buffer * buffer,
        unsigned short * constructor,
        bool * hasConstructor,
        int * typePointer,
        bool * funcType
        ) {

    _CollectorConstructorOnlyOne(buffer, hasConstructor);

    constructor[0] = buffer->_pointer - 1;
    constructor[2] = *typePointer;

    while (1) {
        switch (fgetc(buffer->fp)) {
            default:
                ErrorCollectorConstructorArgs(buffer);
            case 32:
                break;
            case 40:
                // Parenthesize start
                RegexFuncArgsTypeInner(buffer, typePointer, funcType);
                MemoryMap(buffer);
                constructor[1] = buffer->_cmp;
                return;
        }
    }
}

void CollectorContructorArgs(struct Buffer * buffer, bool * hasConstructor, unsigned short * constructor) {

    _CollectorConstructorOnlyOne(buffer, hasConstructor);
    constructor[0] = buffer->_pointer - 1;

    while (1) {
        switch (fgetc(buffer->fp)) {
            default:
                ErrorCollectorConstructorArgs(buffer);
            case 32:
                break;
            case 40:
                // Parenthesize start
                RegexFuncArgsInner(buffer);
                MemoryMap(buffer);
                constructor[1] = buffer->_cmp;
                return;
        }

    }
}

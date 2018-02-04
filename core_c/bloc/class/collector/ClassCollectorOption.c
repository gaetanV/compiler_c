/**
@ERROR
 */
void ErrorCollectorExtends(struct Buffer * buffer) {
    Error(buffer, "Class format extends");
}

void ErrorCollectorImplements(struct Buffer * buffer) {
    Error(buffer, "Class format implements");
}

void ErrorCollectorClass(struct Buffer * buffer) {
    Error(buffer, "Class format");
}

/**
@DEFINE
 */
// REGEX Extends Start at 101
#define _ExtendsStart(buffer)\
    if (fgetc(buffer->fp) != 120) { ErrorCollectorExtends(buffer); }\
    if (fgetc(buffer->fp) != 116) { ErrorCollectorExtends(buffer); }\
    if (fgetc(buffer->fp) != 101) { ErrorCollectorExtends(buffer); }\
    if (fgetc(buffer->fp) != 110) { ErrorCollectorExtends(buffer); }\
    if (fgetc(buffer->fp) != 100) { ErrorCollectorExtends(buffer); }\
    if (fgetc(buffer->fp) != 115) { ErrorCollectorExtends(buffer); }\
    RegexStrictSpaces(buffer);\
    Memory(buffer);\


// REGEX Implements Start at 105
#define _ImplementsStart(buffer) \
    if (fgetc(buffer->fp) != 109) { ErrorCollectorImplements(buffer); }\
    if (fgetc(buffer->fp) != 112) { ErrorCollectorImplements(buffer); }\
    if (fgetc(buffer->fp) != 108) { ErrorCollectorImplements(buffer); }\
    if (fgetc(buffer->fp) != 101) { ErrorCollectorImplements(buffer); }\
    if (fgetc(buffer->fp) != 109) { ErrorCollectorImplements(buffer); }\
    if (fgetc(buffer->fp) != 101) { ErrorCollectorImplements(buffer); }\
    if (fgetc(buffer->fp) != 110) { ErrorCollectorImplements(buffer); }\
    if (fgetc(buffer->fp) != 116) { ErrorCollectorImplements(buffer); }\
    if (fgetc(buffer->fp) != 115) { ErrorCollectorImplements(buffer); }\
    RegexStrictSpaces(buffer);\
    MemoryMap(buffer);\


/**
@@@@@@@
 */
void CollectorExtendsImplements(struct Buffer * buffer, bool * hasExtends, bool * hasImplements) {

    if (buffer->ch == 123) {
        return;
    }
    while (1) {
        switch (fgetc(buffer->fp)) {
            case 32:
                break;
            case 23:
                break;
            case 105:
                *hasExtends = 0;
                goto implements;
            case 101:
                _ExtendsStart(buffer);
                *hasExtends = 1;
                while (1) {
                    switch (buffer->ch = fgetc(buffer->fp)) {
                        case EOF:
                            ErrorCollectorExtends(buffer);
                        case 10:
                            ErrorCollectorExtends(buffer);
                        case 59:
                            ErrorCollectorExtends(buffer);
                        case 32:
                            while (1) {
                                switch (fgetc(buffer->fp)) {
                                    case 32:
                                        break;
                                    case 23:
                                    case 105:
                                        goto implements;
                                        break;
                                    case 123:
                                        MemoryMap(buffer);
                                        return;
                                    default:
                                        ErrorCollectorExtends(buffer);
                                }
                            }
                        case 123:
                            MemoryMap(buffer);
                            return;
                        default:
                            Memory(buffer);
                            break;
                    }
                }

                break;
            case 123:
                *hasExtends = 0;
                *hasImplements = 0;
                return;
            default:
                ErrorCollectorClass(buffer);
        }
    }

implements:

    _ImplementsStart(buffer);
    *hasImplements = 1;
    Memory(buffer);
    while (1) {
        switch (buffer->ch = fgetc(buffer->fp)) {
            case EOF:
                ErrorCollectorImplements(buffer);
            case 10:
                ErrorCollectorImplements(buffer);
            case 59:
                ErrorCollectorImplements(buffer);
            case 32:

                while (1) {
                    // Function start
                    switch (fgetc(buffer->fp)) {
                        case 32:
                            break;
                        case 23:
                            break;
                        case 123:
                            MemoryMap(buffer);
                            return;
                        default:
                            ErrorCollectorImplements(buffer);
                    }
                }
            case 123:
                MemoryMap(buffer);
                return;
            default:
                Memory(buffer);
                break;
        }
    }



}

void CollectorExtends(struct Buffer * buffer, bool * hasExtends) {

    if (buffer->ch == 123) {
        goto endFuncFalse;
    }

    while (1) {
        switch (fgetc(buffer->fp)) {
            case 32:
                break;
            case 23:
                break;
            case 101:
                _ExtendsStart(buffer);
                while (1) {
                    switch (buffer->ch = fgetc(buffer->fp)) {
                        case EOF:
                            ErrorCollectorExtends(buffer);
                        case 10:
                            ErrorCollectorExtends(buffer);
                        case 59:
                            ErrorCollectorExtends(buffer);
                        case 32:
                            while (1) {
                                switch (fgetc(buffer->fp)) {
                                    case 32:
                                        break;
                                    case 23:
                                        break;
                                    case 123:
                                        goto extendsEnd;
                                    default:
                                        ErrorCollectorExtends(buffer);
                                }
                            }
                        case 123:
                            goto extendsEnd;
                        default:
                            Memory(buffer);
                            break;
                    }
                }
            case 123:
                goto endFuncFalse;
            default:
                ErrorCollectorClass(buffer);
        }
        buffer->ch = fgetc(buffer->fp);
    }
endFuncFalse:
    *hasExtends = 0;
    MemoryMap(buffer);
    return;

extendsEnd:
    *hasExtends = 1;
    MemoryMap(buffer);
    return;



}

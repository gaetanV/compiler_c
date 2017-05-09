#include <stdbool.h>

int RegexMemoryFuncInner(struct Buffer * this) {

    // Function Start
    while (1) {
        switch (fgetc(this->fp)) {
            case 32:
                break;
            case 23:
                break;
            case 123:
                goto End;
            default:
                return 0;
        }
    }
End:
    this->c = 1;
    while (1) {
        switch (this->ch = fgetc(this->fp)) {
            case EOF:
                return 0;
            case 47:
                switch (this->ch = fgetc(this->fp)) {
                    case 47:
                        if (!RegexForceEmptyLigne(this)) {
                            return 0;
                        }
                        break;
                    case 42:
                        if (!RegexCommentBloc(this)) {
                            return 0;
                        }
                        break;
                    default:
                        MemoryChar(this, 47);
                        Memory(this);
                        break;
                }
                break;
            case 123:
                Memory(this);
                this->c++;
                break;
            case 125:

                this->c--;
                if (this->c <= 0) {
                    return 1;
                }
                Memory(this);
                break;
            default:
                Memory(this);
                break;
        }
    }
    // Function Stop

}

void RegexFuncArgsInner(struct Buffer * this) {

    this->_cmp = 0;
step1:
    while (1) {
        switch (this->ch = fgetc(this->fp)) {
            case EOF:
                goto errorFuncInner;
            case 32:
                break;
            case 41:
                goto end;
            default:
                if (this->_cmp != 0) {
                    MemoryMap(this);
                }
                this->_cmp++;
                Memory(this);
                goto step2;
                break;
        }
    }
step2:
    while (1) {
        switch (this->ch = fgetc(this->fp)) {
            case EOF:
                goto errorFuncInner;
            case 41:
                goto end;
            case 44:
                goto step1;
            case 32:
                goto step3;
                break;
            default:

                Memory(this);
                break;
        }
    }
step3:
    while (1) {
        switch (this->ch = fgetc(this->fp)) {
            case EOF:
                goto errorFuncInner;
            case 41:
                goto end;
            case 44:
                goto step1;
            default:
                goto errorFuncInner;
        }
    }

end:
    if (this->_cmp != 0) {
        MemoryMap(this);
    }
    // Args Stop
    if (!RegexMemoryFuncInner(this)) {
        goto errorFuncInner;
    }
    return;

errorFuncInner:
    Error(this, "function arguments ");

}


int RegexFuncArgsTypeInner(struct Buffer * this, int * typePointer, bool * type) {

    this->_cmp = 0;

step1:
                
    this->c = 1;
    while (1) {
        switch (this->ch = fgetc(this->fp)) {
            case EOF:
                return 0;
            case 41:
                goto end;
            case 32:
                break;
            default:
                if (this->_cmp != 0) {
                    MemoryMap(this);
                }
                type[* typePointer] = 0;
                * typePointer = *typePointer + 1;
                Memory(this);
                goto step2;
                break;
        }
    }
step2:
    while (1) {
        switch (this->ch = fgetc(this->fp)) {
            case EOF:
                return 0;
            case 41:
                goto end;
            case 44:
                goto step1;
                break;
            case 32:
                while (1) {
                    switch (this->ch = fgetc(this->fp)) {
                        case EOF:
                            return 0;
                        case 41:
                            goto end;
                        case 44:
                            goto step1;
                        default:
                            type[* typePointer - 1 ] = 1;
                            MemoryMap(this);
                            Memory(this);
                            goto step3;
                            break;

                    }
                }
            default:
                Memory(this);
                break;
        }
    }
step3:
    while (1) {
        switch (this->ch = fgetc(this->fp)) {
            case EOF:
                return 0;
            case 41:
                goto end;
            case 44:
                goto step1;
                break;
            case 32:
                goto step4;
                break;
            default:
                Memory(this);
                break;
        }
    }

step4:
    while (1) {
        switch (this->ch = fgetc(this->fp)) {
            case 41:
                goto end;
            case 44:
                goto step1;
                break;
            case 32:
                break;
            default:
                return 0;
        }
    }

end:
    return RegexMemoryFuncInner(this);

}



void RegexFuncArgsStrictTypeInner(struct Buffer * this) {

    this->_cmp = 0;

step1:
    this->c = 1;
    while (1) {
        switch (this->ch = fgetc(this->fp)) {
            case EOF:
                goto errorName;
            case 41:
                goto end;
            case 32:
                break;
            default:

                if (this->_cmp != 0) {
                    MemoryMap(this);
                }

                this->_cmp++;
                Memory(this);
                goto step2;
                break;
        }
    }
step2:
    while (1) {
        switch (this->ch = fgetc(this->fp)) {
            case EOF:
                goto errorArgs;
            case 41:
                goto errorArgs;
            case 44:
                goto errorArgs;
                break;
            case 32:
                while (1) {
                    switch (this->ch = fgetc(this->fp)) {
                        case EOF:
                            goto errorArgs;
                        case 41:
                            goto errorArgs;
                        case 44:
                            goto errorArgs;
                        default:
                            MemoryMap(this);
                            Memory(this);
                            goto step3;
                            break;

                    }
                }
            default:
                Memory(this);
                break;
        }
    }
step3:
    while (1) {
        switch (this->ch = fgetc(this->fp)) {
            case EOF:
                goto errorArgs;
            case 41:
                goto end;
            case 44:
                goto step1;
                break;
            case 32:
                goto step4;
                break;
            default:
                Memory(this);
                break;
        }
    }

step4:
    while (1) {
        switch (this->ch = fgetc(this->fp)) {
            case 41:
                goto end;
            case 44:
                goto step1;
                break;
            case 32:
                break;
            default:
                goto errorArgs;
        }
    }

end:
    if (!RegexMemoryFuncInner(this)) {
        goto errorArgs;
    }

    return;
errorArgs:
    Error(this, "function arguments type");

errorName:
    Error(this, "function name");

}


#include <stdio.h>
#include <stdbool.h>

int RegexFuncArgsInner(struct sequenceRegex * this) {

    this->_cmp = 0;
step1:
    while (1) {
        switch (this->ch = fgetc(this->fp)) {
            case EOF:
                return 0;
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
                return 0;
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
                return 0;
            case 41:
                goto end;
            case 44:
                goto step1;
            default:
                printf("Error in Arguments \n");
                return 0;
        }
    }

end:
    if (this->_cmp != 0) {
        MemoryMap(this);
    }
    // Args Stop

    return RegexMemoryFuncInner(this);
}

int RegexFuncArgs(struct sequenceRegex * this) {
    while (1) {
        switch (fgetc(this->fp)) {
            default:
                return 0;
            case 32:
                break;
            case 40:

                // Parenthesize start
                return RegexFuncArgsInner(this);
        }
    }

}

int RegexFuncArgsTypeInner(struct sequenceRegex * this, int * typePointer, bool * type) {

    
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
                this->_cmp++;
                type[* typePointer] = 0;
                * typePointer = * typePointer + 1;
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

int RegexFuncArgsType(struct sequenceRegex * this, int * typePointer, bool * type) {

    while (1) {
        switch (fgetc(this->fp)) {
            default:
                return 0;
            case 32:
                break;
            case 40:
                // Parenthesize start
                return RegexFuncArgsTypeInner(this,typePointer,type);
        }
    }

}




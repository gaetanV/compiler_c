#include <stdio.h>

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

int RegexFuncArgsType(struct sequenceRegex * this) {


    while (1) {
        switch (fgetc(this->fp)) {
            default:
                return 0;
            case 32:
                break;
            case 40:
                // Parenthesize start
                goto end;
        }
    }
end:

    // MemoryCmp(this);
    // Args Start
    this->c = 1;
    do {
        switch (this->ch = fgetc(this->fp)) {
            case EOF:
                return 0;
            case 41:
                printf("End param \n");
                break;
            case 44:
                printf("End param \n");
                this->c = 1;
                break;
            case 32:
                if (this->c = 2) {
                    printf("End Type \n");
                    this->c = 3;
                }
                break;
            default:
                Memory(this);
                if (this->c == 1) {
                    printf("Start Type \n");
                    this->c = 2;
                }
                if (this->c == 3) {
                    printf("Start Param \n");
                    //   MemoryCmpNext(this);

                    this->c = 4;
                }
                break;
        }
    } while (this->ch != 41);
    // Args End

    return RegexMemoryFuncInner(this);
}




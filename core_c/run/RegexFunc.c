#include <stdio.h>

int RegexFuncNameArgs(struct sequenceRegex * this) {
   
    if (!this->ch == 32) {
              Memory(this);
    }


    /// Start NotSpace Or Parenthesize
    while (1) {
        switch (this->ch = fgetc(this->fp)) {
            case EOF:
                return 0;
            case 10:
                return 0;
            case 32:
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
                break;
            case 40:
                // Parenthesize start
                goto end;
            default:
                Memory(this);
                break;
        }
    }
end:
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
                break;
            default:
                Memory(this);
                if (this->c == 1) {
                    printf("Start param \n");
                }
                this->c = 2;
                break;

        }

    } while (this->ch != 41);
    // Args Stop

    return RegexMemoryFuncInner(this);
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
                    this->c = 4;
                }
                break;
        }
    } while (this->ch != 41);
    // Args End

    return RegexMemoryFuncInner(this);
}




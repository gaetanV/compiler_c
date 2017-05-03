#include <stdio.h>

#include "./regex/RegexImport.c"
#include "./regex/RegexExport.c"

int parseHeader(struct sequenceRegex * this) {

    while (1) {
        switch ( fgetc(this->fp)) {
            case EOF:
                return 0;
            case 105:
                if (RegexImport(this)) {
                    if (this->ch != 10) {
                        printf("Header/End/Regex  import \n");
                        RegexEmptyLigne(this);
                    }
                }
                break;
            case 101:
                if (RegexExport(this)) {
                    printf("Header/End/Regex  export \n ");
                    return 1;
                }
                break;
            case 32:
                break;
            case 10:
                break;
            default:
                return 0;
                break;
        }

    }
    return 1;
}

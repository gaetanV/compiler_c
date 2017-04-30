#include <stdio.h>

#include "./regex/RegexImport.c"
#include "./regex/RegexExport.c"

int parseHeader(struct sequenceRegex * this) {

    while (nextChar(this)) {
        switch (this->ch) {
            case 105:
                printf(">----------------------------- \n");
                printf("Header/Find/Regex import \n");
                if (RegexImport(this)) {
                    if (this->ch != 10) {
                        printf("Header/End/Regex  import \n");
                        printf("-----------------------------< \n");
                        SequenceEmptyLigne(this);
                    }
                }
                break;
            case 101:
                printf(">----------------------------- \n");
                printf("Header/Find/Regex export \n");
                if (RegexExport(this)) {
                    printf("Header/End/Regex  export \n ");
                    printf("-----------------------------< \n");
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

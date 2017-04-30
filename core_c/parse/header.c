#include <stdio.h>

#include "regex/import.c"
#include "regex/export.c"


int parseHeader(FILE *fp) {
  

    struct sequenceRegex seqRegex;
    initSequenceRegex(&seqRegex, fp);
    
    while (nextChar(&seqRegex)) {
        printf("F %c\n", currentChar(&seqRegex));
        printf("F %d\n", currentChar(&seqRegex));
        switch (currentChar(&seqRegex)) {
            case 105:
                if (!newImport(&seqRegex)) {
                    if (currentChar(&seqRegex) != 10) {
                        emptyLigne(&seqRegex);
                    }
                }
                break;
            case 101:
                if (newExport(&seqRegex)) {
                    return 1;
                }
                break;
            case 32:
                break;
            case 10:
                break;
            default:
                emptyLigne(&seqRegex);
                break;
        }

    }
    return 0;
}

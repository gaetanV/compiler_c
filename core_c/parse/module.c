#include <stdio.h>
#include "regex/func.c"
#include "regex/constructor.c"
#include "regex/static.c"

#include "regex/p_.c"



int parseModule(FILE *fp) {


    struct sequenceRegex seqRegex;
    initSequenceRegex(&seqRegex, fp);

    while (nextChar(&seqRegex)) {
        printf("M %c\n", currentChar(&seqRegex));

        switch (currentChar(&seqRegex)) {
            case  99:
                if (newConstructor(&seqRegex)) {
                     printf("-- Constructor \n");
                }else{
                    printf("error");
                    return 0;
                }
                break;
            case 112:
                if (newP_(&seqRegex)) {
                     printf("-- END P_\n");
                }else{
                    printf("error");
                    return 0;
                }
                break;
            case 115:
                if (newStatic(&seqRegex)) {
                     printf("-- Static \n");
                }else{
                    printf("error");
                    return 0;
                }
                break;
            case 125:
                return 1;
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

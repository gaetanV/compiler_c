#include "sequence/sequenceRegex.c"
#include "sequence/Regexcommon.c"
#include "sequence/RegexFunc.c"
#include "bloc/header/header.c"
#include "bloc/class/class.c"

int main(int argc, char *argv[]) {

    if (!argv[1]) {
        printf("File argument expected.\n");
        return 0;
    }

    struct sequenceRegex seqRegex;

    if (SequenceInit(&seqRegex, argv[1])) {
        if (parseHeader(&seqRegex)) {
            if (currentChar(&seqRegex) == 99) {
                if (parseClass(&seqRegex, RegexFuncArgsType , RegexFuncNameArgs )) {
                    printf("Module done.\n");
                } else {
                    printf("Error in Module");
                    return 0;
                }
            } else {
                printf("Only export class.\n");
            }
        } else {
            printf("Error in header");
            return 0;
        }
    }

    SequenceFlush(&seqRegex);

    printf("All is done nice work");

    return 1;
}

#include "run/sequenceRegex.c"
#include "run/Regexcommon.c"
#include "run/RegexFunc.c"
#include "run/RegexFuncExtends.c"

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
            switch (currentChar(&seqRegex)) {
                case 99:
                    if (parseClass(&seqRegex, RegexFuncArgsType, RegexFuncNameArgs , RegexExtendsImplements)) {
                        printf("Module done.\n");
                    } else {
                        printf("Error in Module");
                        return 0;
                    }
                    break;
                default:
                    printf("Only export class.\n");
                    return 0;
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

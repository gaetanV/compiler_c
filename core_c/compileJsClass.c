#include "run/Buffer.c"
#include "run/Error.c"

#include "run/Regexcommon.c"
#include "run/RegexFunc.c"

#include "bloc/header/header.c"
#include "bloc/class/class.c"

#include <time.h>

/**
@TOOLS
 */

int _scanJs(struct Buffer * buffer) {
    //struct timespec t1, t2;
    //clock_gettime(CLOCK_MONOTONIC, &t1);
    
    if (parseHeader(buffer)) {
        switch (buffer->ch) {
            case 99:
         
                if (parseClassJsServer(buffer, ClassJsServerOutput)) {
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
    fclose(buffer->fp);


    printf("All is done nice work");
    //clock_gettime(CLOCK_MONOTONIC, &t2);
    //printf(" \t | %lu \n",  (unsigned long long) (t2.tv_nsec -  t1.tv_nsec));

    return 1;
}

/**
@MAIN
 */
int main(int argc, char *argv[]) {

    if (!argv[1]) {
        printf("File argument expected.\n");
        return 0;
    }

    struct Buffer seqRegex;

    SequenceInit(&seqRegex, argv[1]);
    return _scanJs(&seqRegex);


}

#include <stdio.h>
#include "sequence.c"
#include "regex/sequenceRegex.c"
#include "regex/import.c"
#include "regex/export.c"



int parseHeader(FILE *fp) {
    char ch;

    
    struct sequenceRegex regex;
    struct sequence header;
    
    constructSequence(&header);
    
    
    while ((ch = fgetc(fp)) != EOF) {
        printf("%c\n", ch);
   
        switch (header.stL) {

            case 0:
               
                switch (ch) {
                    case 105:
                        startSequence(&header, 1);
                        startSequenceRegex(&regex);
                        break;
                    case 101:
                        startSequence(&header, 5);
                        startSequenceRegex(&regex);
                        break;
                    case 32:
                        break;
                    case 10:
                        startLigne(&header);
                        break;
                    default:
                        emptyLigne(&header);
                        break;
                }
            case 1:
                switch (header.seq) {
                    case 1:
                        switch (nextImport(&regex, ch)) {
                            case 0:
                                emptyLigne(&header);
                                break;
                            case 2:
                                endLigne(&header);
                                break;
                        }
                        break;
                    case 5:
                        switch (nextExport(&regex, ch)) {
                            case 0:
                                emptyLigne(&header);
                                break;
                            case 2:
                                printf("seq5 complete \n");
                                endLigne(&header);
                                return 1;
                                break;
                        }
                        break;
                }
                if (ch == 10) {
                    startLigne(&header);
                }
                break; 
                
            case 2:
                if (ch == 10) {
                    startLigne(&header);
                }
                break;
        }
    }
    return 0;
}
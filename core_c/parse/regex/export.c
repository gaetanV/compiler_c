#include <stdio.h>

int RegexExport(int pos, char ch) {
    switch (pos) {
        case 0:
            if (ch == 101) {
                return 1;
            }
            break;
        case 1:
            if (ch != 120) {
                return 0;
            } else {
                return 1;
            }
            break;
        case 2:
            if (ch != 112) {
                return 0;
            } else {
                return 1;
            }
            break;
        case 3:
            if (ch != 111) {
                return 0;
            } else {
                return 1;
            }
            break;
        case 4:
            if (ch != 114) {
                return 0;
            } else {
                return 1;
            }
            break;
        case 5:
            if (ch != 116) {
                return 0;
            } else {
                return 2;
            }
    }
    return 0;
}



int RegexClass(int pos, char ch) {
    switch (pos) {
        case 0:
            if (ch == 99) {
                return 1;
            } else {
                return 0;
            }
            break;
        case 1:
            if (ch == 108) {
                return 1;
            } else {
                return 0;
            }
            break;
        case 2:
            if (ch == 97) {
                return 1;
            } else {
                return 0;
            }
            break;
        case 3:
            if (ch == 115) {
                return 1;
            } else {
                return 0;
            }
        case 4:
            if (ch == 115) {
                return 2;
            } else {
                return 0;
            }
            break;   
            

    }
    return 0;
}




int nextExport(struct sequenceRegex * this, char ch) {
    switch (this->seq) {
        case 0:
            switch (RegexExport(this->seqPos, ch)) {
                case 0:
                    startSequenceRegex(this);
                    return 0;
                    break;
                case 1:
                    this->seqPos++;
                    break;
                case 2:
                    nextSequenceRegex(this);
                    break;
            }
            break;
        case 1:                   
            switch (RegexSpace(this->seqPos, ch)) {
                case 0:
                    startSequenceRegex(this);
                    return 0;
                    break;
                case 1:
                    this->seqPos++;
                    break;
                case 2:
                    nextSequenceRegex(this);
                    nextExport(this,ch) ;
                    break;
            }
            break;
        case 2:
            switch (RegexClass(this->seqPos, ch)) {
                case 0:
                    startSequenceRegex(this);
                    return 0;
                    break;
                case 1:
                    this->seqPos++;
                    break;
                case 2:
                    nextSequenceRegex(this);
                    break;
            }
            break;
        case 3:   
            switch (RegexSpace(this->seqPos, ch)) {
                case 0:
                    startSequenceRegex(this);
                    return 0;
                    break;
                case 1:
                    this->seqPos++;
                    break;
                case 2:
                    nextSequenceRegex(this);
                    nextExport(this,ch) ;
                    break;
            }
            break;  
        case 4:
            switch (RegexNotSpace(this->seqPos,ch)) {
                case 0:
                    startSequenceRegex(this);
                    return 0;
                    break;
                case 1:
                    this->seqPos++;
                    break;
                case 2:
                    nextSequenceRegex(this);
                    break;
            }
            break;  
        case 5:
            switch (RegexStartFunc(this->seqPos, ch)) {
                case 0:
                    startSequenceRegex(this);
                    return 0;
                    break;
                case 1:
                    this->seqPos++;
                    break;
                case 2:
                    printf("seq export complete \n");
                    startSequenceRegex(this);
                    return 2;
                    break;
            }
            break;
    }
    return 1;
}

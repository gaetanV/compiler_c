#include <stdio.h>


int RegexImport(int pos,char ch) {
    switch (pos) {
        case 0:
            if (ch == 105) {
                 return 1;
            }
            break;
        case 1:
            if (ch != 109) {
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


int RegexFrom(int pos,char ch) {

    switch (pos) {
        case 0:
            if (ch != 102) {
                return 0;
            } else {
                return 1;
            }
            break;
        case 1:
            if (ch != 114) {
                return 0;
            } else {
                return 1;
            }
            break;
        case 2:
            if (ch != 111) {
                return 0;
            } else {
               return 1;
            }
            break;
        case 3:
            if (ch != 109) {
                return 0;
            } else {
                return 2;
            }
            break;
    }
    return 0;
}

int nextImport(struct sequenceRegex * this,char ch) {
    switch (this->seq) {
        case 0:
            switch (RegexImport(this->seqPos,ch)) {
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
                    nextImport(this,ch) ;
                    break;
            }
            break;   
        case 2:
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
        case 3:
            switch (RegexFrom(this->seqPos,ch)) {
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
        case 4:                   
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
                    nextImport(this,ch) ;
                    break;
            }
            break;      
        case 5:
            switch (RegexNotSpaceOrEndOfLine(this->seqPos,ch)) {
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
                case 4:
                    printf("seq import complete \n");
                    startSequenceRegex(this);
                    return 2;
                    break;
            }
            break;  
        case 6:
            switch (RegexEndOfLine(this->seqPos, ch)) {
                case 0:
                    startSequenceRegex(this);
                    return 0;
                    break;
                case 1:
                    this->seqPos++;
                    break;
                case 2:
                    printf("seq import complete \n");
                    startSequenceRegex(this);
                    return 2;
                    break;
            }
            break;
    }
    return 1;
};
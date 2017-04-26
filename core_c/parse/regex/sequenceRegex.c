#include <stdio.h>

struct sequenceRegex {
    int seq;
    int seqPos;
};

void startSequenceRegex(struct sequenceRegex * this) {
    this->seq = 0;
    this->seqPos = 0;

};

void nextSequenceRegex(struct sequenceRegex * this) {
    this->seq++;
    this->seqPos = 0;
};

int RegexSpace(int pos, char ch) {
    switch (ch) {
        case 32:
            return 3;
        default:
            return 2;
    }
}

int RegexNotSpace(int pos, char ch) {
    switch (ch) {
        case 32:
            return 2;
        default:
            return 3;
    }
}

int RegexStartFunc(int pos, char ch) {
    switch (ch) {
        case 123:
            return 2;
        case 23:
            return 3;
        default:
            return 0;
    }
}

int RegexEndOfLine(int pos, char ch) {
    switch (ch) {
        case 59:
            return 2;
        case 23:
            return 3;
        default:
            return 0;
    }
}

int RegexNotSpaceOrEndOfLine(int pos, char ch) {
    switch (ch) {
        case 59:
            return 4;
        case 32:
            return 2;
        default:
            return 3;
    }
}
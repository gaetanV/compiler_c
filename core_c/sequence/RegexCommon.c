int RegexSpace(int pos, char ch) {
    switch (ch) {
        case 32:
            return 3;
        case 10:
            return 0;
        default:
            return 2;
    }
}

int RegexNotSpace(int pos, char ch) {
    switch (ch) {
        case 32:
            return 2;
        case 10:
            return 0;
        default:
            return 3;
    }
}


int RegexEndOfLine(int pos, char ch) {
    switch (ch) {
        case 59:
            return 2;
        case 32:
            return 1;
        default:
            return 0;
    }
}

int RegexNotSpaceOrEndOfLine(int pos, char ch) {
    switch (ch) {
        case 59:
            return 2;
        case 32:
            return 2;
        case 10:
            return 0;
        default:
            return 3;
    }
}

int RegexNotSpaceOrParenthesize(int pos, char ch) {
     switch (ch) {
        case 40:
            return 2;
        case 32:
            return 2;
        case 10:
            return 0;
        default:
            return 3;
    }
}

int RegexStartParenthesize(int pos, char ch) {
    switch (ch) {
        case 40:
            return 2;
        case 32:
            return 1;
        case 23:
            return 0;
        default:
            return 3;
    }
}

int RegexEndParenthesize(int pos, char ch){
     switch (ch) {
        case 41:
            return 2;
        case 32:
            return 1;
        case 23:
            return 0;
        default:
            return 3;
    }
}


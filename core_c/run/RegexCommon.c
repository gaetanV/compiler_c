
int RegexJumpSpace(struct sequenceRegex * this) {
    while (1) {
        if ((this->ch = fgetc(this->fp)) !=  32) {
            return 1;
        }
    };
}


int RegexCommentBloc(struct sequenceRegex * this) {
    while (1) {
        loop1 :
        switch (fgetc(this->fp)) {
            case EOF:
                return 0;
            case 42:
                loop2 :
                switch (fgetc(this->fp)) {
                    case EOF:
                        return 0;    
                    case 47:
                        return 1;
                    case 42:
                        goto loop2;
                    default:
                        goto loop1;

                }
                break;

        }
    }
}


int RegexForceEmptyLigne(struct sequenceRegex * this) {
    while (1) {
        switch (fgetc(this->fp)) {
            case EOF:
                return 0;
            case 10:
                return 1;
        }
    }
}

int RegexComments(struct sequenceRegex * this) {
    switch (fgetc(this->fp)) {
        case 47:
            if (!RegexForceEmptyLigne(this)) {
                return 0;
            }
            break;
        case 42:
            if (!RegexCommentBloc(this)) {
                return 0;
            }
            break;
        default:
            return 0;
    }
}


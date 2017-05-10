/**
@ERROR
*/
void ErrorComment(struct Buffer * this) {
    Error(this, "Comment");
}

void ErrorSpace(struct Buffer * this) {
    Error(this, "Spaces");
}

/**
@@@@@@@
*/
void RegexJumpSpace(struct Buffer * this) {
    while (1) {
        if ((this->ch = fgetc(this->fp)) != 32) {
            return;
        }
    };
}

int RegexForceEmptyLigne(struct Buffer * this) {
    while (1) {
        switch (fgetc(this->fp)) {
            case EOF:
                return 0;
            case 10:
                return 1;
        }
    }
}

void RegexStrictSpaces(struct Buffer * this) {
    if (fgetc(this->fp) != 32) {
        ErrorSpace(this);
    }
    while (1) {
        if ((this->ch = fgetc(this->fp)) != 32) {
            return;
        }
    };
}

int RegexCommentBloc(struct Buffer * this) {
    while (1) {
loop1:
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

void RegexStrictComments(struct Buffer * this) {
    switch (fgetc(this->fp)) {
        case 47:
            if (!RegexForceEmptyLigne(this)) {
                ErrorComment(this);
            }
            return;
            break;
        case 42:
            if (!RegexCommentBloc(this)) {
                ErrorComment(this);
            }
            return;
            break;
        default:
            ErrorComment(this);
    }

}



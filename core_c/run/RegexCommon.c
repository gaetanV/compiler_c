int RegexEmptyLigne(struct sequenceRegex * this) {
    while (1) {
        switch (this->ch = fgetc(this->fp)) {
            case 32:
                break;
            case 10:
                return 1;
            default:
                return 0;
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

int RegexCommentBloc(struct sequenceRegex * this) {
    while (1) {
        switch (fgetc(this->fp)) {
            case EOF:
                return 0;
            case 42:
                end :
                switch (fgetc(this->fp)) {
                    case 47:
                        return 1;
                    case 42:
                        goto end;

                }
                break;

        }
    }
}

int RegexJumpSpace(struct sequenceRegex * this) {
    while (1) {
        if (!nextCharIs(this, 32)) {
            return 1;
        }
    };
}

int RegexEndOfScriptLine(struct sequenceRegex * this) {
    while (1) {
        switch (fgetc(this->fp)) {
            case EOF:
                return 0;
            case 10:
                return 0;
            case 59:
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
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

//Regex
#define RegexJumpSpace(this) do{this->ch = fgetc(this->fp);} while (this->ch == 32); 
#define RegexStrictSpaces(this) if(fgetc(this->fp) != 32) {ErrorSpace(this);};  RegexJumpSpace(this)   ;

void RegexForceEmptyLigne(struct Buffer * this) {
    while (1) {
        switch (fgetc(this->fp)) {
            case EOF:
                ErrorSpace(this);
            case 10:
                return;
        }
    }
}

void RegexCommentBloc(struct Buffer * this) {
    while (1) {
loop1:
        switch (fgetc(this->fp)) {
            case EOF:
                ErrorComment(this);
            case 42:
                loop2 :
                switch (fgetc(this->fp)) {
                    case EOF:
                        ErrorComment(this);
                    case 47:
                        return;
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
            RegexForceEmptyLigne(this);
            return;
        case 42:
            RegexCommentBloc(this);
            return;
        default:
            ErrorComment(this);
    }

}



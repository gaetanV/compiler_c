/**
@ERROR
 */
void ErrorComment(struct Buffer * buffer) {
    Error(buffer, "Comment");
}

void ErrorSpace(struct Buffer * buffer) {
    Error(buffer, "Spaces");
}

/**
@@@@@@@
 */

//Regex
#define RegexJumpSpace(this) do{this->ch = fgetc(this->fp);} while (this->ch == 32); 
#define RegexStrictSpaces(this) if(fgetc(this->fp) != 32) {ErrorSpace(this);};  RegexJumpSpace(this)   ;

void RegexForceEmptyLigne(struct Buffer * buffer) {
    while (1) {
        switch (fgetc(buffer->fp)) {
            case EOF:
                ErrorSpace(buffer);
            case 10:
                return;
        }
    }
}

void RegexCommentBloc(struct Buffer * buffer) {
    while (1) {
loop1:
        switch (fgetc(buffer->fp)) {
            case EOF:
                ErrorComment(buffer);
            case 42:
                loop2 :
                switch (fgetc(buffer->fp)) {
                    case EOF:
                        ErrorComment(buffer);
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

void RegexStrictComments(struct Buffer * buffer) {
    switch (fgetc(buffer->fp)) {
        case 47:
            RegexForceEmptyLigne(buffer);
            return;
        case 42:
            RegexCommentBloc(buffer);
            return;
        default:
            ErrorComment(buffer);
    }

}



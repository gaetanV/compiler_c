int RegexAttributDouble(struct sequenceRegex * this) {
    switch (RegexNotSpaceOrEndOfScriptLine(this)) {
        case 0:
            break;
        case 2:
            return 1;
        default:
            if (!RegexEndOfScriptLine(this)) {
                return 0;
            }
             return 1;
    }
    return 0;
}

int parseAttribut(struct sequenceRegex * this) {

    if (!RegexJumpSpace(this)) {
        return 0;
    }
    switch (RegexNotSpaceOrEndOfScriptLineOrDouble(this)) {
        case 0:
            return 0;
        case 1:
            switch (RegexEndOfScriptLineOrDouble(this)) {
                case 0:
                    return 0;
                case 2:
                    return RegexAttributDouble(this);
                case 1:
                    if (!RegexEndOfScriptLine(this)) {
                        return 0;
                    }
            }
            break;
        case 2:
            return 1;
        case 3:
            return RegexAttributDouble(this);
    }
    return 0;
}

int RegexAttributs(struct sequenceRegex * this, int(constructor) (struct sequenceRegex *)) {
    while (1) {
        this->ch = fgetc(this->fp);
        printf("NextO | %c |  %d  \n", this->ch , this->ch);       
        switch (this->ch) {
            case 112:
                printf(">----------------------------- \n");
                printf("Module/Find/Regex p_\n");
                
                
                if (RegexP_(this, parseAttribut)) {
                    printf("Module/End/Regex p_\n");
                    printf("-----------------------------< \n");
                } else {
                    return 0;
                }
                break;
            case 99:
                printf(">----------------------------- \n");
                printf("Module/Find/Regex constructor\n");
                if (RegexConstructor(this)) {
                    if(!RegexFuncNameArgs(this)){
                        return 0;
                    }
                    printf("Module/End/Regex constructor\n");
                    printf("-----------------------------< \n");
                    return 1;
                } else {
                    return 0;
                }
                break;
            case 32:
                break;
            case 10:
                break;
            default:
                return 0;
        }
    }
    return 0;
}
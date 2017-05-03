int MemoryChar(struct sequenceRegex * this,char ch) {
    this->buffer[this->_buffer++] = ch;
}

int Memory(struct sequenceRegex * this) {
    this->buffer[this->_buffer++] = this->ch;
}

int RegexMemoryNotSpaceInlineOrFuncStart(struct sequenceRegex * this) {
    Memory(this);
    while (1) {
        switch (this->ch = fgetc(this->fp)) {
            case EOF:
                return 0;
            case 10:
                return 0;
            case 59:
                return 0;
            case 32:
                return 1;
            case 123:
                return 2;
            default:
                Memory(this);
                break;     
        }
    }
}

int RegexMemoryNotSpaceInline(struct sequenceRegex * this) {
    Memory(this);
    while (1) {
        switch (this->ch = fgetc(this->fp)) {
            case EOF:
                return 0;
            case 10:
                return 0;
            case 59:
                return 0;
            case 32:
                return 1;
            default:
                Memory(this);
                break;
        }
    }
}

int RegexMemoryFuncInner(struct sequenceRegex * this) {
    // Function Start
    while (1) {
        switch (fgetc(this->fp)) {
            case 32:
                break;
            case 23:
                break;
            case 123:
                goto End;
            default:
                return 0;
        }
    }
End:
    this->c = 1;
    do {
        switch (this->ch = fgetc(this->fp)) {
            case EOF:
                return 0;
            case 123:
                this->c++;
                break;
            case 125:
                this->c--;
                break;
            default:
                Memory(this);
                break;
        }
    } while (this->c != 0);
    // Function Stop
    return 1;
}


int MemoryChar(struct sequenceRegex * this, char ch) {
    this->buffer[this->_buffer++] = ch;
}

int MemoryMap(struct sequenceRegex * this) {
    this->pointer[this->_pointer++] = this->_buffer;
}

int Memory(struct sequenceRegex * this) {
    this->buffer[this->_buffer++] = this->ch;
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
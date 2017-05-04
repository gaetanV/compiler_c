int MemoryChar(struct sequenceRegex * this,char ch) {
    this->buffer[this->_buffer++] = ch;
}


int MemoryCmp(struct sequenceRegex * this) {
    this->_cmp=this->_class++;
    this->class[this->_cmp] = 0;
}

int MemoryCmpNext(struct sequenceRegex * this) {
    this->class[this->_cmp]++;
}

int MemoryType(struct sequenceRegex * this,int type) {
    this->class[this->_class++] = type;
    this->class[this->_class++] = -1;
}

int MemoryClass(struct sequenceRegex * this) {
    this->class[this->_class++] = this->_buffer;
}


int MemoryMap(struct sequenceRegex * this) {
    this->class[this->_class++] = this->_buffer;
}


int MemoryExport(struct sequenceRegex * this,int type) {
    this->class[this->_class++] = type;
}



int MemoryAddArgs(struct sequenceRegex * this,int pointer) {
    this->class[this->_class]++;
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
    while(1) {
        switch (this->ch = fgetc(this->fp)) {
            case EOF:
                return 0;
            case 47:
                switch (this->ch=fgetc(this->fp)) {
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
                        MemoryChar(this, 47);
                        Memory(this);
                        break;
                }
                break;
            case 123:
                Memory(this);
                this->c++;
                break;
            case 125:
                
                this->c--;
                if(this->c <= 0){
                    return 1;
                }
                Memory(this);
                break;
            default:
                Memory(this);
                break;
        }
    } 
    // Function Stop
 
}


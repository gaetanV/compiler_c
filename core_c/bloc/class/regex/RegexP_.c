int RegexRivateOrFunc(struct Buffer * buffer) {

    // REGEX rivate Start at 114

    if ((buffer->ch = fgetc(buffer->fp)) != 105) {
        
        MemoryChar(buffer, 112);
        MemoryChar(buffer, 114);
        return 0;
    }
    if ((buffer->ch = fgetc(buffer->fp)) != 118) {
     
        MemoryChar(buffer, 112);
        MemoryChar(buffer, 114);
        MemoryChar(buffer, 105);
        return 0;
    }
    if ((buffer->ch = fgetc(buffer->fp)) != 97) {
     
        MemoryChar(buffer, 112);
        MemoryChar(buffer, 114);
        MemoryChar(buffer, 105);
        MemoryChar(buffer, 118);
        return 0;
    }
    if ((buffer->ch = fgetc(buffer->fp)) != 116) {

        MemoryChar(buffer, 112);
        MemoryChar(buffer, 114);
        MemoryChar(buffer, 105);
        MemoryChar(buffer, 118);
        MemoryChar(buffer, 97);
        return 0;
    }
    if ((buffer->ch = fgetc(buffer->fp)) != 101) {
     
        MemoryChar(buffer, 112);
        MemoryChar(buffer, 114);
        MemoryChar(buffer, 105);
        MemoryChar(buffer, 118);
        MemoryChar(buffer, 97);
        MemoryChar(buffer, 116);
        return 0;
    }

    return 1;

}

int RegexUblicOrFunc(struct Buffer * buffer) {

    // REGEX ublic Start at 117

    if ((buffer->ch = fgetc(buffer->fp)) != 98) {
    
        MemoryChar(buffer, 112);
        MemoryChar(buffer, 117);
        return 0;
    }
    if ((buffer->ch = fgetc(buffer->fp)) != 108) {

        MemoryChar(buffer, 112);
        MemoryChar(buffer, 117);
        MemoryChar(buffer, 98);
        return 0;
    }
    if ((buffer->ch = fgetc(buffer->fp)) != 105) {

        MemoryChar(buffer, 112);
        MemoryChar(buffer, 117);
        MemoryChar(buffer, 98);
        MemoryChar(buffer, 108);
        return 0;
    }
    if ((buffer->ch = fgetc(buffer->fp)) != 99) {
      
        MemoryChar(buffer, 112);
        MemoryChar(buffer, 117);
        MemoryChar(buffer, 98);
        MemoryChar(buffer, 108);
        MemoryChar(buffer, 105);
        return 0;
    }
    return 1;
}

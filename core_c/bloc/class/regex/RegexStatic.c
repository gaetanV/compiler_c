int RegexStaticOrFunc(struct Buffer * buffer) {

    // REGEX ublic Start at 115

    if ((buffer->ch = fgetc(buffer->fp)) != 116) {
  
        MemoryChar(buffer, 115);
        return 0;
    }
    if ((buffer->ch = fgetc(buffer->fp)) != 97) {

        MemoryChar(buffer, 115);
        MemoryChar(buffer, 116);
        return 0;
    }
    if ((buffer->ch = fgetc(buffer->fp)) != 116) {

        MemoryChar(buffer, 115);
        MemoryChar(buffer, 116);
        MemoryChar(buffer, 97);
        return 0;
    }
    if ((buffer->ch = fgetc(buffer->fp)) != 105) {
 
        MemoryChar(buffer, 115);
        MemoryChar(buffer, 116);
        MemoryChar(buffer, 97);
        MemoryChar(buffer, 116);
        return 0;
    }
    if ((buffer->ch = fgetc(buffer->fp)) != 99) {
     
        MemoryChar(buffer, 115);
        MemoryChar(buffer, 116);
        MemoryChar(buffer, 97);
        MemoryChar(buffer, 116);
        MemoryChar(buffer, 105);
        return 0;
    }

    return 1;

}
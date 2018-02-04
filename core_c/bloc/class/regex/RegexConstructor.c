int RegexConstructorOrFunc(struct Buffer * buffer) {

    // REGEX CONSTRUCT Start at 99

    if ((buffer->ch = fgetc(buffer->fp)) != 111) {
      
        MemoryChar(buffer, 99);
        MemoryChar(buffer, buffer->ch);
        return 0;
    }

    if ((buffer->ch = fgetc(buffer->fp)) != 110) {
     
        MemoryChar(buffer, 99);
        MemoryChar(buffer, 111);
        return 0;
    }
    if ((buffer->ch = fgetc(buffer->fp)) != 115) {
 
        MemoryChar(buffer, 99);
        MemoryChar(buffer, 111);
        MemoryChar(buffer, 110);
        return 0;
    }

    if ((buffer->ch = fgetc(buffer->fp)) != 116) {
   
        MemoryChar(buffer, 99);
        MemoryChar(buffer, 111);
        MemoryChar(buffer, 110);
        MemoryChar(buffer, 115);
        return 0;
    }

    if ((buffer->ch = fgetc(buffer->fp)) != 114) {

        MemoryChar(buffer, 99);
        MemoryChar(buffer, 111);
        MemoryChar(buffer, 110);
        MemoryChar(buffer, 115);
        MemoryChar(buffer, 116);
        return 0;
    }

    if ((buffer->ch = fgetc(buffer->fp)) != 117) {

        MemoryChar(buffer, 99);
        MemoryChar(buffer, 111);
        MemoryChar(buffer, 110);
        MemoryChar(buffer, 115);
        MemoryChar(buffer, 116);
        MemoryChar(buffer, 114);
        return 0;
    }

    if ((buffer->ch = fgetc(buffer->fp)) != 99) {

        MemoryChar(buffer, 99);
        MemoryChar(buffer, 111);
        MemoryChar(buffer, 110);
        MemoryChar(buffer, 115);
        MemoryChar(buffer, 116);
        MemoryChar(buffer, 114);
        MemoryChar(buffer, 117);
        return 0;
    }

    if ((buffer->ch = fgetc(buffer->fp)) != 116) {

        MemoryChar(buffer, 99);
        MemoryChar(buffer, 111);
        MemoryChar(buffer, 110);
        MemoryChar(buffer, 115);
        MemoryChar(buffer, 116);
        MemoryChar(buffer, 114);
        MemoryChar(buffer, 117);
        MemoryChar(buffer, 99);
        return 0;
    }

    if ((buffer->ch = fgetc(buffer->fp)) != 111) {
   
        MemoryChar(buffer, 99);
        MemoryChar(buffer, 111);
        MemoryChar(buffer, 110);
        MemoryChar(buffer, 115);
        MemoryChar(buffer, 116);
        MemoryChar(buffer, 114);
        MemoryChar(buffer, 117);
        MemoryChar(buffer, 99);
        MemoryChar(buffer, 116);
        return 0;
    }

    if ((buffer->ch = fgetc(buffer->fp)) != 114) {

        MemoryChar(buffer, 99);
        MemoryChar(buffer, 111);
        MemoryChar(buffer, 110);
        MemoryChar(buffer, 115);
        MemoryChar(buffer, 116);
        MemoryChar(buffer, 114);
        MemoryChar(buffer, 117);
        MemoryChar(buffer, 99);
        MemoryChar(buffer, 116);
        MemoryChar(buffer, 111);
        return 0;
    }

    return 1;
    
}
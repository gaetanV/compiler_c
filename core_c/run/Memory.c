int MemoryChar(struct Buffer * this, char ch) {
    this->buffer[this->_buffer++] = ch;
}

int MemoryMap(struct Buffer * this) {
    this->pointer[this->_pointer++] = this->_buffer;
}

int Memory(struct Buffer * this) {
    this->buffer[this->_buffer++] = this->ch;
}
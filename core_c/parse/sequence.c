#include <stdio.h>

struct sequence {
    int seq;
    int stL ;
} ;

void startSequence (struct sequence *this,int val) {
    printf("seq%d in \n",val);
    this->seq = val;  
    this->stL = 1;
};

void endLigne (struct sequence *this) {
    this->stL = 2; 
};

void stopSequence (struct sequence *this) {
    this->seq = 0;
};

void emptyLigne (struct sequence *this) {
    printf("seq%d all out \n", this->seq);
    stopSequence(this);
    this->stL = 2;  
};

void startLigne (struct sequence *this) {
    this->stL = 0;  
    printf("new line sequence %d out \n", this->seq);
};

void constructSequence (struct sequence *this) {
    this->seq = 0;  
    startLigne(this);
};

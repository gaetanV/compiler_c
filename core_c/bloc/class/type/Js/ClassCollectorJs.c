#include <stdbool.h>

struct ClassCollectorJs {
     
    unsigned short startPointer;
    
    bool hasConstructor;
    bool hasExtends;
    unsigned short constructor [2];

    int attrStatic[20];
    int _attrStatic;
    int func[20];
    int _func;
    int funcStatic[20];
    int _funcStatic;

};


struct ClassCollectorJs *newClassCollectorJs(unsigned short pointer) {

    struct ClassCollectorJs *y = malloc(sizeof (struct ClassCollectorJs));
    
    y->hasConstructor = 0;
    y->_attrStatic = 0;
    y->_funcStatic = 0;
    y->_func = 0;
    
    y->startPointer = pointer;

    return y;
}


int PrintClassCollectorJs(struct Buffer * this, struct ClassCollectorJs * collector) {
    
    

    printf(">>>>>>>>>>>>>\n");
    for (int i = 0; i < this->_pointer; i++) {
        printf(" %d \n", this->pointer[i]);

    }
    
    printf(">>>>>>>>>>>>>\n");
    
    printf(" %d \n", collector->startPointer);
    printf(" %d \n", collector->hasConstructor);
    printf(" %d \n", collector->hasExtends);

    
    printf("Constructor \n");
    for (int i = 0; i < 2; i++) {
        printf(" %d \n", collector->constructor[i]);
    }
    
    
 
    printf("Func \n");
    for (int i = 0; i < collector->_func; i++) {
        printf(" %d \n", collector->func[i]);
    }

    printf("Func Static \n");
    for (int i = 0; i < collector->_funcStatic; i++) {
        printf(" %d \n", collector->funcStatic[i]);
    }
 

    printf("Attr Static \n");
    for (int i = 0; i < collector->_attrStatic; i++) {
        printf(" %d \n", collector->attrStatic[i]);
    }

}


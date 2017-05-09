#include <stdbool.h>

struct ClassCollectorUnity {
    
    unsigned short startPointer;
    bool hasExtends;
    bool hasConstructor;
    
    unsigned short constructor [3];

        
    int attrPublic[10];
    int _attrPublic;  
    
    int attrStatic[10];
    int _attrStatic;
    
    int attrPrivate[10];
    int _attrPrivate;  
    
    int func[20];
    int _func;
    
    int funcStatic[10];
    int _funcStatic;
    
    int funcPrivate[10];
    int _funcPrivate;
   
    
};


struct ClassCollectorUnity *newClassCollectorUnity (unsigned short pointer) {
    
    struct ClassCollectorUnity *y = malloc (sizeof (struct ClassCollectorUnity));
    

    y->_attrPublic = 0; 
    y->_attrPrivate = 0; 
    y->_attrStatic = 0;
    y->_funcPrivate = 0;
    y->_funcStatic = 0;
    y->_func = 0;

    y->startPointer = pointer;
    

    return y;   
}




int PrintClassUnityCollector(struct Buffer * this,struct ClassCollectorUnity * collector){
    
    printf(">>>>>>>>>>>>>\n");
    for (int i = 0; i < this->_pointer; i++) {
        printf(" %d \n", this->pointer[i]);

    }

  
    printf("Func \n");
    for (int i = 0; i < collector->_func; i++) {
        printf(" %d \n", collector->func[i]);
    }
    
    printf("Func Static \n");
    for (int i = 0; i < collector->_funcStatic; i++) {
        printf(" %d \n", collector->funcStatic[i]);
    }
    printf("Func Private\n");
    for (int i = 0; i < collector->_funcPrivate; i++) {
        printf(" %d \n", collector->funcPrivate[i]);
    }
    
    
    printf("Attr Static \n");
    for (int i = 0; i < collector->_attrStatic; i++) {
        printf(" %d \n", collector->attrStatic[i]);
    }
    
    printf("Attr Private \n");
    for (int i = 0; i < collector->_attrPrivate; i++) {
        printf(" %d \n", collector->attrPrivate[i]);
    }
    
   
}


#include <stdbool.h>
struct ClassCollector {
   
    int module[6];
        
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
    
    bool type[30];
    int _type;
    
};

int ClassCollectorInit(struct ClassCollector * this,int pointer) {
    
    this->_attrPublic = 0; 
    this->_attrPrivate = 0; 
    this->_attrStatic = 0;
    this->_funcPrivate = 0;
    this->_funcStatic = 0;
    this->_func = 0;
    this->_type = 0;

    this->module[0] = pointer;
    // 0 Char pointer
    // 1 Extends
    // 2 Implements
    // 3 Char pointer constructor  ???
    this->module[3] = -1;
    // 4 Nb arguments
    this->module[4] = 0;
    // 5 Type pointer
    
}

int ClassCollectorPrint(struct sequenceRegex * this, struct ClassCollector * collector) {
    

    printf(">>>>>>>>>>>>>\n");
    for (int i = 0; i < this->_pointer; i++) {
        printf(" %d \n", this->pointer[i]);

    }

    printf(">>>>>>>>>>>>>\n");
    for (int i = 0; i < 6; i++) {
        printf(" %d \n", collector->module[i]);

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
    
    printf("Type \n");
    for (int i = 0; i < collector->_type; i++) {
        printf(" %d \n", collector->type[i]);
    }
    
}

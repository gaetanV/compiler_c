struct ClassCollector {
   
    int module[6];
    int _module;
    
    int attrStatic[10];
    int _attrStatic;
    
    int func[20];
    int _func;
    
    int funcStatic[10];
    int _funcStatic;
    
    int funcPrivate[10];
    int _funcPrivate;
    
};

int ClassCollectorInit(struct ClassCollector * this) {
    
    this->_attrStatic = 0;
    this->_funcPrivate = 0;
    this->_funcStatic = 0;
    this->_func = 0;
    this->_module = 0;

}

int ClassCollectorPrint(struct sequenceRegex * this, struct ClassCollector * collector) {
    

    printf(">>>>>>>>>>>>>\n");
    for (int i = 0; i < this->_pointer; i++) {
        printf(" %d \n", this->pointer[i]);

    }

    printf(">>>>>>>>>>>>>\n");
    for (int i = 0; i < collector->_module; i++) {
        printf(" %d \n", collector->module[i]);

    }
    printf(">>>>>>>>>>>>>\n");
    for (int i = 0; i < collector->_func; i++) {
        printf(" %d \n", collector->func[i]);
    }
    printf(">>>>>>>>>>>>>\n");
    for (int i = 0; i < collector->_funcStatic; i++) {
        printf(" %d \n", collector->funcStatic[i]);
    }
    
    printf(">>>>>>>>>>>>>\n");
    for (int i = 0; i < collector->_attrStatic; i++) {
        printf(" %d \n", collector->attrStatic[i]);
    }

}

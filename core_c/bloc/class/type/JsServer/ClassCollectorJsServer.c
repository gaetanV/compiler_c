#include <stdbool.h>

struct ClassCollectorJsServer {
    unsigned short startPointer;

    bool hasConstructor;
    bool hasExtends;
    bool hasImplements;

    unsigned short constructor [3];

    int attrPublic[20];
    int _attrPublic;

    int attrStatic[20];
    int _attrStatic;

    int attrPrivate[20];
    int _attrPrivate;

    int func[20];
    int _func;

    int funcStatic[20];
    int _funcStatic;

    int funcPrivate[20];
    int _funcPrivate;

    bool type[30];
    int _type;

};

/**
@CONSTRUCTOR
 */

struct ClassCollectorJsServer *newClassCollectorJsServer(unsigned short pointer) {

    struct ClassCollectorJsServer *y = (ClassCollectorJsServer*) malloc(sizeof (struct ClassCollectorJsServer));

    y->hasConstructor = 0;

    y->_attrPublic = 0;
    y->_attrPrivate = 0;
    y->_attrStatic = 0;
    y->_funcPrivate = 0;
    y->_funcStatic = 0;
    y->_func = 0;
    y->_type = 0;

    y->startPointer = pointer;

    return y;
}

int PrintClassCollectorServer(struct Buffer * buffer, struct ClassCollectorJsServer * collector) {
    printf(">>>>>>>>>>>>>\n");
    for (int i = 0; i < buffer->_pointer; i++) {
        printf(" %d \n", buffer->pointer[i]);

    }

    printf(">>>>>>>>>>>>>\n");

    printf(" %d \n", collector->startPointer);

    printf(" %d \n", collector->hasConstructor);
    printf(" %d \n", collector->hasExtends);
    printf(" %d \n", collector->hasImplements);



    printf("Constructor \n");
    for (int i = 0; i < 3; i++) {
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
    return 1;

}


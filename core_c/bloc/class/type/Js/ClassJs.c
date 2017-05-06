#include <stdio.h>

int ClassJs(struct sequenceRegex * this, struct ClassCollector * collector) {

    MemoryMap(this);

    // Get the name
    collector->module[collector->_module++] = this->_pointer - 2;

    switch (RegexExtendsStartClass(this)) {
        case 0:
            printf("Error in class format extends \n");
            exit(0);
        case 1:
            collector->module[collector->_module++] = 0;
        case 2:
            collector->module[collector->_module++] = 1;
            MemoryMap(this);
            break;
    }

    int construct = collector->_module++;

    collector->module[construct] = -1;
    collector->module[collector->_module++] = 0;


    while (1) {
        switch (this->ch = fgetc(this->fp)) {
            case 32:
                break;
            case 10:
                break;
            case 47:
                RegexStrictComments(this);
                break;
            case 99:
                if (RegexConstructorOrFunc(this)) {
                    if (collector->module[construct] != -1) {
                        printf("Error Only one Constructor \n");
                        exit(0);
                    }
                    collector->module[construct] = this->_pointer - 1;

                    if (!RegexFuncArgs(this)) {
                        return 0;
                    }
                    MemoryMap(this);
                    collector->module[construct + 1] = this->_cmp;
                } else {
                    CollectorFuncNameArgs(
                            this, 
                            &collector->_func,
                            collector->func
                    );
                }
                break;
            case 115:
                if (RegexStaticOrFunc(this)) {
                    if (!RegexJumpSpace(this)) {
                        return 0;
                    }
                    CollectorFuncNameArgsOrAttr(
                            this,
                            &collector->_funcStatic,
                            collector->funcStatic,
                            &collector->_attrStatic,
                            collector->attrStatic
                    );

                } else {
                    CollectorFuncNameArgs(
                            this, 
                            &collector->_func, 
                            collector->func
                    );
                }
                break;
            default:
                CollectorFuncNameArgs(
                        this, &collector->_func,
                        collector->func
                );
                break;
            case EOF:
                return 0;
            case 125:
                return 1;

        }
    }
    return 0;
}

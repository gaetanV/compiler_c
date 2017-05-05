#include <stdio.h>

int OutputClassJsEcma6(struct sequenceRegex * this) {

    printf("%s\n", this->buffer);
    char output[255]= {};

    this->c = this->import[0];

    for (int i = 0; i < this->import[1]; i++) {
        /// Import 
        strncat(output,
                (this->buffer + this->pointer[this->c]),
                (this->pointer[(this->c + 1)] - this->pointer[this->c])
                );
        this->c++;


        /// Import Name
        strncat(output,
                (this->buffer + this->pointer[this->c]),
                (this->pointer[(this->c + 1)] - this->pointer[this->c])
                );

        this->c++;
    }

    for (int i = 0; i < this->_module; i++) {

        this->c = this->module[i];

        /// Module Name

        strncat(output,
                (this->buffer + this->pointer[this->c]),
                (this->pointer[(this->c + 1)] - this->pointer[this->c])
                );
        this->c++;



        /// Extends

        if (this->module[++i] == 1) {
            /// Module Extends
            strncat(output,
                    (this->buffer + this->pointer[this->c]),
                    (this->pointer[(this->c + 1)] - this->pointer[this->c])
                    );
        }



        // Constructor
        if (this->module[++i] != -1) {

            this->c = this->module[i];

             i++;

            for (int j = 0; j < this->module[i]; j++) {
                /// Constructor Args
                strncat(output,
                        (this->buffer + this->pointer[this->c]),
                        (this->pointer[(this->c + 1)] - this->pointer[this->c])
                        );
                this->c++;
            }


            /// Constructor Inner
            strncat(output,
                    (this->buffer + this->pointer[this->c]),
                    (this->pointer[(this->c + 1)] - this->pointer[this->c])
                    );
         
   
        } else {
            i++;
        }
   
        int z = this->module[++i];
        i++;
  
        for (int j = 0; j < this->module[i]; j++) {
            
            /// Func
            this->c = this->func[z];      
            /// Func Name
            strncat(output,
                    (this->buffer + this->pointer[this->c]),
                    (this->pointer[(this->c + 1)] - this->pointer[this->c])
                    );
            
            this->c++;
            z++;
           for (int k = 0; k < this->func[z]; k++) {      
                /// Func Args 
                strncat(output,
                        (this->buffer + this->pointer[this->c]),
                        (this->pointer[(this->c + 1)] - this->pointer[this->c])
                        );
                this->c++;
              }
           z++;  
            /// Func Inner
           strncat(output,
                        (this->buffer + this->pointer[this->c]),
                        (this->pointer[(this->c + 1)] - this->pointer[this->c])
                        );
           this->c++;
        }
        
        z = this->module[++i];
        
        i++;
        for (int j = 0; j < this->module[i]; j++) {
            
            /// Func
            this->c = this->funcStatic[z];      
            /// Func Static Name
            strncat(output,
                    (this->buffer + this->pointer[this->c]),
                    (this->pointer[(this->c + 1)] - this->pointer[this->c])
                    );
            
            this->c++;
            z++;
           for (int k = 0; k < this->funcStatic[z]; k++) {      
                /// Func Static Args 
                strncat(output,
                        (this->buffer + this->pointer[this->c]),
                        (this->pointer[(this->c + 1)] - this->pointer[this->c])
                        );
                this->c++;
              }
           z++;  
            /// Func Static Inner
           strncat(output,
                        (this->buffer + this->pointer[this->c]),
                        (this->pointer[(this->c + 1)] - this->pointer[this->c])
                        );
           this->c++;
        }
        
  
    }


    for (int i = 0; i < this->_pointer; i++) {
        printf(" %d \n", this->pointer[i]);

    }
    
    printf(">>>>>>>>>>>>>\n");
    for (int i = 0; i < this->_module; i++) {
        printf(" %d \n", this->module[i]);

    }
    printf(">>>>>>>>>>>>>\n");
    for (int i = 0; i < this->_func; i++) {
        printf(" %d \n", this->func[i]);
    }
    printf(">>>>>>>>>>>>>\n");
    for (int i = 0; i < this->_funcStatic; i++) {
        printf(" %d \n", this->funcStatic[i]);
    }
    
   
    printf("\n%s\n", output);
}

int ClassJs(struct sequenceRegex * this) {

    MemoryMap(this);


    switch (RegexExtendsStartClass(this)) {
        case 0:
            printf("Error in class format extends \n");
            return 0;
        case 1:
            this->module[this->_module++] = 0;
        case 2:
            this->module[this->_module++] = 1;
            MemoryMap(this);
            break;
    }

    int construct = this->_module++;

    this->module[construct] = -1;
    this->module[this->_module++] = -1;

  
    this->module[this->_module++] = this->_func;
    int func = this->_module++;
    
    this->module[this->_module++] = this->_funcStatic;
    int funcStatic = this->_module++;
    
    this->module[func] =0;
   
    while (1) {
        switch (this->ch=fgetc(this->fp)) {
            case 32:
                break;
            case 10:
                break;
            case 47:
                if (!RegexComments(this)) {
                    return 0;
                }
                break;
            case 99:
                if (RegexConstructorOrFunc(this)) {
                    if(this->module[construct]!=-1){
                        printf("Error Only one Constructor \n");
                    }
                    this->module[construct] = this->_pointer - 1;

                    if (!RegexFuncArgs(this)) {
                        return 0;
                    }
                    MemoryMap(this);
                    this->module[construct + 1] = this->_cmp;

                } else {
                    
                    this->func[this->_func++] = this->_pointer - 1;
                    if (!RegexFuncNameArgs(this)) {
                        printf("Error in class format function \n");
                        return 0;
                    }
                    this->module[func]++;
                    this->func[this->_func++] = this->_cmp;
                    MemoryMap(this);      
                          
                }
                break;
            case 115:
                if (RegexStaticOrFunc(this)) {
                    if (!RegexJumpSpace(this)) {
                        return 0;
                    }
                    this->funcStatic[this->_funcStatic++] = this->_pointer - 1;
                    if (!RegexFuncNameArgs(this)) {
                        printf("Error in class format function static \n");
                        return 0;
                    }
                    this->module[funcStatic]++;
                    this->funcStatic[this->_funcStatic++] = this->_cmp;
                    MemoryMap(this);   
                    
                } else {
                    printf("Module/End/Regex Func\n");
                    
                    this->func[this->_func++] = this->_pointer - 1;
                    if (!RegexFuncNameArgs(this)) {
                        printf("Error in class format function \n");
                        return 0;
                    }
                    this->module[func]++;
                    this->func[this->_func++] = this->_cmp;
                    MemoryMap(this);      
                    
                }
              
                break;
            default:
                
                this->func[this->_func++] = this->_pointer - 1;
                if (!RegexFuncNameArgs(this)) {
                    printf("Error in class format function \n");
                    return 0;
                }
                this->module[func]++;
                this->func[this->_func++] = this->_cmp;
                MemoryMap(this);   

                break;
            case EOF:
                return 0;
            case 125:
                return 1;

        }
    }
    return 0;
}

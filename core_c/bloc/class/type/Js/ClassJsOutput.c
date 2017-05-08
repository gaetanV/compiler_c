#include <stdio.h>

int ClassJsOutput(struct sequenceRegex * this, struct ClassCollector * collector) {

    
    printf("%s\n", this->buffer);
    
    this->buffer[this->_buffer]= '\0' ;
    
    this->c = 0;
    
    ClassCollectorPrint(this,collector);
    
  
    for (int i = 0; i < this->import; i++) {
        /// Import 
        strncat(this->output,
                (this->buffer + this->pointer[this->c]),
                (this->pointer[(this->c + 1)] - this->pointer[this->c] )
                );
        this->c++;


        /// Import Name
        strncat(this->output,
                (this->buffer + this->pointer[this->c]),
                (this->pointer[(this->c + 1)] - this->pointer[this->c])
                );

        this->c++;
    }



    this->c = collector->module[0];


    /// Module Name

    strncat(this->output,
            (this->buffer + this->pointer[this->c]),
            (this->pointer[(this->c + 1)] - this->pointer[this->c])
            );
    this->c++;



    /// Extends

    if (collector->module[1] == 1) {

        /// Module Extends
        strncat(this->output,
                (this->buffer + this->pointer[this->c]),
                (this->pointer[(this->c + 1)] - this->pointer[this->c])
                );
          this->c++;
    }
    
  
  
    // Constructor
    if (collector->module[3] != -1) {

        this->c = collector->module[3];


        for (int j = 0; j < collector->module[4]; j++) {
            /// Constructor Args
            strncat(this->output,
                    (this->buffer + this->pointer[this->c]),
                    (this->pointer[(this->c + 1)] - this->pointer[this->c])
                    );
            this->c++;
        }


        /// Constructor Inner
        strncat(this->output,
                (this->buffer + this->pointer[this->c]),
                (this->pointer[(this->c + 1)] - this->pointer[this->c])
                );


    }
    
        for (int j = 0; j < collector->_attrStatic; j++) {
           
        /// Func Attribute Static
        this->c = collector->attrStatic[j];
        /// Func Attribute Static Name
        strncat(this->output,
                (this->buffer + this->pointer[this->c]),
                (this->pointer[(this->c + 1)] - this->pointer[this->c])
                );

        this->c++;
    }
    

    for (int j = 0; j < collector->_func; j++) {
        /// Func
        this->c = collector->func[j];
        /// Func Name
        strncat(this->output,
                (this->buffer + this->pointer[this->c]),
                (this->pointer[(this->c + 1)] - this->pointer[this->c])
                );

        this->c++;

        j++;

        for (int k = 0; k < collector->func[j]; k++) {
            /// Func Args 
            strncat(this->output,
                    (this->buffer + this->pointer[this->c]),
                    (this->pointer[(this->c + 1)] - this->pointer[this->c])
                    );
            this->c++;
        }

        /// Func Inner
        strncat(this->output,
                (this->buffer + this->pointer[this->c]),
                (this->pointer[(this->c + 1)] - this->pointer[this->c])
                );

    }

    for (int j = 0; j < collector->_funcStatic; j++) {
        
      
        /// Func Static
        this->c = collector->funcStatic[j];
        /// Func Static Name
        strncat(this->output,
                (this->buffer + this->pointer[this->c]),
                (this->pointer[(this->c + 1)] - this->pointer[this->c])
                );

        this->c++;

        j++;

        for (int k = 0; k < collector->funcStatic[j]; k++) {
            /// Func Static Args 
            strncat(this->output,
                    (this->buffer + this->pointer[this->c]),
                    (this->pointer[(this->c + 1)] - this->pointer[this->c])
                    );
            this->c++;
        }

        /// Func Static Inner
        strncat(this->output,
                (this->buffer + this->pointer[this->c]),
                (this->pointer[(this->c + 1)] - this->pointer[this->c])
                );
    }
    


    printf("\n%s\n", this->output);

}
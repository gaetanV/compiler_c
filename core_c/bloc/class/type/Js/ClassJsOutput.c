#include <stdio.h>

int ClassJsOutput(struct Buffer * this, struct ClassCollectorJs * collector) {

    
    printf("%s\n", this->buffer);
    
    this->buffer[this->_buffer]= '\0' ;
    
    this->c = 0;
    
    PrintClassCollectorJs(this,collector);
    
  
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



    this->c = collector->startPointer;


    /// Module Name

    strncat(this->output,
            (this->buffer + this->pointer[this->c]),
            (this->pointer[(this->c + 1)] - this->pointer[this->c])
            );
    this->c++;



    /// Extends

    if (collector->hasExtends == 1) {

        /// Module Extends
        strncat(this->output,
                (this->buffer + this->pointer[this->c]),
                (this->pointer[(this->c + 1)] - this->pointer[this->c])
                );
          this->c++;
    }
    
  
  
    // Constructor
    if (collector->hasConstructor == 1) {

        this->c = collector->constructor[0];


        for (int j = 0; j < collector->constructor[1]; j++) {
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
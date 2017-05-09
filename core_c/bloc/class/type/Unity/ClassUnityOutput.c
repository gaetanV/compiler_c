#include <stdio.h>



int ClassUnityOutput(struct Buffer * this, struct ClassCollectorUnity * collector) {


    printf("%s\n", this->buffer);

    this->buffer[this->_buffer] = '\0';

    this->c = 0;

    PrintClassUnityCollector(this,collector);


    for (int i = 0; i < this->import; i++) {
        /// Import 
        strncat(this->output,
                (this->buffer + this->pointer[this->c]),
                (this->pointer[(this->c + 1)] - this->pointer[this->c])
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


            /// Constructor Args Type
            strncat(this->output,
                    (this->buffer + this->pointer[this->c]),
                    (this->pointer[(this->c + 1)] - this->pointer[this->c])
                    );
            this->c++;

            /// Constructor Args Name


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
        /// Func Attribute Static Type
        strncat(this->output,
                (this->buffer + this->pointer[this->c]),
                (this->pointer[(this->c + 1)] - this->pointer[this->c])
                );

        this->c++;
        /// Func Attribute Static Name
        strncat(this->output,
                (this->buffer + this->pointer[this->c]),
                (this->pointer[(this->c + 1)] - this->pointer[this->c])
                );
        this->c++;

    }
    for (int j = 0; j < collector->_attrPrivate; j++) {

        /// Func Attribute Private
        this->c = collector->attrPrivate[j];
        /// Func Attribute Private Type
        strncat(this->output,
                (this->buffer + this->pointer[this->c]),
                (this->pointer[(this->c + 1)] - this->pointer[this->c])
                );

        this->c++;
        /// Func Attribute Private Name
        strncat(this->output,
                (this->buffer + this->pointer[this->c]),
                (this->pointer[(this->c + 1)] - this->pointer[this->c])
                );
        this->c++;

    }
   for (int j = 0; j < collector->_attrPublic; j++) {

        /// Func Attribute Public
        this->c = collector->attrPublic[j];
        /// Func Attribute Public Type
        strncat(this->output,
                (this->buffer + this->pointer[this->c]),
                (this->pointer[(this->c + 1)] - this->pointer[this->c])
                );

        this->c++;
        /// Func Attribute Public Name
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
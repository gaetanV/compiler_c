#include <stdio.h>

int ClassJsServerOutput(struct Buffer * buffer, struct ClassCollectorJsServer * collector) {


    printf("%s\n", buffer->buffer);

    buffer->buffer[buffer->_buffer] = '\0';

    buffer->c = 0;
    PrintClassCollectorServer(buffer, collector);



    for (int i = 0; i < buffer->import; i++) {
        /// Import 
        strncat(buffer->output,
                (buffer->buffer + buffer->pointer[buffer->c]),
                (buffer->pointer[(buffer->c + 1)] - buffer->pointer[buffer->c])
                );
        buffer->c++;


        /// Import Name
        strncat(buffer->output,
                (buffer->buffer + buffer->pointer[buffer->c]),
                (buffer->pointer[(buffer->c + 1)] - buffer->pointer[buffer->c])
                );

        buffer->c++;
    }



    buffer->c = collector->startPointer;


    /// Module Name

    strncat(buffer->output,
            (buffer->buffer + buffer->pointer[buffer->c]),
            (buffer->pointer[(buffer->c + 1)] - buffer->pointer[buffer->c])
            );
    buffer->c++;



    /// Extends

    if (collector->hasExtends == 1) {

        /// Module Extends
        strncat(buffer->output,
                (buffer->buffer + buffer->pointer[buffer->c]),
                (buffer->pointer[(buffer->c + 1)] - buffer->pointer[buffer->c])
                );
        buffer->c++;
    }

    if (collector->hasImplements == 1) {

        /// Module Implements
        strncat(buffer->output,
                (buffer->buffer + buffer->pointer[buffer->c]),
                (buffer->pointer[(buffer->c + 1)] - buffer->pointer[buffer->c])
                );
    }



    // Constructor
    if (collector->hasConstructor == 1) {

        buffer->c = collector->constructor[0];
        int z = collector->constructor[2];

        for (int j = 0; j < collector->constructor[1]; j++) {


            /// Constructor Args
            strncat(buffer->output,
                    (buffer->buffer + buffer->pointer[buffer->c]),
                    (buffer->pointer[(buffer->c + 1)] - buffer->pointer[buffer->c])
                    );
            buffer->c++;
            /// Constructor Args Type
            z++;
            if (collector->type[z] == 1) {
                strncat(buffer->output,
                        (buffer->buffer + buffer->pointer[buffer->c]),
                        (buffer->pointer[(buffer->c + 1)] - buffer->pointer[buffer->c])
                        );
                buffer->c++;
            }
        }


        /// Constructor Inner
        strncat(buffer->output,
                (buffer->buffer + buffer->pointer[buffer->c]),
                (buffer->pointer[(buffer->c + 1)] - buffer->pointer[buffer->c])
                );


    }


    for (int j = 0; j < collector->_attrStatic; j++) {

        /// Func Attribute Static
        buffer->c = collector->attrStatic[j];
        /// Func Attribute Static Name
        strncat(buffer->output,
                (buffer->buffer + buffer->pointer[buffer->c]),
                (buffer->pointer[(buffer->c + 1)] - buffer->pointer[buffer->c])
                );

        buffer->c++;
    }
    for (int j = 0; j < collector->_attrPrivate; j++) {

        /// Func Attribute Static
        buffer->c = collector->attrPrivate[j];
        /// Func Attribute Static Name
        strncat(buffer->output,
                (buffer->buffer + buffer->pointer[buffer->c]),
                (buffer->pointer[(buffer->c + 1)] - buffer->pointer[buffer->c])
                );

        buffer->c++;
    }


    for (int j = 0; j < collector->_func; j++) {
        /// Func
        buffer->c = collector->func[j];
        /// Func Name
        strncat(buffer->output,
                (buffer->buffer + buffer->pointer[buffer->c]),
                (buffer->pointer[(buffer->c + 1)] - buffer->pointer[buffer->c])
                );

        buffer->c++;

        j++;

        for (int k = 0; k < collector->func[j]; k++) {
            /// Func Args 
            strncat(buffer->output,
                    (buffer->buffer + buffer->pointer[buffer->c]),
                    (buffer->pointer[(buffer->c + 1)] - buffer->pointer[buffer->c])
                    );
            buffer->c++;
        }

        /// Func Inner
        strncat(buffer->output,
                (buffer->buffer + buffer->pointer[buffer->c]),
                (buffer->pointer[(buffer->c + 1)] - buffer->pointer[buffer->c])
                );

    }

    for (int j = 0; j < collector->_funcStatic; j++) {


        /// Func Static
        buffer->c = collector->funcStatic[j];
        /// Func Static Name
        strncat(buffer->output,
                (buffer->buffer + buffer->pointer[buffer->c]),
                (buffer->pointer[(buffer->c + 1)] - buffer->pointer[buffer->c])
                );

        buffer->c++;

        j++;

        for (int k = 0; k < collector->funcStatic[j]; k++) {
            /// Func Static Args 
            strncat(buffer->output,
                    (buffer->buffer + buffer->pointer[buffer->c]),
                    (buffer->pointer[(buffer->c + 1)] - buffer->pointer[buffer->c])
                    );
            buffer->c++;
        }

        /// Func Static Inner
        strncat(buffer->output,
                (buffer->buffer + buffer->pointer[buffer->c]),
                (buffer->pointer[(buffer->c + 1)] - buffer->pointer[buffer->c])
                );
    }
    
    for (int j = 0; j < collector->_funcPrivate; j++) {
        /// Func Private
        buffer->c = collector->funcPrivate[j];
        /// Func Name
        strncat(buffer->output,
                (buffer->buffer + buffer->pointer[buffer->c]),
                (buffer->pointer[(buffer->c + 1)] - buffer->pointer[buffer->c])
                );

        buffer->c++;

        j++;
  
        for (int k = 0; k < collector->funcPrivate[j]; k++) {
      
            /// Func Args 
            strncat(buffer->output,
                    (buffer->buffer + buffer->pointer[buffer->c]),
                    (buffer->pointer[(buffer->c + 1)] - buffer->pointer[buffer->c])
                    );
            buffer->c++;
        }

        /// Func Inner
        strncat(buffer->output,
                (buffer->buffer + buffer->pointer[buffer->c]),
                (buffer->pointer[(buffer->c + 1)] - buffer->pointer[buffer->c])
                );

    }
    printf("\n%s\n", buffer->output);
  
        return 1;


}
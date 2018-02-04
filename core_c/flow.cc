#include <node.h>
#include "compileJsClass.c"

namespace nodeFlow {

    using v8::Function;

    using v8::FunctionCallbackInfo;
    using v8::Isolate;
    using v8::Local;
    using v8::Object;
    using v8::String;
    using v8::Value;
    using v8::Null;
    using v8::Number;
    using v8::Persistent;

    char* ToCString(Local<String> str) {
        String::Utf8Value value(str);
        return *value;
    }

    void Open(const FunctionCallbackInfo<Value>& args) {
        char* param1 = ToCString(args[0]->ToString());
        struct Buffer seqRegex;
        SequenceInit(&seqRegex, param1);
        _scanJs(&seqRegex);
    }

    void init(Local<Object> exports) {
        NODE_SET_METHOD(exports, "open", Open);
    }

    NODE_MODULE(NODE_GYP_MODULE_NAME, init)

}  
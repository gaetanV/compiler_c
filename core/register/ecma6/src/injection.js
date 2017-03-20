class Injection {
    
    constructor(space) {
        this.fn = space.fn;
        this.imports = [];
        this.inject = space.inject;
        this.type = space.type;
    }
    
    build(args) {
        for (var i in args) {
            if (this.inject[i]) {
                var type = this.inject[i];
                try {
                    if (type[0] !== "/") {
                        this.typeValidator(args[i], type);
                    } else {
                        this.classValidator(args[i], type);
                    }

                } catch (err) {
                    console.log(err);
                    return false;
                }
            }
        }
        args.import  = (namespace) => {
            if(this.imports[namespace]){
              return (args) => {
                this.imports[namespace].build(args);
              }
            }else{
                console.log("error import not exist");
            }
        }
        return  new this.fn(args);
    }
    
    typeValidator(a, type) {
        switch (type) {
            default:
                throw "ERROR NOT A UNKNOWN TYPE"
                break;
            case "String":
            case "string":
                if (a.constructor !== String) {
                    throw `ERROR ${a} NOT A string`
                }
                break;
            case "number":
            case "int":
                if (a.constructor !== Number) {
                    throw `ERROR ${a} NOT A Number`
                }
                break;
            case "boolean":
                if (a.constructor !== Boolean) {
                    throw `ERROR ${a} NOT A Boolean`
                }
                break;
            case "object":
                if (a.constructor !== Object) {
                    throw `ERROR ${a} NOT A Object`
                }
                break;
            case "array":
                if (a.constructor !== Array) {
                    throw `ERROR ${a} NOT A Array`
                }
                break;
        }
        return true;
    }
    
    classValidator(a, namespace) {   
        let thatspace = this.imports[namespace];
        if (!thatspace) {
            throw"THAT SPACE NOT EXIST";
        }
        if (thatspace.fn !== a.constructor) {

            throw "ERROR NOT A OWNER OBJECT";
        }
        return true;
    }
}

class $ {
    constructor(namespace, user, myspace) {
        this.myspace = myspace;
        this.namespace = namespace;
        this.user = user;
        var vm = this;
        function self(namespace) {

            var n = namespace.split("/");
            var fnname = n.pop();
            var n = n.slice(1);

            var thatspace = vm.myspace.getNamespaceByUser(n, vm.user);
            if (!thatspace) {
                throw"THAT SPACE NOT EXIST";
            }
            var thatclass = thatspace.Class[fnname];
            if (this == "undefined") {
                return thatclass
            } else {
                return function (args) {

                    for (var i in args) {
                        if (thatclass.inject[i]) {
                            var type = thatclass.inject[i];

                            try {
                                if (type[0] != "/") {
                                    vm.typeValidator(args[i], type);
                                } else {
                                    vm.classValidator(args[i], type);
                                }

                            } catch (err) {
                                console.log(err);
                            }

                        }
                    }
                    var c={};
           
                    
                    return  new thatclass.fn(args);
                   
                };
            }
        }
        return self;
    }  

    typeValidator(a, type) {
        switch (type) {
            default:
                throw "ERROR NOT A UNKNOWN TYPE"
                break;
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
        var n = namespace.split("/");
        var fnname = n.pop();
        var n = n.slice(1);
        var thatspace = this.myspace.getNamespaceByUser(n, this.user);

        if (!thatspace) {
            throw"THAT SPACE NOT EXIST";
        }
        var thatclass = thatspace.Class[fnname];
        if (thatclass.fn !== a.constructor) {
            throw "ERROR NOT A OWNER OBJECT";
        }
        return true;
    }

}
module.exports = (function () {
'use strict'
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
class Autoload {
    constructor() {
        this.namespace = new Namespace();
        var c = this.self.bind(this);
        c.owner = this.owner.bind(this);
        var vm = this;
        c.$ = function (namespace, user) {
            var myspace = new Namespace();
            for (var i in namespace) {
                var n = namespace[i].split("/").slice(1, -1);
                var spaceInject = vm.namespace.getNamespaceByUser(n, user);
                if (spaceInject) {
                    var space = myspace.setNamespace(n);
                    Object.assign(space, spaceInject);
                }
            }
            return new $(namespace, user, myspace);
        };
        return c;
    }
    self(namespace) {
        
        var n = namespace.split("/").slice(1, -1);
        var namespace = this.namespace.getNamespace(n);
        if (namespace) {
            return {
                class: function (name, fn, inject) {
                    var space = namespace;
                    space.class(name, fn, inject);
                }.bind(this)
            }
        } else {
            return {
                class: function (name, fn, inject) {
                    var space = this.namespace.setNamespace(n);

                    space.class(name, fn, inject);
                }.bind(this)
            }
        }
    }
    owner(namespace, owner) {
        if (owner.constructor.name == "User") {
            var n = namespace.split("/").slice(1, -1);
            namespace = n[0];
            if (this.namespace.getNamespace(n)) {
                return false;
            } else {
                this.namespace.setNamespace(n);
                this.namespace.setOwner(n, owner);
            }
        }
    }
}
class Class {
    constructor(fn, inject) {
        this.fn = fn;
        this.inject = inject;

    }
}
class Namespace {
    constructor() {
        this.spaces = {};
    }
    setOwner(n, user) {
        var space = this.getNamespace(n);
        console.log("setOwner");
        if (space.owner === false) {
            space.owner = user;

            return true;
        } else {
            console.log("ERROR USER IS ALREADY DEFININED");
            return false;
        }
    }
    setNamespace(n, name, fn, inject) {
        console.log("setNamespace");
        if (!this.getNamespace(n)) {
            var tmpspaces = this.spaces;
            for (var i = 0; i < n.length; i++) {
                var p = tmpspaces[n[i]];
                if (!p) {
                    tmpspaces[n[i]] = new Space(false);
                }
                if (i == n.length - 1) {
                    return tmpspaces[n[i]];
                }
                tmpspaces = tmpspaces[n[i]].children;
            }
        }
    }
    getNamespace(n) {
        var tmpspaces = this.spaces;
        for (var i in n) {
            tmpspaces = tmpspaces[n[i]];
            if (!tmpspaces) {
                return false;
            }
            if (i != n.length - 1) {
                tmpspaces = tmpspaces.children;
            }
        }
        return tmpspaces;
    }
    getNamespaceByUser(n, user) {
        var tmpspaces = this.spaces;
        for (var i in n) {
            tmpspaces = tmpspaces[n[i]];

            if (!tmpspaces) {
                return false;
            } else {
                if (tmpspaces.owner != false) {
                    if (tmpspaces.owner !== user) {
                        console.log("ERROR USER CAN ACCES THIS SPACE");
                        return false;
                    }
                }
            }
            if (i != n.length - 1) {
                tmpspaces = tmpspaces.children;
            }
        }
        return tmpspaces;
    }
}
class Space {
    constructor(owner) {
        this.children = [];
        this.owner = owner;
        this.Class = [];
        this.Abstract = [];
        this.Interface = [];
    }
    class(name, fn, inject) {
        if (!this.Class[name]) {
            this.Class[name] = new Class(fn, inject);
        } else {
            console.log("ERROR CLASS IS ALREADY DEFININED");
        }
    }
}
return new Autoload()
})();

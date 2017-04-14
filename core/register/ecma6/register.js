module.exports = (function () {
    'use strict'
    class Class {
        constructor(fn, inject, type) {
            this.fn = fn;
            this.inject = inject;
            this.type = type ? type : "class";
        }
    }
    class Injection {

        constructor(space) {
            this.fn = space.fn;
            this.imports = [];
            this.inject = space.inject;
            this.type = space.type;
        }

        build(args) {
            !args && (args =[]);
   
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
            
            args.import = (namespace) => {
                if (this.imports[namespace]) {
                    return (args) => {
                        this.imports[namespace].build(args);
                    }
                } else {
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
    class Namespace {
        constructor() {
            this.spaces = {};
        }
        setNamespace(n, name, fn, inject) {
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
    }
    class Register {
        constructor() {
            this.mapping;

            this.namespace = new Namespace();
            this.isdeploy;
            this.lock;
            var c = this.self.bind(this);
            c.containers = this.containers.bind(this);

            c.deploy = this.deploy.bind(this);
            var vm = this;
            return c;
        }
        self(namespace) {
            if (!this.isdeploy && this.lock) {
                var n = namespace.split("/").slice(1, -1);
                console.log(this.namespace);
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
            } else {
                console.log("DON'T TRY TO HACK");
            }
        }
        containers(mapping, locky) {
            if (!this.mapping && !this.lock) {
                this.lock = locky;
                this.mapping = mapping;
                return true;
            } else {
                console.log("DON'T TRY TO HACK");
            }
            return false;
        }
        deploy(key) {
            if (!this.isdeploy && key === this.lock) {
                let tmpregister = [], register = [];

                for (var i in this.mapping) {
                    let n = [i];
                    let c = this.mapping[i];

                    let space = this.namespace.getNamespace(n);
                    if (space) {
                        let func = [];
                        for (var j in c) {
                            let a = c[j].split("/").slice(1, -1);
                            let b = this.namespace.getNamespace(a);
                            let result = Register.parseInner(a.join("/"), b);

                            for (var j in result) {
                                func[j] = result[j];
                            }
                        }
                        let owner = Register.parseInner(n.join("/"), space);
                        tmpregister.push({owner: owner, func: func});
                    }
                }
                tmpregister.forEach((e) => {
                    for (var j in e.owner) {
                        if (!register[j]) {
                            var owner = e.owner[j];
                            register[j] = new Injection({
                                fn: owner.fn,
                                inject: owner.inject,
                                type: owner.type,
                            });
                        }
                        for (var k in e.func) {
                            register[j].imports[k] = e.func[k];
                        }
                    }
                })
                /*******
                 * RECURSIVE
                 */
                for (var i in register) {
                    for (var j in register[i].imports) {
                        register[i].imports[j] = register[j];
                    }
                }

                this.isdeploy = true;
                return function (space) {

                    return function (args) {
                        if (!register[space]) {
                            return false;
                        }
                        return register[space].build(args);
                    }
                }

            } else {
                console.log("DON'T TRY TO HACK");
                return false;
            }
        }
        static parseInner(namespace, space) {
            let array = [];
            for (var i in space.Class) {
                array[("/" + namespace + "/" + i).replace(/\/\//g, "/")] = space.Class[i];
            }
            if (space.children) {
                for (var i in space.children) {
                    let result = Register.parseInner(("/" + namespace + "/" + i).replace(/\/\//g, "/"), space.children[i]);
                    for (var j in result) {
                        array[j] = result[j];
                    }
                }
            }
            return array;
        }

    }
    class Space {
        constructor(owner) {
            this.children = [];
            this.Class = [];
        }
        class(name, fn, inject) {
            if (!this.Class[name]) {
                this.Class[name] = new Class(fn, inject);
            } else {
                console.log("ERROR CLASS IS ALREADY DEFININED");
            }
        }
    }
    return new Register()
})();

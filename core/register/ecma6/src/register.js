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

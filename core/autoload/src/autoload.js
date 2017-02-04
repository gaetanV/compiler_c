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

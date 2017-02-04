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
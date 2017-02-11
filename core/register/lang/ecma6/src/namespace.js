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
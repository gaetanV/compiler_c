module.exports = (function () {
    'use strict'
    class Deamon {
        constructor(mapping, name) {
            if (!mapping.src || !mapping.imports ) {
                throw "error"
            }
            this.name = "deamon/"+name;
            this.src = mapping.src;
            this.imports = mapping.imports;
        }
    }
    return class Deamons {
        constructor(hook) {
            this.hook = hook;
            this.deamon = [];
            for (var i in hook.deamons) {
                this.deamon[i] = new Deamon(hook.deamons[i], i);
            }
        }
    }
})();

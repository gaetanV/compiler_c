module.exports = (function () {
    'use strict'
    class Service {
        constructor(mapping, name) {
            if (!mapping.src || !mapping.imports ) {
                throw "error"
            }
            this.name = "service/"+name;
            this.src = mapping.src;
            this.imports = mapping.imports;
        }
    }
    return class Services {
        constructor(hook) {
            this.hook = hook;
            this.service = [];
            for (var i in hook.services) {
                this.service[i] = new Service(hook.services[i], i);
            }
        }
    }
})();

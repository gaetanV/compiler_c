module.exports = (function () {
    'use strict'
    class Container {
        constructor(mapping, name) {
            if (!mapping.src || !mapping.imports || !mapping.services) {
                throw "error"
            }
            this.name = name;
            this.src = mapping.src;
            this.imports = mapping.imports;
            this.services = mapping.services;
        }
    }
    return class Containers {
        constructor(hook) {
            this.hook = hook;
            this.container = [];
            for (var i in hook.containers) {
                this.container[i] = new Container(hook.containers[i], i);
            }
        }
    }
})();

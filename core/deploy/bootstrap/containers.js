module.exports = (function () {
    'use strict'
    const $fs = require('fs');
    const $path = require('path');
    
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
            this.contenairs = [];
            for (var i in hook.contenairs) {
                this.contenairs[i] = new Container(hook.contenairs[i], i);
            }
        }

    }

   

})();

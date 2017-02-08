module.exports = (function () {
    'use strict'
    return class Contenainer {
        constructor(mapping, name) {
            if (!mapping.src || !mapping.namespace || !mapping.imports || !mapping.services) {
                throw "error"
            }
            this.name = name;
            this.src = mapping.src;
            this.namespace = mapping.namespace;
            this.imports = mapping.imports;
            this.services = mapping.services;
        }
        build() {
            return new Promise((resolve, reject) => {
                resolve(`"${this.namespace}":"[${this.imports.join(",")}]",\n` );
            });
        }
    }

})();
'use strict'
const $path = require('path');
const register = require($path.join(__dirname, "..", 'register.js'));

let bootstrap = (function () {
    'use strict'
    class Key {
        constructor() {}
    }
    let key = new Key({method: "strict", role: "root"});
    register.containers({
        "bundle": ['/bundle/Class/entity/', '/bundle/Class/security/'],
        "route": ['/bundle/Class/'],
    }, key)
   return class {
        constructor() {
          //  let $ = autoload.deploy(key);
           // console.log($('/Bundles/UserBundle/Service/test'));
           // $('/Bundles/UserBundle/Service/inject')({string: "string", integer: 5});
        }
    }
    
})();

register('/route/').class('test', class {
    constructor(args) {
        let value = args.value;
        let inject = args.inject;

    }
    re() {

        " + "
    }
    static de(s) {

        " + "
    }
    static reflect() {
        return [{"type": "public", "name": "re", "args": []}, {"type": "static", "name": "de", "args": ["s"]}, {"type": "private", "name": "test", "args": ["a"]}, {"type": "constructor", "name": "", "args": {"value": "String", "inject": "/Bundles/UserBundle/Service/inject"}}]
    }
}
, {"value": "String", "inject": "/Bundles/UserBundle/Service/inject"});
register('/bundle/Controller').class('inject', class {
    constructor(args) {
        let value = args.value;
        let integer = args.integer;

    }
    static reflect() {
        return [{"type": "private", "name": "superbe", "args": ["a", "v"]}, {"type": "constructor", "name": "", "args": {"value": "String", "integer": "int"}}]
    }
}
, {"value": "String", "integer": "int"});
register('/bundle/Controller').class('test', class {
    constructor(args) {
        let value = args.value;
        let inject = args.inject;

    }
    superbe(a, v) {

        " + "
    }
    static ret(c, n) {

        " + "
    }
    static reflect() {
        return [{"type": "public", "name": "superbe", "args": ["a", "v"]}, {"type": "static", "name": "ret", "args": ["c", "n"]}, {"type": "constructor", "name": "", "args": {"value": "String", "inject": "/Bundles/UserBundle/Service/inject"}}]
    }
}
, {"value": "String", "inject": "/Bundles/UserBundle/Service/inject"});

'use strict'
const $path = require('path');

const autoload = require($path.join(__dirname, 'autoload.js'));
let bootstrap = (function () {
    'use strict'
    let user = class {}
    let root = new user();
    let ab = new user();
    autoload.owner('/Bundles/', root);
    return class {
        constructor() {
            let $ = new autoload.$(["/Bundles/"], root);
            let b = new $('/Bundles/UserBundle/Service/inject')({string: "test", integer: 5});
            console.log(b);
        }
    }

})();
(function () {
    class inject {
        constructor(params) {
            let $ = new autoload.$(["/Bundles/"], root);
            let string = params.string;
            let integer = params.integer;
            let c = new $('/Bundles/UserBundle/Service/test')({string: "test", inject: this});
            console.log(c);

            console.log("-----inject-----");
            console.log(`{string:${string},integer:${integer}}`);
        }
    }
    autoload('/Bundles/UserBundle/Service/').class('inject', inject, {string: "string", integer: "int"});
})();
(function () {
    class test {
        constructor(params) {
            let $ = new autoload.$(["/Bundles/"], root);
            let string = params.string;
            let inject = params.inject;

            console.log("-----test-------");
            console.log(`{string:${string},inject:${inject}}`);

        }
    }
    autoload('/Bundles/UserBundle/Service/').class('test', test, {string: "string", inject: "/Bundles/UserBundle/Service/inject"});
})();


new bootstrap();
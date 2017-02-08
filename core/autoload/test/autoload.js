'use strict'
const $path = require('path');

const autoload = require($path.join(__dirname, "..", 'autoload.js'));
let bootstrap = (function () {
    'use strict'
    let key = {name: "bootstrap", method: "strict", role: "root"};

    autoload.containers(
            {
                "/Bundles/UserBundle/Service/": ["/Bundles/UserBundle/Service/"],
                "/Bundles/": ["/Bundles/UserBundle/", "/Bundles/"]
            },
            key
            );

    return class {
        constructor() {
            let $ = autoload.deploy(key);
            console.log($('/Bundles/UserBundle/Service/test'));
            $('/Bundles/UserBundle/Service/inject')({string: "string", integer: 5});
        }
    }

})();
autoload('/Bundles/UserBundle/Service/').class('inject', class inject {
    constructor(params) {

        let importA = params.import('/Bundles/UserBundle/Service/test');
        let string = params.string;
        let integer = params.integer;

        importA({string: "string", inject: this});
        console.log(params);

    }
}, {string: "string", integer: "int"});

autoload('/Bundles/UserBundle/Service/').class('test', class test {
    constructor(params) {

        let string = params.string;
        let inject = params.inject;


        console.log("-----test-------");
        console.log(`{string:${string},inject:${inject}}`);

    }
}, {string: "string", inject: "/Bundles/UserBundle/Service/inject"});

new bootstrap();
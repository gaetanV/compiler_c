'use strict'
module.exports = (function () {
    return {
        name: "run.js",
        injection: "type",
        namespace: {
            "Bundles/Class/": "./exemple/Class/",
            "Core": "./exemple/Core/"
        },
        target: "es6",
        mapping: {
            "app.js": ["Core", "Bundles/Class/"],
            "Bundles/Class/": ["Bundles/Class/"]
        },
        bootstrap: "./app/bootstrap.js",
        start: "./app/app.js"
    }
})();

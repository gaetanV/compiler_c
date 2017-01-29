module.exports = (function () {
    'use strict'
    return {
        name: "run.js",
        injection: "type",
        namespace: {
            "Bundles/Class/": "./src/Class/",
            "Core": "./src/Core/"
        },
        mapping: {
            "app.js": ["Core", "Bundles/Class/"],
            "Bundles/Class/": ["Bundles/Class/"]
        },
        bootstrap: "./app/bootsrap.js",
        start: "./app/app.js"
    }
})();

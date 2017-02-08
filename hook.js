module.exports = (function () {
    'use strict'
    return {
        param: {
            restrict_bundle_space : "/var/www/private/tmp",
            htpp :{
                ip : "58.125.136.124",
                port : 8080,
            }
        },
        contenairs : {
            bundle :{
                 injection: "none",
                 src: "./exemple/Bundle/",
                 namespace: "Bundles/Class/",
                 imports : ["Bundles/Class/entity/", "Bundles/Class/security/"] ,
                 services : {
                     "bundleFile" : "bundleFile",
                 }
            },
            route :{
                 injection: "typeJS",
                 src: "./exemple/Route/",
                 namespace: "Bundles/Route/",
                 imports : ["Bundles/Class/"] ,
                 services : {
                     "serveurHttp" : "serveurHttp",
                 }
            },
        },
        services: {
            bundleFile: {
               injection: "typeJS",
               class: "./exemple/Core/fs/fs",
               inject: { 
                   spaceRestraint: "%restrict_bundle_space%"
               },
               import: ["./exemple/Core/fs/lib/"]
            },
            serveurHttp:{
               injection: "typeJS",
               class: "./exemple/Core/server/serverHttp",
               inject: {
                   ip: "%ip%",
                   port : "%port%"
               },
               import: ["./exemple/Core/server/lib/"]
            },
            response:{
                injection: "none",
                class: "./exemple/Core/http/respnse",
            }
        },
        target : "es6",
        bootstrap: "./app/bootstrap.js"
    }
})();

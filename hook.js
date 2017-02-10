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
                 src: "./exemple/Container/Bundle/",
                 imports : ["/bundle/Class/entity/", "/bundle/Class/security/"] ,
                 services : ["bundleFile"],    
            },
            route :{
                 injection: "typeJS",
                 src: "./exemple/Container/Route/",
                 imports : ["/bundle/Class/"] ,
                 services : [ "cache"],
                 deamon: ["serveurHttp","eventDispatcher"],
            },
        },
        services: {
            cache: {
               injection: "typeJS",
               class: "./exemple/Core/cache/cache",
               deamon: ["eventDispatcher"],
            },
            bundleFile: {
               injection: "typeJS",
               class: "./exemple/Core/fs/fs",
               inject: { 
                   spaceRestraint: "%restrict_bundle_space%"
               },
               import: [],
            }
        },
        deamon: {
             eventDispatcher: {
                 injection: "typeJS",
                 class: "./exemple/Core/server/serverHttp",
             },   
             serveurHttp: {
               injection: "typeJS",
               class: "./exemple/Core/server/serverHttp",
               inject: {
                   ip: "%ip%",
                   port : "%port%"
               },
               import: [],
             },
             cron: {
               injection: "typeJS",
               class: "./exemple/Core/cron/cron",
               inject: {},
               import: [],
             }
        },
        target : "es6",
        bootstrap: "./app/bootstrap.js"
    }
})();

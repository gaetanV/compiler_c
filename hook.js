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
        containers : {
            bundle :{
                 injection: "none",
                 src: "./exemple/Container/Bundle/",
                 imports : [] ,
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
            bundleFile: {
               injection: "typeJS",
               src: "./exemple/Service/bundleFile/",
               class : "bundle",
               imports: [],
               inject: { 
                   spaceRestraint: "%restrict_bundle_space%"
               },
              
            }
        },
        deamons: {
             serveurHttp: {
               injection: "typeJS",
               src: "./exemple/Deamon/serveurHttp/",
               bootstrap : "serverHttp",
               inject: {
                   ip: "%ip%",
                   port : "%port%"
               },
               imports: [],
             },
             cron: {
               injection: "typeJS",
               src: "./exemple/Deamon/cron/",
               inject: {},
               imports: [],
             }
        },
        target : "es6",
        bootstrap: "./app/bootstrap.js"
    }
})();

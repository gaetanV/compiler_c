 (function () {
   'use strict'
   const $watch = require('node-watch');
   const $path = require('path');
   const $fs = require('fs');
   const $deploy = require($path.join(__dirname,'core','deploy.js'));
   const $hook = require($path.join(__dirname,'hook.js'));
  
   
   let deploy=new $deploy();
   let cycle=[];
   
   for(var i in $hook.namespace){
        cycle.push({map: "namespace",src:$hook.namespace[i],name:i});
   }
  
   for(var i in cycle){
       var watcher = $watch('./'+cycle[i].src);
       watcher.on('change', function(file) {
                compile();
       });
   }
   
   compile();
   function compile(){
        function* thread() {
            var index=0;
            while (index < cycle.length-1 ){
                yield index++;
            }
        }
      
       let iterator=thread();
       
       for(var index in cycle){
           switch(cycle[index].map){
               case "namespace":
                    deploy.parseNamespace(cycle[index].src,cycle[index].name).then(function(value){
                        iterator.next().done==1&&( write()) ;                
                   })
                   break;
           }
       }
   }
 
    function write(rest){
        $fs.writeFile($path.join(__dirname,$hook.bootstrap), deploy.str , function (error) {
            if (error) {
                console.error("write error:  " + error.message);
            } else {
                console.log("completed");
            }
        })
    }
  
})();
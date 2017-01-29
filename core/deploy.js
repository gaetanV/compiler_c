 (function () {
  'use strict'
    const $fs = require('fs');
    const $path = require('path');
    const path={
        server:$path.join(__dirname,"..","/"),
        root_dir:$path.join(__dirname,"/"),
    }
    const REGEX={
        import: "import[^\{]*{([^\}]*)}[^f]*from([^;]*)",
        constructor: "constructor[\\s]*\\(([^\)]*)\\)[^\{]*\{",
        export: "export[\\s]*class[\\s]*${func}[\\s]*([^\{]*)\{",
        js: "^(.*).js$",
    }

    String.prototype.apply = function (array) {
        var format = this;
        for (var i in  array)
            format = format.replace("${" + i + "}", array[i]);
        return format;
    };


    class Deploy { 
        constructor(){
            this.str = "";
        }
       
       static parseInnerClass(fn,file){
            let exportRegex = new RegExp(REGEX.export.apply({func: fn}),"g");
            let func={
                getExportName: (fn,file) => {
                   //TO DO :: EXTENDS NAMESPACE + INTERFACES
                    let match = exportRegex.exec(file);
                    if(!match){throw "ERROR "+fn+" CLASS IS NOT CORRECTLY DEFINED"};
                    return match;
                },
                getImport: (file) => {
                    let inject=[],m= new RegExp(REGEX.import,"g"),tmp;
                    do {
                        tmp = m.exec(file);
                        if (tmp) {
                            inject.push({name:tmp[1],space:tmp[2]});
                        }
                    } while (tmp);
                    return inject
                },
                getInnerFunc: (start_index, file) => {
                    let  closure = [];
                    function getAllIndexes(arr, val,indexMin) {
                       let indexes = [], i = -1;
                       while ((i = arr.indexOf(val, i+1)) != -1){
                           if(i>=indexMin)indexes.push(i);
                       }
                       return indexes;
                    }
                    getAllIndexes(file,"{",start_index).map(function(a,b){closure[a]=1;});
                    getAllIndexes(file,"}",start_index).map(function(a,b){closure[a]=-1;});
                    var cmp = 0, r = false;
                    closure.map(function(a,b){
                        cmp+= a;
                        if(cmp == 0){r = b;}
                    });
                    if(!r){ throw "ERROR IN CLASS"};
                    return file.slice(start_index,r+1);
                },
                getConstructorArgs: (c) => {
                    let match =  new RegExp(REGEX.constructor,"g").exec(c), args;
                    if(match){
                        if(match[1]){
                            args = match[1].split(",");
                            args=args.map(function(a,b){return a.trim().split(" ");})
                            return { values: args, match: match } ;
                        }
                     }
                     return false;
                }
            }

            let match = func.getExportName(fn, file);
            let inject = func.getImport(file);
            let c  = func.getInnerFunc(match.index+match[0].length-1, file);
            let argsObj = func.getConstructorArgs(c);
            
            let args = [];
            
            if(argsObj){
                args = argsObj.values;
                var index = argsObj.match.index + argsObj.match[0].length;
                
                if(args) {
                    let rest = "";
                    if(inject.length>0){
                        rest += "let $=new autoload();\n";
                        for(var i in inject){
                                   rest+="let "+inject[i].name+" = $("+inject[i].space+");\n";
                        }
                        c = c.slice(0, index) + rest + c.slice(index);
                        
                        
                        
                    }
                    c = c.replace(argsObj.match[1],args.map(function(a,b){ return a[1]; }));   
                }
            }
            return {fn:"class "+fn+" "+match[1]+c,args:args,inject:inject}
        }
             
       parseNamespace(directory,namespace,restrict){
           directory = directory.replace(/\\/g,"/");
           if(!namespace){namespace=directory}else{namespace=namespace.replace(/\\/g,"/")};
           const repertory_path=$path.join(path.server,directory);
          
           let func={
               getClassName: (filename) => {
                    if(restrict){
                         var classNameRestrict = restrict.exec(filename);
                         if (!classNameRestrict){throw("ERROR RESTRICT")}; 
                    }
                    var className = new RegExp(REGEX.js,"g").exec(filename);
                    if (!className){throw("ERROR")}; 
                    return className[1];
               },
               buildHeader: (namespace, fn, args) => {
                    this.str+= "(function () {\n";
                    this.str+= "'use strict';\n";
                    this.str+= "autoload('"+namespace+"').class('"+fn+"',"+fn+","+JSON.stringify(args)+");\n";
               },
               buildBody: (innerClass) => {
                    this.str+= innerClass;  
               },
               buildFooter: () => {
                    this.str+= "})();\n";
               }
           };
           
            let vm=this;
           return new Promise( (resolve, reject) => {
               $fs.readdir(repertory_path, function (err, files) {
                   let tasks = files.length-1;
                   function* thread() {
                        var index=0;
                        while (index < tasks ){
                            yield index++;
                        }
                   }
                   let iterator=thread();
                   files.forEach(function (file) {
                       let path_file = $path.join(repertory_path, file);
                       if(!$fs.lstatSync(path_file).isDirectory()){
                            let fn = func.getClassName(file);
                            let innerClass= Deploy.parseInnerClass(fn,$fs.readFileSync(path_file, 'utf8'));
                            func.buildHeader.apply(vm,[namespace,fn,innerClass.args]);
                            func.buildBody.apply(vm,[innerClass.fn]);
                            func.buildFooter.apply(vm,{});
                            iterator.next().done==1&&(  resolve( )) ; 
                       }else{
                           tasks++;
                           parseNamespace($path.join(directory, file,"/"),$path.join(namespace, file,"/"),restrict).then(                                        
                                            (valeur) => { iterator.next().done==1&&(  resolve( )) ; }
                            )
                       }
                   });
                   
               });
           });
        };
   }     

   module.exports=Deploy;
})();
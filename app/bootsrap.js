(function () {
'use strict';
autoload('Bundles/Class/').class('inject',inject,[["String","value"],["int","integer"]]);
class inject {
        constructor(value,integer)
        {let $=new autoload();
let  test  = $( '/Bundle/Superbe');
let  a  = $( '/Bundle/ert');

            new test("ss");
            console.log("-----inject-----");
            console.log(value);
            console.log(integer);
            
        }
}})();
(function () {
'use strict';
autoload('Bundles/Class/').class('test',test,[["String","value"],["/Bundles/UserBundle/Service/inject","inject"]]);
class test {
        constructor(value,inject)
        {
           // $("/Bundles/UserBundle/Service/inject");
            console.log("-----test-------");
           // console.log(@inject);
            console.log(value);
            console.log(inject);
        }
        superbe(){
            console.log("superbe");
        }
}})();
(function () {
'use strict';
autoload('Core').class('test',test,[["String","value"],["/Bundles/UserBundle/Service/inject","inject"]]);
class test {
        test : int;
        
        constructor(value,inject)
        {let $=new autoload();
let  test  = $( '/Bundle/Superbe');
let  a  = $( '/Bundle/ert');

           // $("/Bundles/UserBundle/Service/inject");
            console.log("-----test-------");
           // console.log(@inject);
            console.log(value);
            console.log(inject);
        }
}})();

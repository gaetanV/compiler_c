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
        private superbe(a,v){
            console.log("superbe private");
        }
}})();
(function () {
'use strict';
autoload('Bundles/Class/').class('test',test,[["String","value"],["/Bundles/UserBundle/Service/inject","inject\r\n","","","","","","","","","","","","","","","","","","","","","","","","//suprebe"]]);
class test {
        constructor(value,inject
)
        {
           // $("/Bundles/UserBundle/Service/inject");
            console.log("-----test-------");
           // console.log(@inject);
            console.log(value);
            console.log(inject);
        }
        public superbe(a,v){
            console.log("superbe");
        }
        static ret(c,n){
            console.log("re");
            
        }
}})();
(function () {
'use strict';
autoload('Core').class('test',test,[["String","value"],["/Bundles/UserBundle/Service/inject","inject"]]);
class test {
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
        private test(a){
            console.log("reflexion mapping");
        }
        public re(){
            
        }
        static de(s){
            console.log("reflexion static");
        }   
}})();

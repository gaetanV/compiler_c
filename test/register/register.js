'use strict'
var chai = require('chai');

var expect = chai.expect;
var assert = chai.assert;

var $register = require('./../../core/register/ecma6/register.js');

describe('Register  Args', () => {
    var key = "what you want it's fake - this is integrity";
    it('Register.containers key', () => {

        $register.containers({
            "bundle": [],
            "route": ['/bundle/Controller/','/route/'] // NO AUTO INJECTION
        }, key)
        assert.equal($register.deploy("key"), false);

    });
    it('Register.containers class', () => {
        assert.isFunction($register('/bundle/Controller/').class);
        $register('/bundle/Controller/').class('inject', class {
            constructor() {
                this.id = "fake injection";
            }
            getId() {
                return this.id;
            }

        }, {});
        $register('/route/').class('superhero', class {
            constructor(args) {
                this.value = args.value;
                this.inject = args.import('/bundle/Controller/inject')();
            }
            getInject() {
                return this.inject;
            }
            getValue() {
                return this.value;
            }
        }, {"value": "String"});
        
        $register('/route/').class('decoration', class {
            constructor(args) {
                this.value = args.value;
            }
            getValue(){
                return this.value;
            }
         
        }, {"value": "/route/superhero"});


        $register('/fake/Controller/').class('inject', class {
            constructor() {}
        }, {});

    });

    var $;
    var $inject;
    it('Register.containers deploy', () => {
        $ = $register.deploy(key);
        assert.isFunction($);
        $inject = new $('/bundle/Controller/inject')();
        assert.equal($inject.getId(), "fake injection");
    });

    it('Register.containers deploy force', () => {
        assert.isFalse($('/fake/Controller/inject')());
    });

    it('Register.containers good type', () => {
        assert.equal(new $('/route/superhero')({value: "5"}).getValue(), "5");
    });
    
    it('Register.containers bad type', () => {
        assert.equal(new $('/route/superhero')({value: 5}), false);
    });

    it('Register.containers injection', () => {
        var A = new $('/route/superhero')({value: "string"});
        assert.equal(A.getInject().getId(), "fake injection");
    });
    

    it('Register.containers good decoration', () => {
       var A =  new $('/route/decoration')({value: new $('/route/superhero')({value: "5"})});
       assert.equal(A.getValue().getValue(),5);
    });
    
    it('Register.containers bad decoration', () => {
       assert.equal(new $('/route/decoration')({value: new $('/bundle/Controller/inject')()}), false);
    });
 
});
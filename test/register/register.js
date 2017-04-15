'use strict'



var chai = require('chai');

var expect = chai.expect;
var assert = chai.assert;

var $register = require('./../../core/register/ecma6/register.js');

describe('Register  Args', () => {
    var key = "what you want it's fake - this is integrity";
    it('Register.containers key', () => {

        $register.containers({
            "bundle": ['/bundle/Class/entity/', '/bundle/Class/security/'],
        }, key)
        assert.equal($register.deploy("key"), false);

    });
    it('Register.containers class', () => {
        assert.isFunction($register('/bundle/Controller/').class);
        $register('/bundle/Controller/').class('inject', class {
            constructor(){
                this.id = "fake injection";
            }
            getId(){
                return this.id;
            }
        }, {});
        $register('/fake/Controller/').class('inject', class {
            constructor(){}
        }, {});
    });
    
    var $;
    it('Register.containers deploy', () => {
        $ = $register.deploy(key);
        assert.isFunction($);
        assert.equal(new $('/bundle/Controller/inject')().getId(), "fake injection");
    });
    
    it('Register.containers deploy force', () => {  
        assert.isFalse($('/fake/Controller/inject')());
    });


});
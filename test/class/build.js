'use strict'

var chai = require('chai');
var $fs = require('fs');
var expect = chai.expect;
var assert = chai.assert;

var $build = require('./../../core/class/Build');

describe('Build.write', () => {
    var path = __dirname + "/../../trash/class1.js";
    
    it('Build.write file', (done) => {
        /*** 
         * ERROR
         */
        var A = new $build("es5");
        A.write("error",path).then(() => {
            assert.isTrue($fs.existsSync(path));
            done();
        });
        
        
    });
    
    
});
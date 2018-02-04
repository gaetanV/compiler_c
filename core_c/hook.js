const fs = require('fs');
const Flow = require('./build/Release/flow');


fs.watch('./../trash/test.js', { encoding: 'buffer' }, (eventType, filename) => {
    if (filename) {
        Flow.open("./../trash/test.js");
    }
});
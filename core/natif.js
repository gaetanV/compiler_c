String.prototype.apply = function (array) {
        var format = this;
        for (var i in  array)
            format = format.replace("${" + i + "}", array[i]);
        return format;
};
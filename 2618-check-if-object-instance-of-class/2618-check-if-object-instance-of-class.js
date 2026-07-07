/**
 * @param {*} obj
 * @param {*} classFunction
 * @return {boolean}
 */
var checkIfInstanceOf = function(obj, classFunction) {
    // If obj is null or undefined, or classFunction is not a function,
    // it cannot be an instance.
    if (obj === null || obj === undefined || typeof classFunction !== 'function') {
        return false;
    }

    // Get the prototype of the object
    let proto = Object.getPrototypeOf(Object(obj));

    // Traverse the prototype chain
    while (proto !== null) {
        if (proto === classFunction.prototype) {
            return true;
        }
        proto = Object.getPrototypeOf(proto);
    }

    return false;
};
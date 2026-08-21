/**
 * @param {Function} fn
 * @param {number} t milliseconds
 * @return {Function}
 */
var debounce = function(fn, t) {
    let timerId;
    
    return function(...args) {
        // Clear the existing timeout if the function is called again within the time window
        clearTimeout(timerId);
        
        // Schedule the execution of fn with the latest arguments after t milliseconds
        timerId = setTimeout(() => {
            fn(...args);
        }, t);
    };
};
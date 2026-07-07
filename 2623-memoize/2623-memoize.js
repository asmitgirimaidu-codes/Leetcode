/**
 * @param {Function} fn
 * @return {Function}
 */
function memoize(fn) {
    const cache = new Map();
    
    return function(...args) {
        // Create a unique key based on the arguments
        const key = JSON.stringify(args);
        
        // If the result is already in the cache, return it
        if (cache.has(key)) {
            return cache.get(key);
        }
        
        // Otherwise, call the function, store the result, and return it
        const result = fn(...args);
        cache.set(key, result);
        return result;
    }
}
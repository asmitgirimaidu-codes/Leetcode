var TimeLimitedCache = function() {
    this.cache = new Map();
};

/** * @param {number} key
 * @param {number} value
 * @param {number} duration time until expiration in ms
 * @return {boolean} if un-expired key already existed
 */
TimeLimitedCache.prototype.set = function(key, value, duration) {
    const found = this.cache.has(key);
    
    // If the key exists, clear its old timeout so it doesn't delete the new value
    if (found) {
        clearTimeout(this.cache.get(key).timeoutId);
    }
    
    // Set a new timeout to delete the key after the duration
    const timeoutId = setTimeout(() => {
        this.cache.delete(key);
    }, duration);
    
    // Store the value and the timeout reference
    this.cache.set(key, { value, timeoutId });
    
    return found;
};

/** * @param {number} key
 * @return {number} value associated with key
 */
TimeLimitedCache.prototype.get = function(key) {
    if (this.cache.has(key)) {
        return this.cache.get(key).value;
    }
    return -1;
};

/** * @return {number} count of non-expired keys
 */
TimeLimitedCache.prototype.count = function() {
    return this.cache.size;
};
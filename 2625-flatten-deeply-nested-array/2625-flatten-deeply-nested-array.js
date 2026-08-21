/**
 * @param {Array} arr
 * @param {number} depth
 * @return {Array}
 */
var flat = function (arr, n) {
    const res = [];
    
    function helper(items, currentDepth) {
        for (const item of items) {
            if (Array.isArray(item) && currentDepth < n) {
                helper(item, currentDepth + 1);
            } else {
                res.push(item);
            }
        }
    }
    
    helper(arr, 0);
    return res;
};
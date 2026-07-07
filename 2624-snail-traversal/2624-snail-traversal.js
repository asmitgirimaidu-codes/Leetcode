/**
 * @param {number} rowsCount
 * @param {number} colsCount
 * @return {Array<Array<number>>}
 */
Array.prototype.snail = function(rowsCount, colsCount) {
    // Check if the input is valid: total elements must match dimensions
    if (rowsCount * colsCount !== this.length) {
        return [];
    }

    // Initialize an empty 2D array with the specified rowsCount
    const result = Array.from({ length: rowsCount }, () => []);

    for (let i = 0; i < this.length; i++) {
        // Calculate the current column index
        const col = Math.floor(i / rowsCount);
        
        // Determine the row index based on column parity
        // Even columns (0, 2, 4...): top to bottom (row increases)
        // Odd columns (1, 3, 5...): bottom to top (row decreases)
        const row = (col % 2 === 0) 
            ? (i % rowsCount) 
            : (rowsCount - 1 - (i % rowsCount));
        
        result[row][col] = this[i];
    }

    return result;
};
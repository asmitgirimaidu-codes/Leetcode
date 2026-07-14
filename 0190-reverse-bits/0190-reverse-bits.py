class Solution:
    # @param n, an integer
    # @return an integer
    def reverseBits(self, n):
        result = 0
        for i in range(32):
            # Extract the bit at position i from n
            bit = (n >> i) & 1
            # Place the bit at the reversed position (31 - i)
            result |= (bit << (31 - i))
        return result
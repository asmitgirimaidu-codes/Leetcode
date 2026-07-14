class Solution(object):
    def countPrimeSetBits(self, left, right):
        """
        :type left: int
        :type right: int
        :rtype: int
        """
        # Set of prime numbers up to 20 (maximum bits for 10^6)
        primes = {2, 3, 5, 7, 11, 13, 17, 19}
        count = 0
        
        # Iterate through the inclusive range
        for i in range(left, right + 1):
            # Count the number of set bits (1s)
            set_bits = bin(i).count('1')
            # If the count is in our prime set, increment the result
            if set_bits in primes:
                count += 1
                
        return count
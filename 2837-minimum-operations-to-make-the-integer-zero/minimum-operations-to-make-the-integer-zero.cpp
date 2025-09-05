class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        // We iterate through k = 1, 2, 3...
        for (long long k = 1; k <= 36; ++k) {
            long long target = num1 - k * num2;
            
            // Condition 1: target must be large enough.
            // target >= k is required because the smallest sum of k powers of 2 is k (k * 2^0).
            // Also target must be positive to have a popcount.
            if (target < k) {
                break; // No solution possible for this or any larger k
            }
            
            // Condition 2: The number of available terms (k) must be >= the minimum required terms (popcount).
            if (__builtin_popcountll(target) <= k) {
                return k;
            }
        }
        
        return -1;
    }
};
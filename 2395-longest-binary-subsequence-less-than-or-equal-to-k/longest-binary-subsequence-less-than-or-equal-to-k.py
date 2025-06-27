class Solution:
    def longestSubsequence(self, s: str, k: int) -> int:
        total = s.count('0')
        cur = 0
        for i in range(len(s)):
            if s[len(s) - i - 1] == '1':
                cur += 2 ** i

                if cur > k: break
                else: total += 1
        
        return total
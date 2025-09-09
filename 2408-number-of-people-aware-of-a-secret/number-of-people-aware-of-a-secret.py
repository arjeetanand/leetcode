class Solution:
    def peopleAwareOfSecret(self, n: int, delay: int, forget: int) -> int:
        MOD = 10**9 + 7
        dp = [0] * (n+1)
        dp[1] = 1
        share = [0] * (n + 2)

        if 1 + delay <= n + 1:
            share[1 + delay] = (share[1 + delay] + 1) % MOD
        if 1 + forget <= n + 1:
            share[1 + forget] = (share[1 + forget] - 1) % MOD

        curr = 0
        for day in range(2, n + 1):
            curr = (curr + share[day]) % MOD
            dp[day] = curr
            if day + delay <= n + 1:
                share[day + delay] = (share[day + delay] + dp[day]) % MOD
            if day + forget <= n + 1:
                share[day + forget] = (share[day + forget] - dp[day]) % MOD

        return sum(dp[n - forget + 1 : n + 1]) % MOD
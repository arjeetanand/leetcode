class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int i, j, sk, maximumlen = 1;
        int n = nums.size();
        vector<unordered_map<int, int>> dp(n);
        for (i = 0; i < n; ++i) {
            dp[i][-1] = 1;
            for (j = 0; j < i; ++j) {
                sk = (nums[j] + nums[i]) % k;
                if (dp[j].count(sk))
                    dp[i][sk] = max(dp[i][sk], dp[j][sk] + 1);
                else {
                    dp[i][sk] = max(dp[i][sk], 2);
                }
                maximumlen = max(maximumlen, dp[i][sk]);
            }
        }
        return maximumlen;
    }
};
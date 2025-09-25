class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        // dp will store the last row initially
        vector<int> dp = triangle[n - 1];

        // Bottom-up calculation
        for (int row = n - 2; row >= 0; row--) {
            for (int col = 0; col <= row; col++) {
                dp[col] = triangle[row][col] + min(dp[col], dp[col + 1]);
            }
        }

        // dp[0] contains the minimum path sum
        return dp[0];
    }
};
class Solution {
public:
    double memo(int id, vector<double>& dp, int n, int k, int maxPts) {
        if (id >= k) return (id <= n ? 1.0 : 0.0);
        if (dp[id] >= 0) return dp[id];
        if (id == k - 1) {
            double sum = 0.0;
            for (int d = 1; d <= maxPts; d++) {
                if (id + d <= n) sum += 1.0;
            }
            return dp[id] = sum / maxPts;
        }
        double valNext = memo(id + 1, dp, n, k, maxPts);
        double valFar = memo(id + maxPts + 1, dp, n, k, maxPts);
        return dp[id] = valNext + (valNext - valFar) / maxPts;
    }
    double new21Game(int n, int k, int maxPts) {
        if (k == 0 || n >= k + maxPts - 1) return 1.0;
        vector<double> dp(k + 1, -1.0);
        return memo(0, dp, n, k, maxPts);
    }
};
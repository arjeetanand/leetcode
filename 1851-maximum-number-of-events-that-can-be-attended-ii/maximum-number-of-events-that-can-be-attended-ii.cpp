class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        // Sort by end times
        std::sort(events.begin(), events.end(), [](std::vector<int>& lhs, std::vector<int>& rhs){
            return lhs[1] < rhs[1];
        });

        int n = events.size();
        std::vector<std::vector<int>> dp(n, std::vector<int>(k + 1, 0));

        // Base cases
        for (int cnt{ 1 }; cnt <= k; ++cnt) dp[0][cnt] = events[0][2];
        for (int i{ 1 }; i < n; ++i) dp[i][1] = std::max(dp[i - 1][1], events[i][2]);

        for (int cnt{ 2 }; cnt <= k; ++cnt) {
            for (int i{ 1 }; i < n; ++i) {
                // Take previous configuration disregarting i-th event
                dp[i][cnt] = std::max(dp[i - 1][cnt], dp[i][cnt - 1]);

                // Find pos of last event intersecting with i-th event
                auto it{ std::lower_bound(events.begin(), events.begin() + i, events[i][0], [](std::vector<int>& e, int start){
                    return e[1] < start;
                }) };

                int pos{ 0 };
                pos = it - events.begin() - 1;
                
                // dp[pos][cnt - 1] is last known configuration with endTime < events[i].startTime

                if (pos >= 0) {
                    // Take i-th event into consideration
                    dp[i][cnt] = std::max(dp[i][cnt], dp[pos][cnt - 1] + events[i][2]);
                }
            }
        }

        return dp[n - 1][k];
    }
};
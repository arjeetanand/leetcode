class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) {
            return 0;
        }
        std::sort(nums.begin(), nums.end());
        return (nums[n - 1] - 1) * (nums[n - 2] - 1);
    }
};
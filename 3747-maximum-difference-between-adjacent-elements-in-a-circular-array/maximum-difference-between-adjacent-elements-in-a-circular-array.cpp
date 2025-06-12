class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        
        int maxi = INT_MIN;
        for(int i=1; i<nums.size(); i++) {
            maxi = max(abs(nums[i-1] - nums[i]), maxi);
        }
        maxi = max(maxi, abs(nums[nums.size()-1]-nums[0]));
        return maxi;
    }
};
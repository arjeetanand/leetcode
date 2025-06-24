class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n=nums.size();
        int i=0,j=0;
        vector<int> ans;
        while(i<n && j<n)
        {
            if(nums[j]==key)
            {
                while(abs(i-j)>k)
                i++;

                while(abs(i-j)<=k && i<n && j<n)
                {
                    ans.push_back(i);
                    i++;
                }
                j++;
            }
            else
            j++;
        }
        return ans;
    }
};
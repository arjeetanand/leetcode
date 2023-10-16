class Solution {
public:
int findMaxConsecutiveOnes(vector<int>& nums) {
    int mx=0, cnt=0;
    
    for (auto i:nums) {
        if(i==1) cnt++;
        else {
            mx = max(mx,cnt);
            cnt=0;
        }
    }
    mx = max(mx,cnt);
    return mx;
}
};
class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        int more= n/4;
        unordered_map<int, int> mp;
        int count=0;
        for (int i=0;i<n; i++){
            mp[arr[i]]++;
        }

        for(auto x: mp){
            if(x.second>more){
                return x.first;
            }
        }
        return more;
    }
};
class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> arr;
        int n = s.length();
        int i = 0;
        string ans;
        while(i < n){
            ans = s.substr(i, k);
            if(ans.length() == k){
                arr.push_back(ans);
            }
            i += k;
        }
        if(ans.length() < k){
            int remain = k - ans.length();
            while(remain--){
                ans += fill;
            }
            arr.push_back(ans);
        }
        return arr;
    }
};
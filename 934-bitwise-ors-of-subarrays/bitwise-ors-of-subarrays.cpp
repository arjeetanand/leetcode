class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> currSet, ans;
        for(int i = 0; i < arr.size(); i++) {
            unordered_set<int> nextSet;
            for(int prev: currSet) {
                nextSet.insert(prev | arr[i]);
            }
            nextSet.insert(arr[i]);
            currSet = nextSet;
            for(int num: currSet) {
                ans.insert(num);
            }
        }
        return ans.size();
    }
};
class Solution {
    void combination(vector<int>& candidates, int target, vector<int> &currComb, int index, vector<vector<int>>& ans){
        if(index==candidates.size()){
            if(target==0){
                ans.push_back(currComb);
            }
            return;
        }

        if(candidates[index]<= target){
            currComb.push_back(candidates[index]);
            combination(candidates, target-candidates[index], currComb, index, ans);
            currComb.pop_back();
        }
        combination(candidates, target, currComb, index+1, ans);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> currComb;
        combination(candidates, target, currComb, 0, ans);
        return ans;
    }
};
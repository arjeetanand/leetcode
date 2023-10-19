class Solution {
public:
    void combination(vector<int>& candidates, int target, vector<int> &currComb, int index, vector<vector<int>>& ans){
        if(target==0){
            ans.push_back(currComb);
            return;
        }
        for( int i=index; i<candidates.size();i++){    
            if(i>index && candidates[i]==candidates[i-1]) continue;
            if( candidates[i] > target) break;
            currComb.push_back(candidates[i]);
            combination(candidates, target-candidates[i], currComb, i+1, ans);
            currComb.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> currComb;
        combination(candidates, target, currComb, 0, ans);
        return ans;
    }
};

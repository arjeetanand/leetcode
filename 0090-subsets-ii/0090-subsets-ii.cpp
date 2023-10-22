class Solution {
public:
void helper(vector<int> &arr,int i,vector<int> &curr,vector<vector<int>> &res)
    { 
        res.push_back(curr);
        for(int j=i; j<arr.size();j++){
            if(j!=i && arr[j]==arr[j-1]) continue;
            curr.push_back(arr[j]);
            helper(arr,j+1,curr,res);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        vector<vector<int>> res;
        vector<int> curr;
        helper(arr,0,curr,res);
        return res;
    }
};

class Solution {
public:
void helper(vector<int> &arr,int i,vector<int> curr,vector<vector<int>> &res)
    { 
        if(i==arr.size())
        {  
            res.push_back(curr);           
            return;
        }
        curr.push_back(arr[i]);
        helper(arr,i+1,curr,res);
        curr.pop_back();
        int j=i;
        while(j<arr.size()-1 && arr[j]==arr[j+1])j++;
        helper(arr,j+1,curr,res);
        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        vector<vector<int>> res;
        vector<int> curr;

        helper(arr,0,curr,res);

        return res;
    }
};

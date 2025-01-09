class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> map;
        vector<int> ans;
        stack<int> st;
        int n= nums2.size();

        for(int i = n-1; i>=0; i--){
            int m= nums2[i];
            while(!st.empty() && st.top()<=m) st.pop();

            int res= (st.empty()) ? -1 : st.top();
            map.insert({m,res});
            st.push(m);
        }
        for(auto j: nums1){
            ans.push_back(map[j]);
    }
    return ans;
    }
};
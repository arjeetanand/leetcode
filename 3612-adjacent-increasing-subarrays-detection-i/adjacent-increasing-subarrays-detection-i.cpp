class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        vector<pair<int,int>> v;
        int ptr = nums.size()-1;
        stack<int> st;
        stack<int> empty;
        if(k==1) return true;
        while(ptr>=0){
            if(!st.empty() && ptr>=0 && nums[ptr]<nums[st.top()]){
                int end = st.top();
                while(ptr>=0 && nums[ptr]<nums[st.top()]){
                    st.push(ptr);
                    ptr--;
                }
                int start = st.top();
                v.push_back({start,end});
                st=empty;
            }
            st.push(ptr);
            ptr--;
        }
        // for(auto i:v){
        //     cout<<i.first<<" "<<i.second<<endl;
        // }
        if(v.size()==1){
            int diff = v[0].second-v[0].first+1;
            if(diff>=2*k) return true;
        }
        for(int i=1;i<v.size();i++){
            int a1 = v[i].first;
            int b1 = v[i].second;
            int a2 = v[i-1].first;
            int b2 = v[i-1].second;
            int diff1 = b2-a2+1;
            int diff2 = b1-a1+1;
            if(diff1>=k && diff1>=2*k) return true;
            if(diff2>=k && diff2>=2*k) return true;
            if(diff1>=k && diff2>=k && a2-b1 ==1 ) return true;
        }
        return false;
        
    }
};
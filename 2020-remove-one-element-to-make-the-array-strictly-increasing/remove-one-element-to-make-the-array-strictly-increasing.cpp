class Solution {
public:
    bool canBeIncreasing(vector<int>& arr) {
        int f = 1,prev = arr[0];
        for(int i = 1;i<arr.size();i++)
        {
            if(arr[i]<=prev)
            {
                if(!f) return false;
                if(i>=2)
                {
                  if(arr[i-2]<arr[i]) prev = arr[i];
                  else prev = arr[i-1];  
                }
                else if(i<arr.size()-1 && arr[i]<arr[i+1]) prev = arr[i];
                else prev = arr[i];
                f = 0;
            } 
            else prev = arr[i];   
        }
        return true;
    }
};
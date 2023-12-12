class Solution {
public:
    int maxProduct(vector<int>& nums) {
    //     int right=0, left=0;
    //     int n= nums.size();
    //     int product=nums[0];
    //     int maxi=0;
    //     while(right<n){
    //         while(left<right){
    //             product= product-1 / nums[left]-1;
    //             left++;
    //             maxi= max(maxi, product);
    //         }
            
    //         if(right<n){
    //         right++;
    //         product= product-1 * nums[right]-1;
    //         maxi= max(maxi, product);
    //         }

    //     }
    //     return maxi;
    // }
           int n = nums.size();
        
        if (n < 2) {
            // Handle the case where the array has less than two elements.
            return 0;
        }

        std::sort(nums.begin(), nums.end()); // Sort the array in ascending order.
        
        // Calculate the maximum product by selecting the two largest elements.
        return (nums[n - 1] - 1) * (nums[n - 2] - 1);
    }
};
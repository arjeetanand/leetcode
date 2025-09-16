#include <vector>
#include <numeric>  // for std::gcd
using namespace std;

class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> res;
        
        for (int num : nums) {
            res.push_back(num);
            
            while (res.size() >= 2) {
                int x = res[res.size() - 2];
                int y = res[res.size() - 1];
                int gcd_val = gcd(x, y);
                
                if (gcd_val > 1) {
                    long long lcm_val = (1LL * x * y) / gcd_val;
                    res.pop_back();
                    res.pop_back();
                    res.push_back((int)lcm_val);
                } else {
                    break;
                }
            }
        }
        
        return res;
    }

    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
};
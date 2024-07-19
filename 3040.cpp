#include <vector>
#include <iostream>
using namespace std;


class Solution {
    int maxOp(const vector<int>& nums, int l, int r, int value) {
        // maximum operations for nums[l:r] (l inclusive, r inclusive)
        // where all the sums equal value
        if (r - l == 0) return nums[l] == value ? 1 : 0;
        else if (r - l == 1) return nums[l] + nums[r] == value ? 1 : 0;
        
        int result = 0;
        
        if (nums[l] + nums[l+1] == value) {
            result = max(result, maxOp(nums, l+2, r, value) + 1);
        } 
        if (nums[r] + nums[r-1] == value) {
            result = max(result, maxOp(nums, l, r-2, value) + 1);
        }
        if (nums[l] + nums[r] == value) {
            result = max(result, maxOp(nums, l+1, r-1, value) + 1);
        }
        
        return result;
    }
public:
    int maxOperations(vector<int>& nums) {
        int n = nums.size();        
        int v1 = nums[0] + nums[1];
        int v2 = nums[n-2] + nums[n-1];
        int v3 = nums[0] + nums[n-1];

        int result = 0;
        int r1 = maxOp(nums, 2, n-1, v1);
        int r2 = maxOp(nums, 0, n-3, v2);
        int r3 = maxOp(nums, 1, n-2, v3);
        if (r1 > 0) {
            result = max(result, 1 + r1);
        }
        if (r2 > 0) {
            result = max(result, 1 + r2);
        }
        if (r3 > 0) {
            result = max(result, 1 + r3);
        }
        return result;
    }
};

int main() {
    vector<int> nums = {3,2,1,2,3,4};
    Solution sol = Solution();
    cout << sol.maxOperations(nums) << endl;
}


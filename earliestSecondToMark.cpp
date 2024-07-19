#include <vector>
#include <unordered_map>

class Solution {
    bool check(vector<int>& nums, vector<int>& changeIndices, int s_max) {
        // check up to second s_max (exclusive)
        // if 
        unordered_map<int, int> last;
        for (int s=0; s<s_max; ++s) {
            last[changeIndices[s]] = s;
        }
        
        int cnt = 0; // count how many numbers we can reduce up to a certain time
        for (int s=0; s<s_max; ++s) {
            if (s == last[changeIndices[s]]) {
                if (cnt - nums[changeIndices[s]-1] < 0) return false;
                else cnt -= nums[changeIndices[s]-1];
            } else {
                ++cnt;
            }
        }
        
        return true;
    }
public:
    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices) {
        int m = changeIndices.size();
        int l=0, r=m;
        int mid;
        while (r - l > 0) { // ?
            mid = (l + r) / 2;
            if (check(nums, changeIndices, mid)) {
                r = mid;
            } else {
                l = mid;
            }
        }
    }
};

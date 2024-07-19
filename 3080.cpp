class Solution {

    
public:
    vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<ind> ni; // nums with indices
        for (int i=0; i<n; ++i) {
            ni.push_back({nums[i], i});
        }
        
        sort(ni.begin(), ni.end());
        
        long long s = 0; // sum of unmarked elms
        for (auto n : nums) {
            s += n;
        }
        
        vector<long long> res;
        
        vector<bool> marked(n, false); // only consider marking indices >= l and unmarked
        int l = 0;
        for (auto q : queries) {
            int idx_to_mark = q[0];
            for (int i = l; i < n; ++i) {
                if (ni[i].index = idx_to_mark) {
                    marked[i] = true;
                    s -= ni[i].num;
                    break;
                }
            }
            
            while (q[1] > 0 && l < n) {
                if (!marked[l]) {
                    marked[l] = true;
                    s -= ni[l].num;
                    --q[1];
                }              
                ++l;
            }
            
            res.push_back(s);
        }
        
        return res;
    }
};

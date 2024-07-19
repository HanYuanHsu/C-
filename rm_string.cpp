#include <vector>
#include <string>

class Solution {

public:
    string lastNonEmptyString(string s) {
        vector<int> orderToRemove(s.length());
        int curMaxOrder[26] = {0}; // the current maximum order of a character

        for (int i=0; i<s.length(); ++i) {
            orderToRemove[i] = ++curMaxOrder[s[i] - 'a']; // the curMaxOrder of the character
                                                          // s[i] is incremented first
        }
        int maxOrder = 0;
        for (int order : orderToRemove) {
            maxOrder = max(maxOrder, order);
        }

        string result = "";
        for (int i=0; i<s.length(); ++i) {
            if (orderToRemove[i] == maxOrder) {
                result += s[i];
            }
        }

        return result;
    }
};



/* second solution
// TLE 656 / 697 test cases passed.
class Solution {
    string rm(const string& s)
    {
        bool hasRemoved[26] = {false};
        vector<bool> mask(s.length(), true); // true means keep that character
        string result = "";

        for (int i=0; i<s.length(); ++i)
        {
            if (!hasRemoved[s[i] - 'a']) {
                mask[i] = false;
                hasRemoved[s[i] - 'a'] = true;
            }
        }

        for (int i=0; i<s.length(); ++i) {
            if (mask[i]) result += s[i];
        }

        return result;
    }

public:
    string lastNonEmptyString(string s) {
        string next_s = rm(s);
        while (next_s != "") {
            s = next_s;
            next_s = rm(s);       
        }
        return s;
    }
};
*/



/* First version:

#include <vector>
#include <iostream>
using namespace std;

struct Mask {
    vector<bool> mask;
    int mask_size;
};

class Solution {}
    
    
    void rm(string s, const Mask& mask, Mask& next_mask) // modifies a mask on the string s indicating which characters are left
    {
        bool hasRemoved[26] = {false};
        for (int i = 0; i < s.length(); ++i)
        {
            if (mask[i] == false) continue;
            
            if (!hasRemoved[s[i] - 'a']) {
                next_mask[i] = false;
                --mask_size;
                hasRemoved[s[i] - 'a'] = true;
            }
        }
        return mask_size;
    }
public:
    string lastNonEmptyString(string s) {
        vector<bool> prev_mask(s.length(), true);
        vector<bool> cur_mask(s.length(), true);
        int prev_mask_size = s.length();
        int cur_mask_size = rm(s, cur_mask, s.length()); // size of the current mask
        
        while (cur_mask_size > 0)
        {

            
            prev_mask_size = rm(s, prev_mask, prev_mask_size);
            cur_mask_size = rm(s, cur_mask, cur_mask_size);
        }
        
        string result = "";
        for (int i=0; i<prev_mask.size(); ++i)
        {
            if (prev_mask[i]) result += s[i];
        }
        return result;
    }
};



*/

#include <vector>
#include <sstream>
#include <iostream>
using namespace std;

class Solution {
    using freqpair = pair<char, int>; // <digit, frequency>
    vector<freqpair> calc_freq(const string& digits) {
        // digits should end with '#' to denote the digit has ended

        vector<freqpair> ans;
        char cur = digits[0];
        int freq = 1;
        for (int i=1; i<digits.length(); ++i) {
            if (digits[i] != cur) {
                ans.push_back({cur, freq});
                cur = digits[i];
                freq = 1;
            } else {
                ++freq;
            }
        }class Solution {
    using freqpair = pair<char, int>; // <digit, frequency>
    vector<freqpair> calc_freq(const string& digits) {
        // digits should end with '#' to denote the digit has ended

        vector<freqpair> ans;
        char cur = digits[0];
        int freq = 1;
        for (int i=1; i<digits.length(); ++i) {
            if (digits[i] != cur) {
                ans.push_back({cur, freq});
                cur = c;
                freq = 1;
            } else {
                ++freq;
            }
        }

        return ans;
    }

    string convert(vector<freqpair> v) {
        stringstream ss;
        for (auto fp : v) {
            ss << fp.second << fp.first;
        }
        return ss.str();
    }
public:
    string countAndSay(int n) {
        
    }
};


        return ans;
    }

    string convert(vector<freqpair> v) {
        stringstream ss;
        for (auto fp : v) {
            ss << fp.second << fp.first;
        }
        return ss.str();
    }
public:
    string countAndSay(int n) {
        return "";
    }

    string test(string digits) {
        return convert(calc_freq(digits));
    }
};

int main() {
    Solution sol = Solution();
    string s = "3322251";
    s += '#';
    cout << sol.test(s) << endl;

    return 0;
}

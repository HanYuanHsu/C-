#include <string>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

class Solution0 {
    vector<bool> has_substring_array(const vector<string>& arr, string t) {
        vector<bool> result;
        int n = arr.size();
        for (int i=0; i<n; ++i) {
            size_t found = arr[i].find(t);
            result.push_back(found != string::npos);
        }
    }
public:
    vector<string> shortestSubstrings(vector<string>& arr) {
        int n = arr.size();
        unordered_map<string, vector<bool>> mp;
        for (int i=0; i<n; ++i) {
            for (int l=0; l<arr[i].length(); ++l) {
                for (int k=1; l+k<=arr[i].length(); ++k) {
                    // k is length of the substring
                    string t = arr[i].substr(l, k);
                    auto it = mp.find(t);
                    if (it == mp.end()) {
                        mp[t] = has_substring_array(arr, t);
                    }
                }
            }
        }

        
    }
};

class Solution {

public:
    vector<string> shortestSubstrings(vector<string>& arr) {
        int n = arr.size();

        // should_consider[t] = true: 
        // should_consider[t] = false: t does not match what the question wants
        // should_consider does not have t: t not yet visited
        unordered_map<string, bool> should_consider;

        vector<string> shortest(n);

        for (int i=0; i<n; ++i) {
            for (int l=0; l<arr[i].length(); ++l) {
                for (int k=1; l+k<=arr[i].length(); ++k) {
                    // k is length of the substring
                    string t = arr[i].substr(l, k);
                    if (should_consider.find(t) == should_consider.end()) {
                        
                    }
                }
            }
        }
    }
};

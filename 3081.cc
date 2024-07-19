#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

struct pa {
    int char_idx;
    int count;
};

bool operator< (const pa& a, const pa& b) {
    return a.count < b.count || (a.count == b.count && a.char_idx < b.char_idx);
}

class LetterCounter {
    vector<int> cnt;
    
public:   
    int max_letter_idx; // records the rightmost letter with positive count
    
    LetterCounter() : cnt(26, 0), max_letter_idx(-1) {}
    
    int get(int char_idx) {
        return cnt[char_idx];
    }
    
    void increment(int char_idx) {
        ++cnt[char_idx];
        max_letter_idx = char_idx;
    }

    friend ostream& operator<< (ostream& os, const LetterCounter& lc) {
        os << "Hello World";
        return os;
    }
};

class Solution {
public:
    string minimizeStringValue(string s) {
        vector<int> cnt(26, 0);
        int n_qmark = 0;
        priority_queue<int, vector<int>, greater<int>> qmark_loc;
        for (int i=0; i<s.length(); ++i) {
            if (s[i] == '?') {
                ++n_qmark;
                qmark_loc.push(i);
            } else {
                cnt[s[i] - 'a']++; // this is probably inefficient. Too many zeros
            }
        }
        
        vector<pa> cnt_pa;
        for (int i=0; i<26; ++i) {
            cnt_pa.push_back({i, cnt[i]});
        }
        
        sort(cnt_pa.begin(), cnt_pa.end());
        
        //priority_queue<int, greater<int>> pq; // min pq
        //unordered_map<int, int> res; // res[char_idx] = number of char to fill in the ?'s
        
        /*
        int threshold = 0;
        int th_i = 0;
        int i = 0;
        while (n_qmark > 0) {
            if (cnt_pa[i].count > threshold) {
                threshold = cnt_pa[i].count;
                th_i = i;
            }
            
            while (i < th_i) {
                
            }
            
            n_qmark--;
        }*/

        cout << "cnt_pa:" << endl;
        for (auto& pa : cnt_pa) {
            cout << "char_idx:" << pa.char_idx << " ";
            cout << "count:" <<  pa.count << endl;
        }
        
        int i = 0;
        int next_i, next_c, c;
        LetterCounter counter = LetterCounter();
        while (n_qmark > 0) {
            c = cnt_pa[i].char_idx; // current character (index of it)
            counter.increment(c);
            n_qmark--;
            
            next_i = (i + 1) % 26;
            next_c = cnt_pa[next_i].char_idx;
            if (cnt_pa[next_i].count + counter.get(next_c) >= cnt_pa[i].count + counter.get(c)) {
                i = 0;
            } else {
                i = next_i;
            }
        }
        
        i = 0; // goes through 0~25, the character indices
        int cur_char_cnt = 0;
        while (!qmark_loc.empty()) {
            if (i > counter.max_letter_idx) break;

            // fast foward to the character with nonempty count
            if (cur_char_cnt <= 0) {
                while (counter.get(i) == 0) ++i;
            }
            cur_char_cnt = counter.get(i);

            int loc = qmark_loc.top(); qmark_loc.pop();   
            s[loc] = (char)(i + 'a');
            --cur_char_cnt;
        }
        
        return s;
    }
};

int main() {
    vector<string> test_cases = {"???", "a?a?"};
    Solution sol = Solution();
    for (auto s : test_cases) {
        cout << "------------" << endl;
        cout << sol.minimizeStringValue(s) << endl;

    }
    
}

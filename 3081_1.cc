#include <string>
#include <queue>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    string minimizeStringValue(string s) {
        using pii = pair<int, char>; // <count, character (lex order)>
        unordered_map<char, int> cnt;
        for (int i=0; i<26; ++i) {
            cnt['a' + i] = 0;
        }

        vector<int> qmark_loc;
        for (int i=0; i<s.length(); ++i) {
            if (s[i] == '?') {
                qmark_loc.push_back(i);
            } else {
                ++cnt[s[i]];
            }
        }

        /*
        cout << "q_mark_loc:" << endl;
        priority_queue<int, vector<int>, greater<int>> ql = qmark_loc;
        while (!ql.empty()) {
            cout << ql.top() << endl;
            ql.pop();
        }*/

        priority_queue<pii, vector<pii>, greater<pii>> pq;
        for (auto [ch, count] : cnt) {
            pq.push({count, ch});
        }

        priority_queue<char, vector<char>, greater<char>> emitter;
        for (int i=0; i<qmark_loc.size(); ++i) {
            emitter.push(pq.top().second);
            pq.push({pq.top().first + 1, pq.top().second});
            pq.pop();
        }

        /*
        cout << "pq:" << endl;
        priority_queue<pii, vector<pii>, greater<pii>> pq1 = pq;
        while (!pq1.empty()) {
            cout << pq1.top().first << " " << pq1.top().second << endl;
            pq1.pop();
        }*/

        for (auto idx : qmark_loc) {
            s[idx] = emitter.top();
            emitter.pop();
        }

        return s;
    }
};

int main() {
    Solution sol = Solution();
    cout << sol.minimizeStringValue("???") << endl;
    cout << sol.minimizeStringValue("a?a?") << endl;

    return 0;

}


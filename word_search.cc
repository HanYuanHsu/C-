#include <string>
#include <vector>
#include <set>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
    vector<string> ans;
    int m, n;

    struct TrieNode {
        bool isWord;
        bool visited;
        unordered_map<char, TrieNode*> children;

        TrieNode() : isWord(false), visited(false) {};
    };

    bool ok(int i, int j) {
        return 0 <= i && i < m && 0 <= j && j < n;
    }

    void insert(TrieNode* root, const string& s) {
        for (char c : s) {
            if (root->children.find(c) == root->children.end()) {
                root->children[c] = new TrieNode();
            }

            root = root->children[c];
        }

        root->isWord = true;
    }

    void dfs(vector<vector<char>>& board, const string& prefix, TrieNode* current, int i, int j) {
        char cur_char = board[i][j];

        if (current->isWord && !current->visited) {
            current->visited = true;
            ans.push_back(prefix);
        }
        
        // set (i, j) as visited first
        board[i][j] = '#';

        int di[4] = {1, 0, -1, 0};
        int dj[4] = {0, 1, 0, -1};
        for (int k=0; k<4; ++k) {
            if (!ok(ni, ))
            int ni = i + di[k];
            int nj = j + dj[k];
            char next_char = board[ni][nj];
            bool hasChild = current->children.find(next_char) != current->children.end();
            if (ok(ni, nj) && next_char != '#' && hasChild) {
                dfs(board, prefix + next_char, current->children[next_char], ni, nj);
            }
        }

        board[i][j] = cur_char;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // initialize
        ans.clear();
        m = board.size();
        n = board[0].size();

        TrieNode* root = new TrieNode();

        for (const string& word : words) {
            insert(root, word);
        }

        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                dfs(board, "", root, i, j);
            }
        }

        return ans;
    }
};

int main() {
    Solution sol = Solution();
    std::vector<std::vector<char>> input = {
        {'o', 'a', 'a', 'n'},
        {'e', 't', 'a', 'e'},
        {'i', 'h', 'k', 'r'},
        {'i', 'f', 'l', 'v'}
    };

    vector<string> words = {"oath","pea","eat","rain"};
    vector<string> ans = sol.findWords(input, words);

    for (auto& s : ans) {
        cout << s << endl;
    }

    return 0;
}

// segmentation fault

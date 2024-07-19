#include <unordered_map>
#include <string>

struct TrieNode {
    std::unordered_map<char, TrieNode*> children;
    bool isWord;

    TrieNode() : isWord(false) {}
};

class Trie {
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(const std::string& s) {
        TrieNode* current = root;

        for (char c : s) {
            if (current->children.find(c) == current->children.end()) {
                current->children[c] = new TrieNode();
            }

            current = current->children[c];
        }

        current->isWord = true;
    }

    bool search(const std::string& s) {
        TrieNode* p = root;
        for (char c : s) {
            if (p->children.find(c) == p->children.end()) {
                return false;
            }

            p = p->children[c];
        }

        return p->isWord;
    }

    bool startsWith(const std::string& prefix) {
        
    }
};

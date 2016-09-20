class TrieNode {
public:
    bool isWord = false;
    TrieNode * children[26];
    // Initialize your data structure here.
    TrieNode() {
        memset (children, NULL, sizeof(children));
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode * cur = root;
        for (int i = 0; i < word.size(); i++) {
            int index = word[i] - 'a';
            if (cur->children[index] == NULL)
                cur->children[index] = new TrieNode ();
            cur = cur->children[index];
        }
        cur->isWord = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode * cur = root;
        for (int i = 0; i < word.size(); i++) {
            int index = word[i] - 'a';
            if (cur->children[index] == NULL)
                return false;
            cur = cur->children[index];
        }
        return cur->isWord;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode * cur = root;
        for (int i = 0; i < prefix.size(); i++) {
            int index = prefix[i] - 'a';
            if (cur->children[index] == NULL)
                return false;
            cur = cur->children[index];
        }
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");

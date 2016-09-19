\\ 用trie tree存储，root表示孔字串，注意类的定义方法. 用DFS搜索.

class WordDictionary {
public:
    class TrieNode {
    public:
        bool isWord = false;
        TrieNode* children[26];
        TrieNode() { memset(children, NULL, sizeof(children)); }
    };
    
    TrieNode * root = new TrieNode(); // root 表示一个空字串.
    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode * cur = root;
        for (int i = 0; i < word.size(); i++) {
            int index = word[i] - 'a';
            if (cur->children[index] == NULL)
                cur->children[index] = new TrieNode ();
            cur = cur->children[index];
        }
        cur->isWord = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return DFS (word, 0, root);
    }
    
    bool DFS (string& word, int pos, TrieNode * root) {
        if (pos == word.size())
            return root->isWord;
        if (word[pos] == '.') {
            for (int i = 0; i < 26; i++) {
                if (root->children[i] && DFS (word, pos + 1, root->children[i]))
                    return true;
            }
            return false;
        }    
        
        int index = word[pos] - 'a';
        if (root->children[index] == NULL)
            return false;
        return DFS (word, pos + 1, root->children[index]);
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");

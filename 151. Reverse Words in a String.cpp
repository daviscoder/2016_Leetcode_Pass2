/**
 * O(n), O(1)
 * remove all redundant spaces before meeting a word. j is the beginning of the word,
 * and i is the end of word. Finally remove the last space is exists.
 * Test cases: empty string, string only contains space, contains leading space, 
 * contains tailing spaces, contains duplicate spaces between words.
 */

class Solution {
public:
    void reverseWords(string &s) {
        reverse (s.begin(), s.end());
        for (int i = 0; i < s.size();) {
            while (i < s.size() && s[i] == ' ')
                s.erase (i, 1);
            int j = i;
            while (i < s.size() && s[i] != ' ')
                i++;
            reverse (s.begin() + j, s.begin() + i);
            i++;
        }
        if (s.size() > 0 && s[s.size()  -1] == ' ')
            s.erase (s.size() - 1, 1);
    }
};

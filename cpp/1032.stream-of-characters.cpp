/*
 * @lc app=leetcode id=1032 lang=cpp
 *
 * [1032] Stream of Characters
 *
 * https://leetcode.com/problems/stream-of-characters/description/
 *
 * algorithms
 * Hard (48.25%)
 * Likes:    399
 * Dislikes: 65
 * Total Accepted:    22.1K
 * Total Submissions: 45.8K
 * Testcase Example:  '["StreamChecker","query","query","query","query","query","query","query","query","query","query","query","query"]\n' +
  '[[["cd","f","kl"]],["a"],["b"],["c"],["d"],["e"],["f"],["g"],["h"],["i"],["j"],["k"],["l"]]'
 *
 * Implement the StreamChecker class as follows:
 * 
 * 
 * StreamChecker(words): Constructor, init the data structure with the given
 * words.
 * query(letter): returns true if and only if for some k >= 1, the last k
 * characters queried (in order from oldest to newest, including this letter
 * just queried) spell one of the words in the given list.
 * 
 * 
 * 
 * 
 * Example:
 * 
 * 
 * StreamChecker streamChecker = new StreamChecker(["cd","f","kl"]); // init
 * the dictionary.
 * streamChecker.query('a');          // return false
 * streamChecker.query('b');          // return false
 * streamChecker.query('c');          // return false
 * streamChecker.query('d');          // return true, because 'cd' is in the
 * wordlist
 * streamChecker.query('e');          // return false
 * streamChecker.query('f');          // return true, because 'f' is in the
 * wordlist
 * streamChecker.query('g');          // return false
 * streamChecker.query('h');          // return false
 * streamChecker.query('i');          // return false
 * streamChecker.query('j');          // return false
 * streamChecker.query('k');          // return false
 * streamChecker.query('l');          // return true, because 'kl' is in the
 * wordlist
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= words.length <= 2000
 * 1 <= words[i].length <= 2000
 * Words will only consist of lowercase English letters.
 * Queries will only consist of lowercase English letters.
 * The number of queries is at most 40000.
 * 
 * 
 */

// @lc code=start
class TrieNode {
  public:
    bool isWord;
    unordered_map<char, TrieNode*> children;
    TrieNode() {isWord=false;}
    void insert (string& word) {
        TrieNode *cur,*child;
        cur = this;
        for (int i = word.size()-1; i >= 0; i--) {
            auto it = cur->children.find(word[i]);
            if (it == cur->children.end()) {
                child = new TrieNode();
                cur->children.insert({word[i], child});
            } else child = it->second;
            cur = child;
        }
        cur->isWord = true;
    }
    
    bool search (string& word) {
        TrieNode *cur;
        cur = this;
        for (int i = word.size()-1; i >= 0; i--) {
            auto it = cur->children.find(word[i]);
            if (it == cur->children.end()) break;
            else cur = it->second;
            if (cur->isWord) break;
        }
        return cur->isWord;
    }
};

class StreamChecker {
    TrieNode* root;
    unordered_set<string> wordSet;
    string S;
public:
    StreamChecker(vector<string>& words) {
        root = new TrieNode();
        for (int i = 0; i < words.size(); i++) root->insert(words[i]);
    }
    
    bool query(char letter) {
        S += letter;
        return root->search(S);
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
// @lc code=end


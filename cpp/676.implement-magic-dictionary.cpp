/*
 * @lc app=leetcode id=676 lang=cpp
 *
 * [676] Implement Magic Dictionary
 *
 * https://leetcode.com/problems/implement-magic-dictionary/description/
 *
 * algorithms
 * Medium (54.49%)
 * Likes:    633
 * Dislikes: 138
 * Total Accepted:    42.5K
 * Total Submissions: 77.7K
 * Testcase Example:  '["MagicDictionary", "buildDict", "search", "search", "search", "search"]\n' +
  '[[], [["hello","leetcode"]], ["hello"], ["hhllo"], ["hell"], ["leetcoded"]]'
 *
 * Design a data structure that is initialized with a list of different words.
 * Provided a string, you should determine if you can change exactly one
 * character in this string to match any word in the data structure.
 * 
 * Implement the MagicDictionary class:
 * 
 * 
 * MagicDictionary() Initializes the object.
 * void buildDict(String[] dictionary) Sets the data structure with an array of
 * distinct strings dictionary.
 * bool search(String searchWord) Returns true if you can change exactly one
 * character in searchWord to match any string in the data structure, otherwise
 * returns false.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input
 * ["MagicDictionary", "buildDict", "search", "search", "search", "search"]
 * [[], [["hello", "leetcode"]], ["hello"], ["hhllo"], ["hell"], ["leetcoded"]]
 * Output
 * [null, null, false, true, false, false]
 * 
 * Explanation
 * MagicDictionary magicDictionary = new MagicDictionary();
 * magicDictionary.buildDict(["hello", "leetcode"]);
 * magicDictionary.search("hello"); // return False
 * magicDictionary.search("hhllo"); // We can change the second 'h' to 'e' to
 * match "hello" so we return True
 * magicDictionary.search("hell"); // return False
 * magicDictionary.search("leetcoded"); // return False
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= dictionary.length <= 100
 * 1 <= dictionary[i].length <= 100
 * dictionary[i] consists of only lower-case English letters.
 * All the strings in dictionary are distinct.
 * 1 <= searchWord.length <= 100
 * searchWord consists of only lower-case English letters.
 * buildDict will be called only once before search.
 * At most 100 calls will be made to search.
 * 
 * 
 */

// @lc code=start
class MagicDictionary {
public:
    /** Initialize your data structure here. */
    struct Node {
        bool isEnd;
        Node* children[26];
    };
    
    Node* newNode() {
        Node* node = new Node;
        node->isEnd = false;
        for(int i=0;i<26;i++) {
            node->children[i] = NULL;
        }
        return node;
    }
    
    Node* root;
    
    void find(Node* root, string s, int c, bool &flag) {
        if(c>1) {
            return ;
        }
        if(flag) {
            return;
        }
        if(s.size()==0) {
            if(root->isEnd && c==1) {
                flag = true;
            }
            return;
        }
        if(!root) {
            return;
        }
        Node* curr = root;
        int idx = s[0]-'a';
        for(int i=0;i<26;i++) {
            if(curr->children[i]) {
                if(i!=idx) {
                    find(curr->children[i], s.substr(1), c+1, flag);
                } else {
                    find(curr->children[i], s.substr(1), c, flag);
                }
            }
        }
    }
    
    MagicDictionary() {
        root = newNode();
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        Node* curr;
        for(auto s: dict) {
            curr = root;
            for(auto c: s) {
                if(curr->children[c-'a']==NULL) {
                    curr->children[c-'a'] = newNode();
                }
                curr = curr->children[c-'a'];
            }
            curr->isEnd = true;
        }
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        bool flag = false;
        find(root, word, 0, flag);
        return flag;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */
// @lc code=end
// 

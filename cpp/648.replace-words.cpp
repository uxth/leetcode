/*
 * @lc app=leetcode id=648 lang=cpp
 *
 * [648] Replace Words
 *
 * https://leetcode.com/problems/replace-words/description/
 *
 * algorithms
 * Medium (56.52%)
 * Likes:    785
 * Dislikes: 134
 * Total Accepted:    59K
 * Total Submissions: 103.4K
 * Testcase Example:  '["cat","bat","rat"]\n"the cattle was rattled by the battery"'
 *
 * In English, we have a concept called root, which can be followed by some
 * other word to form another longer word - let's call this word successor. For
 * example, when the root "an" is followed by the successor word "other", we
 * can form a new word "another".
 * 
 * Given a dictionary consisting of many roots and a sentence consisting of
 * words separated by spaces, replace all the successors in the sentence with
 * the root forming it. If a successor can be replaced by more than one root,
 * replace it with the root that has the shortest length.
 * 
 * Return the sentence after the replacement.
 * 
 * 
 * Example 1:
 * Input: dictionary = ["cat","bat","rat"], sentence = "the cattle was rattled
 * by the battery"
 * Output: "the cat was rat by the bat"
 * Example 2:
 * Input: dictionary = ["a","b","c"], sentence = "aadsfasf absbs bbab cadsfafs"
 * Output: "a a b c"
 * Example 3:
 * Input: dictionary = ["a", "aa", "aaa", "aaaa"], sentence = "a aa a aaaa aaa
 * aaa aaa aaaaaa bbb baba ababa"
 * Output: "a a a a a a a a bbb baba a"
 * Example 4:
 * Input: dictionary = ["catt","cat","bat","rat"], sentence = "the cattle was
 * rattled by the battery"
 * Output: "the cat was rat by the bat"
 * Example 5:
 * Input: dictionary = ["ac","ab"], sentence = "it is abnormal that this
 * solution is accepted"
 * Output: "it is ab that this solution is ac"
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= dictionary.length <= 1000
 * 1 <= dictionary[i].length <= 100
 * dictionary[i] consists of only lower-case letters.
 * 1 <= sentence.length <= 10^6
 * sentence consists of only lower-case letters and spaces.
 * The number of words in sentence is in the range [1, 1000]
 * The length of each word in sentence is in the range [1, 1000]
 * Each two consecutive words in sentence will be separated by exactly one
 * space.
 * sentence does not have leading or trailing spaces.
 * 
 * 
 */

// @lc code=start
struct Trie
{
    unordered_map<char, Trie*> children;
    bool word;
    bool search(string& s, string& res)
    {
        // printf("search: %s\n", s.c_str());
        Trie* cur = this;
        int i=0;
        while(i<s.size() && cur->children.count(s[i]))
        {
            cur = cur->children[s[i]];
            ++i;
            if(cur->word)
            {
                res = s.substr(0,i);
                return true;
            }
        }
        return false;
    }
    void insert(string& s)
    {
        // printf("insert: %s\n", s.c_str());
        Trie* cur = this;
        for(int i=0; i<s.size(); ++i)
        {
            if (cur->children.count(s[i]) == 0)
            {
                cur->children[s[i]] = new Trie();
            }
            cur = cur->children[s[i]];
        }
        cur->word = true;
    }
};
class Solution {
public:
    void split(const std::string& s,
        std::vector<std::string>& sv,
                    const char* delim = " ") {
        sv.clear(); 
        int start = 0;
        for(int i=0; i<=s.size(); ++i)
        {
            if(s[i] == ' ' || i == s.size())
            {
                sv.push_back(s.substr(start, i-start));
                start = i+1;
            }
        }
        return;
    }
    string replaceWords(vector<string>& dict, string sentence) {
        Trie* tree = new Trie();
        for(string& d : dict) tree->insert(d);
        string res;
        vector<string> filtered;
        split(sentence, filtered);
        for(string& i : filtered)
        {
            string s = i;
            if(tree->search(i, s))
                res += s + " ";
            else
                res += i + " ";
        }
        res.pop_back();
        return res;
    }
};
// @lc code=end


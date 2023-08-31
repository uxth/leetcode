/*
 * @lc app=leetcode id=677 lang=cpp
 *
 * [677] Map Sum Pairs
 *
 * https://leetcode.com/problems/map-sum-pairs/description/
 *
 * algorithms
 * Medium (53.46%)
 * Likes:    534
 * Dislikes: 83
 * Total Accepted:    43.2K
 * Total Submissions: 80.6K
 * Testcase Example:  '["MapSum", "insert", "sum", "insert", "sum"]\n' +
  '[[], ["apple",3], ["ap"], ["app",2], ["ap"]]'
 *
 * 
 * Implement a MapSum class with insert, and sum methods.
 * 
 * 
 * 
 * For the method insert, you'll be given a pair of (string, integer). The
 * string represents the key and the integer represents the value. If the key
 * already existed, then the original key-value pair will be overridden to the
 * new one.
 * 
 * 
 * 
 * For the method sum, you'll be given a string representing the prefix, and
 * you need to return the sum of all the pairs' value whose key starts with the
 * prefix.
 * 
 * 
 * Example 1:
 * 
 * Input: insert("apple", 3), Output: Null
 * Input: sum("ap"), Output: 3
 * Input: insert("app", 2), Output: Null
 * Input: sum("ap"), Output: 5
 * 
 * 
 * 
 */

// @lc code=start
class MapSum {
    public:
    struct trie { trie* ch[26] = {}; int sum = 0; } root;
    unordered_map<string, int> pairs;
    void insert(string key, int val) {
        auto p = &root;
        for (auto i = 0; i < key.size(); p->sum += val - pairs[key], ++i) 
            p = p->ch[key[i] - 'a'] = p->ch[key[i]  - 'a'] == nullptr ? new trie() : p->ch[key[i] - 'a'];
        pairs[key] = val;
    }
    int sum(string prefix) {
        auto p = &root;
        for (auto i = 0; i < prefix.size() && p != nullptr; p = p->ch[prefix[i] - 'a'], ++i) ;
        return p == nullptr ? 0 : p->sum;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
// @lc code=end


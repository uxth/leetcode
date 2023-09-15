/*
 * @lc app=leetcode id=745 lang=cpp
 *
 * [745] Prefix and Suffix Search
 */

// @lc code=start
// class WordFilter {
// private:
//     unordered_map<string, unordered_map<string,int>> pre;
//     unordered_map<string, unordered_map<string,int>> suf;
// public:
//     WordFilter(vector<string>& words) {
//         for(int i=0; i<words.size(); ++i){
//             string p = "";
//             for(int j=0; j<words[i].size(); ++j){
//                 p += words[i][j];
//                 pre[p][words[i]]=i;
//             }
//             p = "";
//             for(int j=words[i].size()-1; j>=0; --j){
//                 p = words[i][j]+p;
//                 suf[p][words[i]]=i;
//             }
//         }
//     }
    
//     int f(string pref, string suff) {
//         int res = -1;
//         for(auto& p : pre[pref]){
//             if(suf[suff].count(p.first)){
//                 res = max(res, p.second);
//             }
//         }
//         return res;
//     }
// };

struct Trie
{
	unordered_map<char, Trie*> nodes;
	set<int> weight;
};

class WordFilter {
private:
	Trie* prefix = new Trie();
	Trie* suffix = new Trie();
public:
    WordFilter(vector<string> words) {
        for (int j = 0; j < words.size(); ++j){
            auto& w = words[j];
            Trie* pre = prefix;
            pre->weight.insert(j);
            for (int i = 0; i < w.size(); ++i){
                if (pre->nodes.count(w[i]) == 0)
                    pre->nodes[w[i]] = new Trie();
                
                pre = pre->nodes[w[i]];pre->weight.insert(j);
            }

            Trie* suf = suffix;
            suf->weight.insert(j);
            for (int i = w.size() - 1; i >= 0; --i){
                if (suf->nodes.count(w[i]) == 0)
                    suf->nodes[w[i]] = new Trie();
                
                suf = suf->nodes[w[i]];suf->weight.insert(j);
            }
        }
    }
    
    int f(string prefix, string suffix) {
        Trie* pre = this->prefix;
        for (auto& c : prefix){
            if (!pre->nodes.count(c))
                return -1;
            pre = pre->nodes[c];
        }
        Trie* suf = this->suffix;
        for (int i = suffix.size() - 1; i >= 0; --i){
            char c = suffix[i];
            if (!suf->nodes.count(c))
                return -1;
            suf = suf->nodes[c];
        }
        for (auto it = pre->weight.rbegin(); it != pre->weight.rend(); ++it){
            if (suf->weight.count(*it))
                return *it;
        }
        return -1;      
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter obj = new WordFilter(words);
 * int param_1 = obj.f(prefix,suffix);
 */

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */
// @lc code=end

/*
["WordFilter","f", "f"]\n[[["apple"]],["ap","le"],["ap","e"]]
["WordFilter","f"]\n[[["abbba","abba"]],["ab","ba"]]
*/

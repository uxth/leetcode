/*
 * @lc app=leetcode id=833 lang=cpp
 *
 * [833] Find And Replace in String
 */

// @lc code=start
class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        string res = s;
        vector<tuple<int, string, string>> data;
        for(int i=0; i<indices.size(); ++i){
            if(s.substr(indices[i], sources[i].size()) == sources[i]){
                data.push_back({indices[i], sources[i], targets[i]});
            }
        }
        sort(begin(data), end(data), [](auto& a, auto& b){return get<0>(a) > get<0>(b);});
        for(auto [index, source, target] : data){
            res = res.substr(0, index) + target + res.substr(index+source.size());
        }
        return res;
    }
};
// @lc code=end
/*
"abcd"\n[0, 2]\n["ab","ec"]\n["eee","ffff"]
"vmokgggqzp"\n[3,5,1]\n["kg","ggq","mo"]\n["s","so","bfr"]
*/

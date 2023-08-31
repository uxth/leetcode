/*
 * @lc app=leetcode id=721 lang=cpp
 *
 * [721] Accounts Merge
 *
 * https://leetcode.com/problems/accounts-merge/description/
 *
 * algorithms
 * Medium (48.68%)
 * Likes:    1650
 * Dislikes: 324
 * Total Accepted:    95.1K
 * Total Submissions: 192.3K
 * Testcase Example:  '[["John","johnsmith@mail.com","john_newyork@mail.com"],["John","johnsmith@mail.com","john00@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]'
 *
 * Given a list accounts, each element accounts[i] is a list of strings, where
 * the first element accounts[i][0] is a name, and the rest of the elements are
 * emails representing emails of the account.
 * 
 * Now, we would like to merge these accounts.  Two accounts definitely belong
 * to the same person if there is some email that is common to both accounts.
 * Note that even if two accounts have the same name, they may belong to
 * different people as people could have the same name.  A person can have any
 * number of accounts initially, but all of their accounts definitely have the
 * same name.
 * 
 * After merging the accounts, return the accounts in the following format: the
 * first element of each account is the name, and the rest of the elements are
 * emails in sorted order.  The accounts themselves can be returned in any
 * order.
 * 
 * Example 1:
 * 
 * Input: 
 * accounts = [["John", "johnsmith@mail.com", "john00@mail.com"], ["John",
 * "johnnybravo@mail.com"], ["John", "johnsmith@mail.com",
 * "john_newyork@mail.com"], ["Mary", "mary@mail.com"]]
 * Output: [["John", 'john00@mail.com', 'john_newyork@mail.com',
 * 'johnsmith@mail.com'],  ["John", "johnnybravo@mail.com"], ["Mary",
 * "mary@mail.com"]]
 * Explanation: 
 * The first and third John's are the same person as they have the common email
 * "johnsmith@mail.com".
 * The second John and Mary are different people as none of their email
 * addresses are used by other accounts.
 * We could return these lists in any order, for example the answer [['Mary',
 * 'mary@mail.com'], ['John', 'johnnybravo@mail.com'], 
 * ['John', 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com']]
 * would still be accepted.
 * 
 * 
 * 
 * Note:
 * The length of accounts will be in the range [1, 1000].
 * The length of accounts[i] will be in the range [1, 10].
 * The length of accounts[i][j] will be in the range [1, 30].
 * 
 */

// @lc code=start
class Solution {
public:
    // vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    //     vector<pair<string,int>> name;
    //     map<string, int> m;
    //     for (auto account : accounts)
    //     {
    //         name.push_back(make_pair(account[0], -1));
    //         set<int> roots;
    //         roots.insert(name.size() - 1);
    //         for (int i = 1; i < account.size(); ++i)
    //         {
    //             if (m.count(account[i]))
    //                 roots.insert(m[account[i]]);
    //             else
    //                 m[account[i]] = name.size() - 1;
    //         }
    //         int t = *roots.rbegin();
    //         for (auto it = next(roots.rbegin()); it != roots.rend(); ++it)
    //         {
    //             int parent = *it;
    //             while (name[parent].second != -1 && parent != name[parent].second)
    //             {
    //                 parent = name[parent].second;
    //             }
    //             name[parent].second = t;
    //         }

    //     }
    //     vector<vector<string>> res;
    //     unordered_map<int, vector<string>> group;
    //     for (auto it = m.begin(); it != m.end(); ++it)
    //     {
    //         int inx = it->second;
    //         while (name[inx].second != -1 && inx != name[inx].second)
    //             inx = name[inx].second;

    //         group[inx].push_back(it->first);

    //     }
    //     for (auto it = group.begin(); it != group.end(); ++it)
    //     {
    //         vector<string> acc{ name[it->first].first };
    //         acc.insert(acc.end(), it->second.begin(), it->second.end());
    //         res.push_back(acc);
    //     }
    //     return res;
    // }

    string find(string p)
    {
        if(data.count(p) == 0 || data[p] == p) return p;
        return find(data[p]);
    }
    void merge(string a, string b)
    {
        string pa = find(a);
        string pb = find(b);
        if(pa < pb) data[pb] = pa;
        else data[pa] = pb;
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts)
    {
        unordered_map<string,string> emailToAcc;
        for(auto& acc : accounts)
        {
            for(int i=1; i<acc.size(); ++i)
            {
                merge(acc[1], find(acc[i]));
                emailToAcc[acc[i]] = acc[0];
            }
        }
        unordered_map<string,string> accountName;
        unordered_map<string, set<string>> accountEmails;
        for(auto& acc : accounts)
        {
            for(int i=1; i<acc.size(); ++i)
            {
                string k = find(acc[i]);
                accountName[k] = acc[0];
                accountEmails[k].insert(acc[i]);
            }
        }
        vector<vector<string>> res;
        for(auto& [k, name] : accountName)
        {
            vector<string> tmp;
            tmp.push_back(name);
            tmp.insert(tmp.end(), accountEmails[k].begin(), accountEmails[k].end());
            res.push_back(tmp);
        }
        return res;
    }
private:
    unordered_map<string, string> data;
};
// @lc code=end
// [["Gabe","Gabe0@m.co","Gabe3@m.co","Gabe1@m.co"],["Kevin","Kevin3@m.co","Kevin5@m.co","Kevin0@m.co"],["Ethan","Ethan5@m.co","Ethan4@m.co","Ethan0@m.co"],["Hanzo","Hanzo3@m.co","Hanzo1@m.co","Hanzo0@m.co"],["Fern","Fern5@m.co","Fern1@m.co","Fern0@m.co"]]


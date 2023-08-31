/*
 * @lc app=leetcode id=126 lang=cpp
 *
 * [126] Word Ladder II
 *
 * https://leetcode.com/problems/word-ladder-ii/description/
 *
 * algorithms
 * Hard (22.12%)
 * Likes:    1835
 * Dislikes: 251
 * Total Accepted:    188.8K
 * Total Submissions: 852.7K
 * Testcase Example:  '"hit"\n"cog"\n["hot","dot","dog","lot","log","cog"]'
 *
 * Given two words (beginWord and endWord), and a dictionary's word list, find
 * all shortest transformation sequence(s) from beginWord to endWord, such
 * that:
 * 
 * 
 * Only one letter can be changed at a time
 * Each transformed word must exist in the word list. Note that beginWord is
 * not a transformed word.
 * 
 * 
 * Note:
 * 
 * 
 * Return an empty list if there is no such transformation sequence.
 * All words have the same length.
 * All words contain only lowercase alphabetic characters.
 * You may assume no duplicates in the word list.
 * You may assume beginWord and endWord are non-empty and are not the same.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input:
 * beginWord = "hit",
 * endWord = "cog",
 * wordList = ["hot","dot","dog","lot","log","cog"]
 * 
 * Output:
 * [
 * ⁠ ["hit","hot","dot","dog","cog"],
 * ["hit","hot","lot","log","cog"]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * beginWord = "hit"
 * endWord = "cog"
 * wordList = ["hot","dot","dog","lot","log"]
 * 
 * Output: []
 * 
 * Explanation: The endWord "cog" is not in wordList, therefore no possible
 * transformation.
 * 
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    // static const int max_N =9e3;
    // vector<int> adj[max_N];
    // int dist[max_N];
    // int dest;
    // bool vis[max_N];
    // vector<string> List;
    // int string_diff(const string &a, const string &b)
    // {
    //     int len = a.length();
    //     int diff = 0;
    //     for (int i = 0; i < len; ++i)
    //         diff += (a[i] != b[i]);
    //     return diff;
    // }
    // void generate_adj(const vector<string> &List)
    // {
    //     int N = List.size();
    //     for (int i = 0; i < N; ++i)
    //         for (int j = i + 1; j < N; ++j)
    //         {
    //             int d = string_diff(List[i], List[j]);
    //             if (d != 1)
    //                 continue;
    //             adj[i].push_back(j);
    //             adj[j].push_back(i);
    //         }
    // }
    // void bfs(int src)
    // {
    //     queue<int> que;
    //     memset(dist, 0, sizeof(dist));
    //     memset(vis, 0, sizeof(vis));
    //     vis[src] = true;
    //     que.push(src);
    //     dist[src] = 1;
    //     while (!que.empty())
    //     {
    //         int curr = que.front();
    //         que.pop();
    //         for (int neigh: adj[curr])
    //         {
    //             if(vis[neigh])
    //                 continue;
    //             vis[neigh] = true;
    //             que.push(neigh);
    //             dist[neigh] = dist[curr] + 1;
    //         }
    //     }
    // }
    // void dfs(int curr, vector<string> path, vector<vector<string>> &res)
    // {
    //     if (curr == dest)
    //     {
    //         res.push_back(path);
    //         return ;
    //     }
    //     for (int neigh: adj[curr])
    //     {
    //         if (dist[neigh] != dist[curr] + 1)
    //             continue;
    //         path.push_back(List[neigh]);
    //         dfs(neigh, path, res);
    //         path.pop_back();
    //     }
    // }
    
    // vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    //     List = wordList;
    //     List.push_back(beginWord);
    //     vector<vector<string>> res;
    //     int target = -1;
    //     for (int i = 0; i < List.size(); ++i)
    //     {
    //         if (List[i] == endWord)
    //         {
    //             target = i;
    //             break;
    //         }
    //     }
    //     if (target == -1)
    //         return res;
    //     generate_adj(List);
    //     int N = List.size();
    //     bfs(N-1);
    //     dest = target;
    //     if (dist[target] == 0)
    //         return res;
    //     memset(vis, 0, sizeof(vis));
    //     vector<string> temp;
    //     temp.push_back(beginWord);
    //     dfs(N-1, temp, res);
    //     return res;
    // }

/////////////////////////////////////////



    // static int string_diff(const string &a, const string &b)
    // {
    //     int len = a.length();
    //     int diff = 0;
    //     for (int i = 0; i < len; ++i)
    //         diff += (a[i] != b[i]);
    //     return diff;
    // }
    // struct Node
    // {
    //     Node(string& str){cur = str; parent = nullptr;}
    //     string cur;
    //     Node* parent;
    // };
    // struct Group
    // {
    //     Group(string& str)
    //     {
    //         Node* n = new Node(str);
    //         que.push(n);
    //         inter[str].push_back(n);
    //     }
    //     void step(vector<string>& wordList)
    //     {
    //         inter.clear();
    //         int size = que.size();
    //         while(size--)
    //         {
    //             Node* f = que.front();
    //             que.pop();
    //             unordered_set<string> visited{f->cur};
    //             Node* iter = f;
    //             while(iter->parent)
    //             {
    //                 iter = iter->parent;
    //                 visited.insert(iter->cur); 
    //             }
    //             for(string& w : wordList)
    //             {
    //                 if(string_diff(w, f->cur) == 1 && visited.count(w) == 0)
    //                 {
    //                     // cout << f->cur << "<=" << w << endl;
    //                     Node* next = new Node(w);
    //                     next->parent = f;
    //                     que.push(next);
    //                     inter[w].push_back(next);
    //                 }
    //             }
    //         }
    //         // cout << endl;
    //     }
    //     queue<Node*> que;
    //     unordered_map<string, vector<Node*>> inter;
    // };
    // bool meet(unordered_map<string, vector<Node*>>& a, unordered_map<string, vector<Node*>>& b, vector<vector<string>>& res)
    // {
    //     for(auto& k : a)
    //     {
    //         if(b.count(k.first))
    //         {
    //             for(auto& i : k.second)
    //             {
    //                 for(auto& j : b[k.first])
    //                 {
    //                     vector<string> tmp{k.first};
    //                     Node* n = i;
    //                     while(n->parent)
    //                     {
    //                         n = n->parent;
    //                         tmp.push_back(n->cur);
    //                     }
    //                     reverse(tmp.begin(), tmp.end());

    //                     n = j;
    //                     while(n->parent)
    //                     {
    //                         n = n->parent;
    //                         tmp.push_back(n->cur);
    //                     }
    //                     res.push_back(tmp);
    //                 }
    //             }
    //         }
    //     }
    //     return !res.empty();
    // }
    // vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) 
    // {
    //     unordered_set<string> dic(wordList.begin(), wordList.end());
    //     if(dic.count(endWord) == 0) return {};

    //     Group fw(beginWord), bw(endWord);
    //     int moves= 0;
    //     vector<vector<string>> res;
    //     while(!fw.inter.empty() && !bw.inter.empty() && !meet(fw.inter, bw.inter, res))
    //     {
    //         if(moves++ % 2 ==0)
    //             fw.step(wordList);
    //         else
    //             bw.step(wordList);
    //     }
    //     return res;
    // }
///////////////////////////////////////////////////////////////////////
/*
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> res;
        unordered_set<string> dict(wordList.begin(), wordList.end());
        vector<string> p{beginWord};
        queue<vector<string>> paths;
        paths.push(p);
        int level = 1, minLevel = INT_MAX;
        unordered_set<string> words;
        while (!paths.empty()) {
            auto t = paths.front(); paths.pop();
            if (t.size() > level) {
                for (string w : words) dict.erase(w);
                words.clear();
                level = t.size();
                if (level > minLevel) break;
            }
            string last = t.back();
            for (int i = 0; i < last.size(); ++i) {
                string newLast = last;
                for (char ch = 'a'; ch <= 'z'; ++ch) {
                    newLast[i] = ch;
                    if (!dict.count(newLast)) continue;
                    words.insert(newLast);
                    vector<string> nextPath = t;
                    nextPath.push_back(newLast);
                    if (newLast == endWord) {
                        res.push_back(nextPath);
                        minLevel = level;
                    } else paths.push(nextPath);
                }
            }
        }
        return res;
    }

*/
    bool step(unordered_multimap<string, vector<string>>& fw, unordered_multimap<string, vector<string>>& bw, unordered_set<string>& dict, vector<vector<string>>& res)
    {
        unordered_multimap<string, vector<string>> nextlevel;
        for(auto it=fw.begin(); it!=fw.end(); ++it)
        {
            // cout << it->first<< endl;
            if(bw.count(it->first))
            {
                auto found = bw.equal_range(it->first);
                for(auto jt = found.first; jt!=found.second; ++jt)
                {
                    res.push_back(it->second);
                    res.back().pop_back();
                    res.back().insert(res.back().end(), jt->second.rbegin(), jt->second.rend());
                }
                
            }
            for(int i=0; i<it->first.size(); ++i)
            {
                string str = it->first;
                for(char c='a'; c<='z'; ++c)
                {
                    str[i] = c;
                    if(str == it->first || dict.count(str) == 0) continue;
                    
                    vector<string> path = it->second;
                    if(path.size()>1 && path[path.size()-2] == str) continue;
                    path.push_back(str);
                    nextlevel.insert({str, path});
                    // cout << str<< endl;
                }
            }
        }
        swap(fw, nextlevel);
        // cout << endl;
        return !res.empty() || fw.empty() || bw.empty();
    }
    struct Node
    {
        Node(string s){word=s;parent=nullptr;}
        string word;
        Node* parent;
    };
    bool step(unordered_multimap<string, Node*>& fw, unordered_multimap<string, Node*>& bw, unordered_set<string>& dict, vector<vector<string>>& res)
    {
        unordered_multimap<string, Node*> nextlevel;
        for(auto it=fw.begin(); it!=fw.end(); ++it)
        {
            // cout << it->first<< endl;
            if(bw.count(it->first))
            {
                auto found = bw.equal_range(it->first);
                for(auto jt = found.first; jt!=found.second; ++jt)
                {
                    Node* n = it->second;
                    vector<string> strs;
                    while(n!=nullptr)
                    {
                        // cout << n->word << "->";
                        strs.push_back(n->word);
                        n=n->parent;
                    }
                    // cout << endl << "bw: " << endl;
                    reverse(strs.begin(), strs.end());
                    strs.pop_back();
                    n=jt->second;
                    while(n!=nullptr)
                    {
                        // cout << n->word << " ";
                        strs.push_back(n->word);
                        n=n->parent;
                    }
                    // for(string t : strs)cout<<t<<" "; cout<<endl;
                    res.push_back(strs);
                }
            }

            for(int i=0; i<it->first.size(); ++i)
            {
                string str = it->first;
                for(char c='a'; c<='z'; ++c)
                {
                    str[i] = c;
                    if(str == it->first || dict.count(str) == 0) continue;
                    
                    Node* n = it->second;
                    if(n->parent && n->parent->word == str) continue;
                    Node* next = new Node(str); next->parent = n;
                    nextlevel.insert({str, next});
                    // cout << str<< endl;
                }
            }
        }
        swap(fw, nextlevel);
        // cout << endl;
        return !res.empty() || fw.empty() || bw.empty();
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList)
    {
        vector<vector<string>> res;
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if(dict.count(endWord) == 0) return {};
        unordered_multimap<string, Node*> fw{{beginWord, new Node(beginWord)}}, bw{{endWord, new Node(endWord)}};
        int moves = 0;
        while(moves%2==0 ? !step(fw, bw, dict, res) : !step(bw, fw, dict, res))
            moves++;
        if(moves%2==1)
            for_each(res.begin(), res.end(), [](vector<string>& i){reverse(i.begin(),i.end());});

        return res;
    }

};
// @lc code=end

// "hot"\n"dog"\n["hot","dog"]

// "red"\n"tax"\n["ted","tex","red","tax","tad","den","rex","pee"]

// "cet"\n"ism"\n["kid","tag","pup","ail","tun","woo","erg","luz","brr","gay","sip","kay","per","val","mes","ohs","now","boa","cet","pal","bar","die","war","hay","eco","pub","lob","rue","fry","lit","rex","jan","cot","bid","ali","pay","col","gum","ger","row","won","dan","rum","fad","tut","sag","yip","sui","ark","has","zip","fez","own","ump","dis","ads","max","jaw","out","btu","ana","gap","cry","led","abe","box","ore","pig","fie","toy","fat","cal","lie","noh","sew","ono","tam","flu","mgm","ply","awe","pry","tit","tie","yet","too","tax","jim","san","pan","map","ski","ova","wed","non","wac","nut","why","bye","lye","oct","old","fin","feb","chi","sap","owl","log","tod","dot","bow","fob","for","joe","ivy","fan","age","fax","hip","jib","mel","hus","sob","ifs","tab","ara","dab","jag","jar","arm","lot","tom","sax","tex","yum","pei","wen","wry","ire","irk","far","mew","wit","doe","gas","rte","ian","pot","ask","wag","hag","amy","nag","ron","soy","gin","don","tug","fay","vic","boo","nam","ave","buy","sop","but","orb","fen","paw","his","sub","bob","yea","oft","inn","rod","yam","pew","web","hod","hun","gyp","wei","wis","rob","gad","pie","mon","dog","bib","rub","ere","dig","era","cat","fox","bee","mod","day","apr","vie","nev","jam","pam","new","aye","ani","and","ibm","yap","can","pyx","tar","kin","fog","hum","pip","cup","dye","lyx","jog","nun","par","wan","fey","bus","oak","bad","ats","set","qom","vat","eat","pus","rev","axe","ion","six","ila","lao","mom","mas","pro","few","opt","poe","art","ash","oar","cap","lop","may","shy","rid","bat","sum","rim","fee","bmw","sky","maj","hue","thy","ava","rap","den","fla","auk","cox","ibo","hey","saw","vim","sec","ltd","you","its","tat","dew","eva","tog","ram","let","see","zit","maw","nix","ate","gig","rep","owe","ind","hog","eve","sam","zoo","any","dow","cod","bed","vet","ham","sis","hex","via","fir","nod","mao","aug","mum","hoe","bah","hal","keg","hew","zed","tow","gog","ass","dem","who","bet","gos","son","ear","spy","kit","boy","due","sen","oaf","mix","hep","fur","ada","bin","nil","mia","ewe","hit","fix","sad","rib","eye","hop","haw","wax","mid","tad","ken","wad","rye","pap","bog","gut","ito","woe","our","ado","sin","mad","ray","hon","roy","dip","hen","iva","lug","asp","hui","yak","bay","poi","yep","bun","try","lad","elm","nat","wyo","gym","dug","toe","dee","wig","sly","rip","geo","cog","pas","zen","odd","nan","lay","pod","fit","hem","joy","bum","rio","yon","dec","leg","put","sue","dim","pet","yaw","nub","bit","bur","sid","sun","oil","red","doc","moe","caw","eel","dix","cub","end","gem","off","yew","hug","pop","tub","sgt","lid","pun","ton","sol","din","yup","jab","pea","bug","gag","mil","jig","hub","low","did","tin","get","gte","sox","lei","mig","fig","lon","use","ban","flo","nov","jut","bag","mir","sty","lap","two","ins","con","ant","net","tux","ode","stu","mug","cad","nap","gun","fop","tot","sow","sal","sic","ted","wot","del","imp","cob","way","ann","tan","mci","job","wet","ism","err","him","all","pad","hah","hie","aim","ike","jed","ego","mac","baa","min","com","ill","was","cab","ago","ina","big","ilk","gal","tap","duh","ola","ran","lab","top","gob","hot","ora","tia","kip","han","met","hut","she","sac","fed","goo","tee","ell","not","act","gil","rut","ala","ape","rig","cid","god","duo","lin","aid","gel","awl","lag","elf","liz","ref","aha","fib","oho","tho","her","nor","ace","adz","fun","ned","coo","win","tao","coy","van","man","pit","guy","foe","hid","mai","sup","jay","hob","mow","jot","are","pol","arc","lax","aft","alb","len","air","pug","pox","vow","got","meg","zoe","amp","ale","bud","gee","pin","dun","pat","ten","mob"]
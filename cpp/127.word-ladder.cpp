/*
 * @lc app=leetcode id=127 lang=cpp
 *
 * [127] Word Ladder
 *
 * https://leetcode.com/problems/word-ladder/description/
 *
 * algorithms
 * Medium (29.52%)
 * Likes:    3322
 * Dislikes: 1196
 * Total Accepted:    441K
 * Total Submissions: 1.5M
 * Testcase Example:  '"hit"\n"cog"\n["hot","dot","dog","lot","log","cog"]'
 *
 * Given two words (beginWord and endWord), and a dictionary's word list, find
 * the length of shortest transformation sequence from beginWord to endWord,
 * such that:
 * 
 * 
 * Only one letter can be changed at a time.
 * Each transformed word must exist in the word list.
 * 
 * 
 * Note:
 * 
 * 
 * Return 0 if there is no such transformation sequence.
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
 * Output: 5
 * 
 * Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" ->
 * "dog" -> "cog",
 * return its length 5.
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
 * Output: 0
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

	// bool step(unordered_set<string> in, unordered_set<string>& out, unordered_set<string>& dict, unordered_set<string>& target)
	// {
	// 	out.clear();
	// 	for(auto i : in)
	// 	{
	// 		for(int j=0; j<i.size(); ++j)
	// 		{
	// 			for(char c='a'; c<='z'; ++c)
	// 			{
	// 				if (i[j] == c) continue;
	// 				string str = i;
	// 				str[j] = c;
	// 				if(dict.count(str))
	// 				{
	// 					if (target.count(str))
	// 						return true;
	// 					out.insert(str);
	// 				}
	// 			}
	// 		}
	// 		dict.erase(i);
			
	// 	}
	// 	return false;
	// }

	// int ladderLength(string beginWord, string endWord, vector<string>& wordList)
	// {
	// 	unordered_set<string> dict;
	// 	dict.insert(wordList.begin(), wordList.end());
	// 	if (!dict.count(endWord)) return false;
	// 	unordered_set<string> left;
	// 	unordered_set<string> right;

	// 	left.insert(beginWord);
	// 	right.insert(endWord);

	// 	int res = 1;
	// 	bool meet = false;
	// 	while(!meet)
	// 	{
	// 		if (res % 2)
	// 			meet |= step(left, left, dict, right);
	// 		else
	// 			meet |= step(right, right, dict, left);
			
	// 		if (!meet && (left.empty() || right.empty()))
	// 			return 0;
	// 		res++;
	// 	}
	// 	return res;
	// }

	int ladderLength(string beginWord, string endWord, vector<string>& wordList)
	{
		if(beginWord == endWord) return true;
		unordered_set<string> list(wordList.begin(), wordList.end());
		if(list.count(endWord) == 0) return 0;
		unordered_set<string> visited{beginWord};
		queue<string> q;
		q.push(beginWord);
		int step = 1;
		while(!q.empty())
		{
			int size = q.size();
			while(size--)
			{
				string& f = q.front();
				if(f == endWord) return step;
				for(int i=0; i<f.size(); ++i)
				{
					for(char c='a'; c<='z'; ++c)
					{
						string str = f;
						str[i] = c;
						if(str == f || list.count(str) == 0 || visited.count(str)) continue;
						visited.insert(str);
						q.push(str);
					}
				}
				q.pop();
			}
			step++;

		}
		return 0;
	}
};
// @lc code=end


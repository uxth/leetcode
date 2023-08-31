/*
 * @lc app=leetcode id=528 lang=cpp
 *
 * [528] Random Pick with Weight
 *
 * https://leetcode.com/problems/random-pick-with-weight/description/
 *
 * algorithms
 * Medium (43.94%)
 * Likes:    817
 * Dislikes: 2299
 * Total Accepted:    113.1K
 * Total Submissions: 257.5K
 * Testcase Example:  '["Solution","pickIndex"]\r\n[[[1]],[]]\r'
 *
 * Given an array w of positive integers, where w[i] describes the weight of
 * index i(0-indexed), write a function pickIndex which randomly picks an index
 * in proportion to its weight.
 * 
 * For example, given an input list of values w = [2, 8], when we pick up a
 * number out of it, the chance is that 8 times out of 10 we should pick the
 * number 1 as the answer since it's the second element of the array (w[1] =
 * 8).
 * 
 * 
 * Example 1:
 * 
 * 
 * Input
 * ["Solution","pickIndex"]
 * [[[1]],[]]
 * Output
 * [null,0]
 * 
 * Explanation
 * Solution solution = new Solution([1]);
 * solution.pickIndex(); // return 0. Since there is only one single element on
 * the array the only option is to return the first element.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input
 * ["Solution","pickIndex","pickIndex","pickIndex","pickIndex","pickIndex"]
 * [[[1,3]],[],[],[],[],[]]
 * Output
 * [null,1,1,1,1,0]
 * 
 * Explanation
 * Solution solution = new Solution([1, 3]);
 * solution.pickIndex(); // return 1. It's returning the second element (index
 * = 1) that has probability of 3/4.
 * solution.pickIndex(); // return 1
 * solution.pickIndex(); // return 1
 * solution.pickIndex(); // return 1
 * solution.pickIndex(); // return 0. It's returning the first element (index =
 * 0) that has probability of 1/4.
 * 
 * Since this is a randomization problem, multiple answers are allowed so the
 * following outputs can be considered correct :
 * [null,1,1,1,1,0]
 * [null,1,1,1,1,1]
 * [null,1,1,1,0,0]
 * [null,1,1,1,0,1]
 * [null,1,0,1,0,0]
 * ......
 * and so on.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= w.length <= 10000
 * 1 <= w[i] <= 10^5
 * pickIndex will be called at most 10000 times.
 * 
 * 
 */

// @lc code=start
class Solution {
private:
    vector<int> low, high;
    int sum;
    int search(int target)
    {
        int left = 0; 
        int right = low.size() - 1;
        while(left < right)
        {
            int mid = left + (right - left) / 2;
            if(low[mid] <= target && target < high[mid]) return mid;
            else if(target >= high[mid]) left = mid + 1;
            else right = mid;
        }
        return left;
    }
public:
    Solution(vector<int>& w) {
        
        low.assign(w.size(), 0);
        high.assign(w.size(), 0);
        high[0] = w[0];
        for(int i=1; i<w.size(); ++i)
        {
            low[i] = high[i-1];
            high[i] = low[i] + w[i];
        }

        sum = accumulate(w.begin(), w.end(), 0);
    }
    
    int pickIndex() {
        // for_each(low.begin(), low.end(), [](int i){cout << i;}), cout << endl;
        // for_each(high.begin(), high.end(), [](int i){cout << i;}), cout << endl;
        int target = rand() % sum;
        int idx = search(target);
        return idx;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
// @lc code=end
// ["Solution","pickIndex","pickIndex","pickIndex","pickIndex","pickIndex"]\n[[[1,3]],[],[],[],[],[]]

/*
 * @lc app=leetcode id=1986 lang=cpp
 *
 * [1986] Minimum Number of Work Sessions to Finish the Tasks
 */

// @lc code=start
class Solution{
public:
    bool check(vector<int> &tasks, vector<int> &vec, int step, int sessionTime){
        if (step >= tasks.size())
            return true;
        int cur = tasks[step];
        for (int i = 0; i < vec.size(); i++){
            if (vec[i] + cur <= sessionTime){
                vec[i] += cur;
                if (check(tasks, vec, step + 1, sessionTime))
                    return true;
                vec[i] -= cur;
            }
            if (vec[i] == 0)
                break;
        }
        return false;
    }
    int bs(vector<int>& tasks, int sessionTime){
        int l = 1, r = tasks.size();
        while (l < r){
            int mid = (l + r) / 2;
            vector<int> vec(mid, 0);
            if (check(tasks, vec, 0, sessionTime))
                r = mid;
            else
                l = mid + 1;
        }
        return l;

    }
    bool dfs(const vector<int>& tasks, int sessions, int sessionTime, int pos, vector<int> &free_time) {
        if (pos == tasks.size())    return true;
        int t = tasks[pos];
        unordered_set<int> appeared_free_time;

        for (int i=0; i<sessions; ++i) {
            if (free_time[i] < t)    continue;
            if (appeared_free_time.contains(free_time[i])) continue;
            appeared_free_time.insert(free_time[i]);
            free_time[i] -= t;
            if(dfs(tasks, sessions, sessionTime, pos+1, free_time)) return true;
            free_time[i] += t;
        }
        return false;
    }
    bool is_feasible(const vector<int>& tasks, int sessions, int sessionTime) {
        vector<int> free_time(sessions, sessionTime);
        return dfs(tasks, sessions, sessionTime, 0, free_time);
    }
    int dfs(vector<int>& tasks, int sessionTime){
        sort(tasks.begin(), tasks.end(), std::greater<int>());
        int total_work_time = accumulate(begin(tasks), end(tasks), 0);

        int begin = total_work_time / sessionTime;
        if (begin == 0) begin = 1;
        int end = tasks.size();
        int len = end - begin + 1;

        // try to find the first valid answer in range [begin, begin+len)
        
        while (len > 0) {
            int l2 = len / 2; // 0 <= l2 < len
            int mid = begin + l2;

            if (is_feasible(tasks, mid, sessionTime)) {
                len = l2;
            } else {
                // keep [mid..]
                int new_first = mid + 1;
                len = begin + len - new_first;
                begin = new_first;
            }
        }
        return begin;
    }
    int minSessions(vector<int> &tasks, int sessionTime){
        // return bs(tasks, sessionTime);
        return dfs(tasks, sessionTime);
    }
};
// @lc code=end
/*
[3,1,3,1,1]\n8
[1,2,3,4,5]\n15
[2,3,3,4,4,4,5,6,7,10]\n12
*/

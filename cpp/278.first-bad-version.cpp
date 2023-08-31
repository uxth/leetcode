/*
 * @lc app=leetcode id=278 lang=cpp
 *
 * [278] First Bad Version
 *
 * https://leetcode.com/problems/first-bad-version/description/
 *
 * algorithms
 * Easy (36.99%)
 * Likes:    1982
 * Dislikes: 802
 * Total Accepted:    531K
 * Total Submissions: 1.4M
 * Testcase Example:  '5\n4'
 *
 * You are a product manager and currently leading a team to develop a new
 * product. Unfortunately, the latest version of your product fails the quality
 * check. Since each version is developed based on the previous version, all
 * the versions after a bad version are also bad.
 * 
 * Suppose you have n versions [1, 2, ..., n] and you want to find out the
 * first bad one, which causes all the following ones to be bad.
 * 
 * You are given an API bool isBadVersion(version) which returns whether
 * version is bad. Implement a function to find the first bad version. You
 * should minimize the number of calls to the API.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 5, bad = 4
 * Output: 4
 * Explanation:
 * call isBadVersion(3) -> false
 * call isBadVersion(5) -> true
 * call isBadVersion(4) -> true
 * Then 4 is the first bad version.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 1, bad = 1
 * Output: 1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= bad <= n <= 2^31 - 1
 * 
 * 
 */

// @lc code=start
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
       long long l=1,r=n;
        while(l!=r){//we stop when l is equal to r since we finally find the place where good versions end and it meet bad version since we assume that r is always at bad version and before l==r, l is always at good version
            long long mid=(l+r)/2;
            if(isBadVersion(mid)){
                r=mid;//if the current version is bad then it's not nexessary that previous version will be bad too
            }else{
                l=mid+1;//since if the current version is good then bad must be to the right of this good version
            }
        }
        return l;
    }
};
// @lc code=end


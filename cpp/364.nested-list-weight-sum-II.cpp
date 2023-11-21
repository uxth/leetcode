/*

Question
Formatted question description: https://leetcode.ca/all/364.html

You are given a nested list of integers nestedList. Each element is either an integer or a list whose elements may also be integers or other lists.

The depth of an integer is the number of lists that it is inside of. For example, the nested list [1,[2,2],[[3],2],1] has each integer's value set to its depth. Let maxDepth be the maximum depth of any integer.

The weight of an integer is maxDepth - (the depth of the integer) + 1.

Return the sum of each integer in nestedList multiplied by its weight.

 

Example 1:



Input: nestedList = [[1,1],2,[1,1]]
Output: 8
Explanation: Four 1's with a weight of 1, one 2 with a weight of 2.
1*1 + 1*1 + 2*2 + 1*1 + 1*1 = 8
Example 2:



Input: nestedList = [1,[4,[6]]]
Output: 17
Explanation: One 1 at depth 3, one 4 at depth 2, and one 6 at depth 1.
1*3 + 4*2 + 6*1 = 17
 

Constraints:

1 <= nestedList.length <= 50
The values of the integers in the nested list is in the range [-100, 100].
The maximum depth of any integer is less than or equal to 50.
Algorithm
This question is an extension of the previous Nested List Weight Sum. The difference is that the deeper the depth, the smaller the weight, which is just the opposite of the previous one.

But the idea of solving the problem has not changed, you can still use DFS to do it, because you don’t know how deep the final depth is when traversing, you can directly accumulate the results when you can’t traverse.

The initial idea was to create a two-dimensional array during the traversal process, save the numbers of each layer, and finally know the depth, then calculate the weight sum.

But, to do it better, we can use two variables unweighted and weighted are used, the non-weighted sum and the weighted sum, which are initialized to 0.

If nestedList is not empty to start the loop, declare an empty array nextLevel first, traverse the elements in nestedList,
If it is a number, then the non-weight sum plus this number,
If it is an array, add nextLevel, After the traversal is completed, the number sum of the first level is stored in unweighted, and the rest of the elements are stored in nextLevel.
At this time, unweighted is added to weighted, and nextLevel is assigned to nestedList, so that it enters the next layer of calculation.

Since the value of the previous layer is still in unweighted, when the second layer is calculated and unweighted is added to weighted, it is equivalent to the sum of the numbers of the first layer being added twice, which perfectly meets the requirements.

*/

// OJ: https://leetcode.com/problems/nested-list-weight-sum-ii/
// Time: O(N)
// Space: O(N)
class Solution {
private:
    int getDepth(vector<NestedInteger>& nestedList) {
        int ans = 0;
        for (auto &item : nestedList) ans = max(ans, item.isInteger() ? 0 : getDepth(item.getList()));
        return 1 + ans;
    }
    int getSum(vector<NestedInteger>& nestedList, int weight) {
        int sum = 0;
        for (auto &item : nestedList) sum += item.isInteger() ? (item.getInteger() * weight) : getSum(item.getList(), weight - 1);
        return sum;
    }
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        int depth = getDepth(nestedList);
        return getSum(nestedList, depth);
    }
};
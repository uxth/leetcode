/*
Question
Formatted question description: https://leetcode.ca/all/251.html

Design an iterator to flatten a 2D vector. It should support the next and hasNext operations.

Implement the Vector2D class:

Vector2D(int[][] vec) initializes the object with the 2D vector vec.
next() returns the next element from the 2D vector and moves the pointer one step forward. You may assume that all the calls to next are valid.
hasNext() returns true if there are still some elements in the vector, and false otherwise.
 

Example 1:

Input
["Vector2D", "next", "next", "next", "hasNext", "hasNext", "next", "hasNext"]
[[[[1, 2], [3], [4]]], [], [], [], [], [], [], []]
Output
[null, 1, 2, 3, true, true, 4, false]

Explanation
Vector2D vector2D = new Vector2D([[1, 2], [3], [4]]);
vector2D.next();    // return 1
vector2D.next();    // return 2
vector2D.next();    // return 3
vector2D.hasNext(); // return True
vector2D.hasNext(); // return True
vector2D.next();    // return 4
vector2D.hasNext(); // return False
 

Constraints:

0 <= vec.length <= 200
0 <= vec[i].length <= 500
-500 <= vec[i][j] <= 500
At most 105 calls will be made to next and hasNext.
 

Follow up: As an added challenge, try to code it using only iterators in C++ or iterators in Java.

Algorithm
Maintain two variables x and y, and initialize x and y to 0.

For the hasNext() function, check whether the current x is less than the total number of rows, and whether y is the same as the number of columns in the current row,

If the same, it means that you want to go to the next line, then x increments by 1, y is initialized to 0
If x is still less than the total number of rows at this time, indicating that the next value can be taken out, then in the next function, you can directly take out the row x, list the number as y, and increment y by 1
Note: special case for empty list
    [
    [1,2],
    [3],
    [4,5,6],
    [],
    [],
    []
    ]
    
*/

// OJ: https://leetcode.com/problems/flatten-2d-vector/
// Time:
//      Vector2D: O(N)
//      next: O(1) amortized
//      hasNext: O(1)
// Space: O(1)
class Vector2D {
    vector<vector<int>> v;
    int i = 0, j = 0;
    void move() {
        while (i < v.size() && j == v[i].size()) {
            ++i;
            j = 0;
        }
    }
public:
    Vector2D(vector<vector<int>>& v) : v(v) {
        move();
    }
    int next() {
        int ans = v[i][j++];
        move();
        return ans;
    }
    bool hasNext() {
        return i < v.size();
    }
};
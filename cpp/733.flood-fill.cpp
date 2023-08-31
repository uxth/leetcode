/*
 * @lc app=leetcode id=733 lang=cpp
 *
 * [733] Flood Fill
 *
 * https://leetcode.com/problems/flood-fill/description/
 *
 * algorithms
 * Easy (55.26%)
 * Likes:    1307
 * Dislikes: 195
 * Total Accepted:    175K
 * Total Submissions: 316.6K
 * Testcase Example:  '[[1,1,1],[1,1,0],[1,0,1]]\n1\n1\n2'
 *
 * 
 * An image is represented by a 2-D array of integers, each integer
 * representing the pixel value of the image (from 0 to 65535).
 * 
 * Given a coordinate (sr, sc) representing the starting pixel (row and column)
 * of the flood fill, and a pixel value newColor, "flood fill" the image.
 * 
 * To perform a "flood fill", consider the starting pixel, plus any pixels
 * connected 4-directionally to the starting pixel of the same color as the
 * starting pixel, plus any pixels connected 4-directionally to those pixels
 * (also with the same color as the starting pixel), and so on.  Replace the
 * color of all of the aforementioned pixels with the newColor.
 * 
 * At the end, return the modified image.
 * 
 * Example 1:
 * 
 * Input: 
 * image = [[1,1,1],[1,1,0],[1,0,1]]
 * sr = 1, sc = 1, newColor = 2
 * Output: [[2,2,2],[2,2,0],[2,0,1]]
 * Explanation: 
 * From the center of the image (with position (sr, sc) = (1, 1)), all pixels
 * connected 
 * by a path of the same color as the starting pixel are colored with the new
 * color.
 * Note the bottom corner is not colored 2, because it is not 4-directionally
 * connected
 * to the starting pixel.
 * 
 * 
 * 
 * Note:
 * The length of image and image[0] will be in the range [1, 50].
 * The given starting pixel will satisfy 0  and 0 .
 * The value of each color in image[i][j] and newColor will be an integer in
 * [0, 65535].
 * 
 */

// @lc code=start
class Solution {
public:
    vector<pair<int,int>> dir{{-1,0},{1,0},{0,-1},{0,1}};
    void dfs(vector<vector<int>>& image, int y, int x, int oldColor, int newColor)
    {
        int m = image.size(); int n = image[0].size();
        if(y<0||x<0||y>=m||x>=n) return;
        if(image[y][x] != oldColor) return;
        image[y][x] = newColor;
        for(auto& d : dir)
        {
            dfs(image, y+d.first, x+d.second, oldColor, newColor);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image[sr][sc] == newColor) return image;
        bfs(image, sr, sc, image[sr][sc], newColor);
        return image;
    }

    void bfs(vector<vector<int>>& image, int y, int x, int oldColor, int newColor)
    {
        int m = image.size(); int n = image[0].size();
        queue<pair<int,int>> q;
        q.push({y,x});
        while(!q.empty())
        {
            auto& f = q.front();
            int i = f.first; int j = f.second;
            q.pop();
            image[i][j] = newColor;
            for(auto& d : dir)
            {
                int yy = i + d.first;
                int xx = j + d.second;
                if(yy<0||xx<0||yy>=m||xx>=n) continue;
                if(image[yy][xx] != oldColor) continue;
                q.push({yy, xx});
            }
            
        }
    }
};
// @lc code=end


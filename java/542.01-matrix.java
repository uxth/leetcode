/*
 * @lc app=leetcode id=542 lang=java
 *
 * [542] 01 Matrix
 */

// @lc code=start
class Solution {
    int m,n;
    boolean vis[][];
    public void minDist(int mat[][],int i,int j,int step){
        if(i<0||j<0||i>=m||j>=n||(step!=0&&mat[i][j]==0))return;
        //If index out of bounds or mat[i][j]==0 (Which means minimum distance is 0) or step==0
        if(vis[i][j]&&mat[i][j]<=step)return;
        //if already visited and mat[i][j] val is less than step count then simply return

        //Or else update the mat and visited matrix's
        mat[i][j]=step;
        vis[i][j]=true;
        //recursively call function in all four directions
        minDist(mat,i+1,j,step+1);
        minDist(mat,i-1,j,step+1);
        minDist(mat,i,j+1,step+1);
        minDist(mat,i,j-1,step+1);

    }
    
    public int[][] updateMatrix(int[][] mat) {
        m=mat.length;
        n=mat[0].length;
        vis=new boolean[m][n];

        for(int i=0;i<m;i++){
            
            for(int j=0;j<n;j++){

                if(mat[i][j]==0){
                    minDist(mat,i,j,0);
                }
            }
        }
        return mat;
    }
}
// @lc code=end


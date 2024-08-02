class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>grid(m,vector<int>(n));
        for(int i=0;i<m;i++){
            grid[i][0]=1;   
            //Only 1 possible way is by moving down from upper cell
        }

        for(int j=0;j<n;j++){
            grid[0][j]=1;
            //Only 1 possible way is by moving right from the left cell
        }

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                grid[i][j]=grid[i-1][j]+grid[i][j-1];
            }
        }
        return grid[m-1][n-1];
    }
};
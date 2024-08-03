class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>answer(m,vector<int>(n));

        answer[0][0]=grid[0][0];
        for(int i=1;i<m;i++){
            //Minimum sum till answer[i][0] cell
            answer[i][0]=answer[i-1][0]+grid[i][0];
            //coz only 1 direction is valid i.e. down
        }

        for(int j=1;j<n;j++){
            //Minimum sum till answer[0][j] cell
            answer[0][j]=answer[0][j-1]+grid[0][j];
            //coz only 1 direction is valid i.e. right
        }

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                //Check where minimum cell is obtained, for upper cell
                //or for left cell
                answer[i][j]=min(answer[i][j-1],answer[i-1][j])+grid[i][j];
            }
        }
        return answer[m-1][n-1];
    }
};
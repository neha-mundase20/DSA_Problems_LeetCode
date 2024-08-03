class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        vector<vector<int>>answer(m,vector<int>(m));

        answer[0][0]=triangle[0][0];

        //Initializing outer left side of triangle
        for(int i=1;i<m;i++){
            answer[i][0]=answer[i-1][0]+triangle[i][0];
        }

        //Initializing outer right side of triangle
        for(int j=1;j<m;j++){
            answer[j][j]=answer[j-1][j-1]+triangle[j][j];
        }

        //Initializing central part of the triangle
        for(int i=2;i<m;i++){
            for(int j=1;j<i;j++){
                answer[i][j]=min(answer[i-1][j-1],answer[i-1][j])+triangle[i][j];
            }
        }

        //Check in last row where minimum path sum is obtained
        int minPathSum=answer[m-1][0];
        for(int j=1;j<m;j++){
            minPathSum=min(minPathSum,answer[m-1][j]);
        }

        return minPathSum;
    }
};
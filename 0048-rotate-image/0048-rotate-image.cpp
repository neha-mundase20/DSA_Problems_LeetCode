class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        //Draw example matrices and observe the relation
        
        int n=matrix.size();
        vector<vector<int>>temp(n,vector<int>(n));
        
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                temp[i][j]=matrix[i][j];
            }
        }
        
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                    matrix[j][n-1-i]=temp[i][j];
            }
        }
    }
};
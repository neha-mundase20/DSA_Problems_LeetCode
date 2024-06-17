class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        map<pair<int,int>,int>mp;
        int m=matrix.size(),n=matrix[0].size();
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                mp[{i,j}]=matrix[i][j];
            }
        }
        
        for(auto it:mp){
            if(it.second==0){
                for(int j=0;j<n;j++){
                    matrix[it.first.first][j]=0;
                }
                for(int i=0;i<m;i++){
                    matrix[i][it.first.second]=0;
                }
            }
        }
    }
};
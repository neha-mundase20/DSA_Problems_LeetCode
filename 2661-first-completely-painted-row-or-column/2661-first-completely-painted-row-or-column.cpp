class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        map<int,pair<int,int>>mp;

        int m=mat.size();
        int n=mat[0].size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                mp[mat[i][j]]={i,j};
            }
        }

        vector<int>rows(m,0);
        vector<int>columns(n,0);

        for(int i=0;i<arr.size();i++){
            auto temp=mp[arr[i]];
            rows[temp.first]++;
            columns[temp.second]++;

            if(rows[temp.first]==n || columns[temp.second]==m){
                return i;
            }
        }
        return -1;
    }
};
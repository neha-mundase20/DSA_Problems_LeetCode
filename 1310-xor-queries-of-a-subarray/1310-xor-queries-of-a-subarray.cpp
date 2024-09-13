class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int m=queries.size();
        vector<int>solution(m,0);

        for(int i=0;i<m;i++){
            int value=0;
            for(int j=queries[i][0];j<=queries[i][1];j++){
                value=value^arr[j];
            }
            solution[i]=value;
        }
        return solution;
    }
};
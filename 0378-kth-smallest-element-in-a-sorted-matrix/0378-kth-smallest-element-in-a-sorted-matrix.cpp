class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        multiset<int>solution;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                solution.insert(matrix[i][j]);
            }
        }
        auto it=solution.begin();
        advance(it,k-1);
        return *it;
    }
};
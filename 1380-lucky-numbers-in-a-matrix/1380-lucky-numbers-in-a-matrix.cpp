class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        vector<int>minValueIndices(m);
        vector<int>luckyNumber;

        for(int i=0;i<m;i++){   //Storing col Index for each minValue row Index
            int currentRowMin=matrix[i][0];
            int minj=0;
            for(int j=0;j<n;j++){
                if(matrix[i][j]<=currentRowMin){
                    currentRowMin=matrix[i][j];
                    minj=j;
                }
            }
            minValueIndices[i]=minj;
        }   

        for(int i=0;i<m;i++){
            int colIndex=minValueIndices[i];
            int candidate=matrix[i][colIndex];
            bool isLucky=true;

            for(int i=0;i<m;i++){
                //Checking if the current candidate is max in said column
                if(candidate<matrix[i][colIndex]){
                    isLucky=false;
                    break;
                }
            }

            if(isLucky==true){
                luckyNumber.push_back(candidate);
                break;
            } 
        }
        return luckyNumber;
    }
};
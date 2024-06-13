class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>solution;
        
        for(int i=1;i<=numRows;i++){
            if(i==1){
                solution.push_back({1});
            }
            else if(i==2){
                solution.push_back({1,1});
            }
            else{
                vector<int>temp;
                temp.push_back(1);
                for(int j=0;j<i-2;j++){
                    temp.push_back(solution[i-2][j]+solution[i-2][j+1]);
                }
                temp.push_back(1);
                
                solution.push_back(temp);
            }
        }
        return solution;
    }
};
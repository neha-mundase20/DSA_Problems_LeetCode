class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> solution;
        
        for (int i = 0; i <= rowIndex; i++) {
            vector<int> temp(i + 1, 1); // Initialize temp vector with size i+1 and all                                             elements as 1
            
            if (i == 0) {
                solution = {1}; // Special case for rowIndex = 0
            } 
            else if (i == 1) {
                solution = {1, 1}; // Special case for rowIndex = 1
            }
            else {
                for (int j = 1; j < i; ++j) {
                    temp[j] = solution[j - 1] + solution[j]; // Calculate each element based                                                                on the previous row
                }
                solution = temp; // Update solution to current row
            }
        }
        
        return solution;
    }
};
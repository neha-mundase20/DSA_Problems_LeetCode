class Solution {
public:
    bool areNumbersAscending(string s) {
        istringstream S(s);
        string token;
        vector<int>solution;
        
        while(S>>token){    //convert string to tokens separated by space
            if(isdigit(token[0])){  //checking if token[0] is a digit
                solution.push_back(stoi(token));
            }
        }
        
        for(size_t i=0;i<solution.size()-1;i++){
            if(solution[i]>=solution[i+1]){
                return false;
            }
        }
        return true;
    }
};
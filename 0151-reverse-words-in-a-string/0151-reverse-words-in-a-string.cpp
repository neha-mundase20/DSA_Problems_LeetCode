class Solution {
public:
    string reverseWords(string s) {
        //Tokenizing the string
        stringstream ss(s);
        string token;
        stack<string>stk;
        string solution;

        while(ss >> token){
            stk.push(token);
        }

        while(!stk.empty()){
            string val=stk.top();
            solution=solution+val;
            stk.pop();
            if(stk.empty()){
                break;
            }
            solution=solution+" ";
        }
        return solution;
    }
};
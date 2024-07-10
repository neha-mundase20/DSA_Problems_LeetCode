class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<int>st;

        for(int i=0;i<logs.size();i++){
            if(logs[i]=="../" && st.empty()!=true){
                st.pop();
            }
            else if(logs[i]!="../" && logs[i]!="./"){
                string temp=logs[i];
                st.push(temp[0]);
            }
        }

        return st.size();   
        /*The number of folders left in stack will be the number of operations  required to return to the main folder.*/
    }
};
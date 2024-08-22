class Solution {
public:
    int findComplement(int num) {
        stack<int>stk;
        vector<int>b;

        while(num>0){
            stk.push(num%2);
            num=num/2;
        }

        while(!stk.empty()){
            b.push_back(stk.top());
            stk.pop();
        }

        for(int i=0;i<b.size();i++){
            if(b[i]==0){
                b[i]=1;
            }
            else{
                b[i]=0;
            }
        }

        int j=0,solution=0;
        for(int i=b.size()-1;i>=0;i--){
            solution=solution+(b[i]*pow(2,j++));
        }

        return solution;
    }
};
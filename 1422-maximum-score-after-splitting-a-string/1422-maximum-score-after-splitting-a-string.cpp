class Solution {
public:
    int maxScore(string s) {
        stack<char>stk;
        int left=0,right=0,score=0,countZeroes=0;

        for(auto it:s){
            if(it=='0'){
                countZeroes++;
            }
            stk.push(it);
        }

        left=countZeroes;

        while(!stk.empty()){
            char x = stk.top();
            stk.pop();
            if(stk.empty()){
                break;
            }
            if(x=='1'){
                right++;
            }
            else{
                left=left-1;
            }

            score=max(score,left+right);
        }
        return score;
    }
};
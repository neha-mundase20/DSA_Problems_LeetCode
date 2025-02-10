class Solution {
public:
    string clearDigits(string s) {
        string result;

        for(int i=0;i<s.length();i++){
            if(isdigit(s[i])){
                int j=i-1;
                if(s[j]=='-'){
                    while(s[j]=='-'){
                        j--;
                    }
                }

                if(isalpha(s[j])){
                    s[j]='-';
                }

                s[i]='-';
            }
        }

        for(auto it:s){
            if(it!='-'){
                result.push_back(it);
            }
        }
        return result;
    }
};
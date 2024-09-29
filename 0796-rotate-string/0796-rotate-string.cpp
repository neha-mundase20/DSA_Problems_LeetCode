class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length()!=goal.length()){
            return false;
        }

        //Try every possible rotation on string s
        for(int i=0;i<s.length();i++){
            string rotated;
            for(int j=0;j<s.length();j++){
                rotated.push_back(s[(i+j)%s.length()]);
            }
            if(goal==rotated){
                return true;
            }
        }
        return false;
    }
};
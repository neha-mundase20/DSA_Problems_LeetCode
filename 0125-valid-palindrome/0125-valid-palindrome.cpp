class Solution {
public:
    bool isPalindrome(string s) {
        string solution;
        
        for(int i=0;s[i]!='\0';i++){
            if(isalnum(s[i])){
                solution.push_back(tolower(s[i]));
            }
        }
        
        int left=0,right=solution.length()-1;
        while(left<right){
            if(solution[left]!=solution[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};
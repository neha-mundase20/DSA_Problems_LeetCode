class Solution {
public:
    bool isPalindrome(int x) {
        string str = to_string(x);
        int flag=1;
                    //coz '\0' is added to the end of the string
        for(int i=0,j=str.size()-1;str[i]!='\0',i<=j;i++,j--){
            if(str[i]!=str[j]){
                flag=0;
                break;
            }
        }
        if(flag==0){
            return false;
        }
        else{
            return true;
        }
    }
};
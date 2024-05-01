class Solution {
public:
    string reversePrefix(string word, char ch) {
        for(int i=0;word[i]!='\0';i++){
            if(word[i]==ch){
                for(int j=0,k=i;j<k;j++,k--){
                    char temp=word[j];
                    word[j]=word[k];
                    word[k]=temp;
                }
                break;
            }
        }
        return word;
    }
};
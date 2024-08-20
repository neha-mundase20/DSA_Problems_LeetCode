class Solution {
public:
    string reverseVowels(string s) {
        int i=0,j=s.length()-1;

        while(i<j){
            char a1=tolower(s[i]),a2=tolower(s[j]);
            if(a1!='a' && a1!='e' && a1!='i' && a1!='o' && a1!='u'){
                i++;
            }

            if(a2!='a' && a2!='e' && a2!='i' && a2!='o' && a2!='u'){
                j--;
            }

            if((a1=='a' || a1=='e' || a1=='i' || a1=='o' || a1=='u')
            && (a2=='a' || a2=='e' || a2=='i' || a2=='o' || a2=='u')){
                swap(s[i],s[j]);
                i++;
                j--;
            }
        }
        return s;
    }
};
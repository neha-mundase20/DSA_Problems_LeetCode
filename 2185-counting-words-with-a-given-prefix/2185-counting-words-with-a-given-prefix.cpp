class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count=0;
        string temp;

        for(int i=0;i<words.size();i++){
            temp=words[i].substr(0,pref.size());
            if(temp==pref){
                count++;
            }
        }
        return count;
    }
};
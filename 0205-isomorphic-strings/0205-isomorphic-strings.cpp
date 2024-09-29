class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char>sTot;
        unordered_map<char,char>tTos;

        for(int i=0;i<s.length();i++){
            char schar=s[i];
            char tchar=t[i];

            if(sTot.find(schar)==sTot.end()){
                sTot[schar]=tchar;
            }
            else{
                if(sTot[schar]!=tchar){
                    return false;
                }
            }

            if(tTos.find(tchar)==tTos.end()){
                tTos[tchar]=schar;
            }
            else{
                if(tTos[tchar]!=schar){
                    return false;
                }
            }
        }
        return true;
    }
};
class Solution {
public:
    bool checkString(string s) {
        map<char,int>mp;
        
        for(auto it:s){
            mp[it]++;
        }
        
        if(mp.find('a')==mp.end()){ //String consists of only 'b'
            return true;
        }
        else if(mp.find('b')==mp.end()){    //String consists of only 'a'
            return true;
        }
        else{
           int countA=mp['a'];
        
            for(int i=0;i<countA;i++){  //If 'b' occurs in set of 'a'
                if(s[i]=='b'){
                return false;
            }
        }
        
            for(int i=countA;s[i]!='\0';i++){
                if(s[i]=='a'){  //If 'a' occurs in set of 'b'
                    return false;
                }
            } 
        }
        return true;
    }
};
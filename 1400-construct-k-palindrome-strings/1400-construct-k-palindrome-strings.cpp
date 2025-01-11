class Solution {
public:
    bool canConstruct(string s, int k) {
        if(k>s.size()){ 
            //can't prepare 'k' palindromes coz insufficient characters
            return false;
        }
        map<char,int>mp;
        for(auto c:s){
            mp[c]++;
        }

        //Calculate count of odd frequency characters
        int count=0;
        for(auto it:mp){
            if(it.second%2!=0){
                count++;
            }
        }

        // Calculate how many characters have an odd frequency. Each such  
        // character will require its own palindrome.Condition: For the 
        // string to be divided into k palindromes:The number of 
        // odd-frequency characters must not exceed k.
        
        if(count>k){
            return false;
        }

        return true;
    }
};
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char,int>mp;
        
        for(char c:magazine){
            mp[c]++;
        }
        
        for(char ch:ransomNote){    //Iterate over ransomNote to check its occurence in                                            //magazine
            if(mp.find(ch)==mp.end() || mp[ch]==0){
                //The element isn't found or the element count is exhausted
                return false; 
            }
            mp[ch]--;   //If element is found, then reduce its occurence count
        }
        return true;
    }
};
class Solution {
public:
    int findMaxK(vector<int>& nums) {
        map<int,int>mp;
        int maxVal=0;
        bool flag=false;
        
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        
        for(auto it:mp){
            if((it.first>maxVal) && mp.find(-(it.first))!=mp.end()){    //find(element)
                //returns an iterator pointing to the element if found, else points to end                   //of the map
                maxVal=it.first;
                flag=true;
            }
        }
        
        if(flag==true){
            return maxVal;
        }
        else{
            return -1;
        }
    }
};
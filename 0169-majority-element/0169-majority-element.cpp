class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int>mp;
        int n=nums.size();
        int val=0;
        
        for(int i=0;i<n;i++){   //store frequencies of elements in 'nums' vector
            mp[nums[i]]++;
        }
        
        for(auto it:mp){
            if(it.second > (n/2)){  //when the frequency exceeds n/2, return that value
                val=it.first;
                break;
            }
        }
        return val;
    }
};
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        unordered_map<int,int>mp;
        int count=0,i=1;
        for(auto it:arr){
            mp[it]++;
        }

        while(count<k){
            if(mp.find(i)==mp.end()){
                count++;
            }
            
            if(count==k){
                break;
            }
            i++;
        }
        return i;
    }
};
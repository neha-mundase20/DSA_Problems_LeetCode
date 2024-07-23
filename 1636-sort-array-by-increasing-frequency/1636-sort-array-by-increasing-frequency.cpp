class Solution {
public:

    struct hashmap{
        int val;
        int freq;
    };

    static bool sortAscFreq(const struct hashmap&a,const struct hashmap&b){
        if(a.freq==b.freq){
            return a.val>b.val;
        }
        return a.freq<b.freq;
    }

    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int>mp;
        vector<int>solution;

        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }

        vector<hashmap>h(mp.size());
        for(auto it:mp){
            h.push_back({it.first,it.second});
        }

        sort(h.begin(),h.end(),sortAscFreq);

        for(auto it:h){
            for(int i=0;i<it.freq;i++){
                solution.push_back(it.val);
            }
        }

        return solution;
    }
};
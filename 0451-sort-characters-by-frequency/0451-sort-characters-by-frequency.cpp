class Solution {
public:

    struct item{
        char s; //character
        int f;  //frequency
    };

    static bool sortItems(struct item&a, struct item&b){
        return a.f>b.f; //sorting in descending order
    }

    string frequencySort(string s) {
        unordered_map<char,int>mp;
        for(auto it:s){
            mp[it]++;
        }

        vector<item>v;

        for(auto it:mp){
            v.push_back({it.first,it.second});
        }

        sort(v.begin(),v.end(),sortItems);

        string result;
        for(auto it:v){
            for(int i=0;i<it.f;i++){
                result.push_back(it.s);
            }
        }

        return result;
    }
};
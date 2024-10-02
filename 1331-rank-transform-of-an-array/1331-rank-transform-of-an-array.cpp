class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        set<int>st;

        for(auto it:arr){
            st.insert(it);  //Find out unique elements
        }

        map<int,int>mp;
        int count=1;

        for(auto it:st){
            mp[it]=count;
            count++;
        }

        for(int i=0;i<arr.size();i++){
            arr[i]=mp[arr[i]];
        }

        return arr;
    }
};